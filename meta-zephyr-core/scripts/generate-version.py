#!/usr/bin/env python3

import json
import pathlib
import re
import sys
import urllib.parse
import urllib.request

# These non-standard modules must be installed on the host
import jinja2
import west.manifest

# This script takes one argument - the Zephyr version in the form x.y.z
version = sys.argv[1]
if not re.match(r'\d+.\d+.\d+', version):
    raise ValueError("Please provide a valid Zephyr version")

# Convert the version (x.y.z) into the Git commit SHA using the Github API
# This is a two-step process - first obtain the tag SHA
ref_url = f'https://api.github.com/repos/zephyrproject-rtos/zephyr/git/refs/tags/v{version}'
with urllib.request.urlopen(ref_url) as f:
    ref_data = json.load(f)
    ref_sha = ref_data['object']['sha']

# Secondly, obtain the commit SHA of the tag SHA
tag_url = f'https://api.github.com/repos/zephyrproject-rtos/zephyr/git/tags/{ref_sha}'
with urllib.request.urlopen(tag_url) as f:
    tag_data = json.load(f)
    tag_sha = tag_data['object']['sha']

# Obtain the West manifest and decode using west as a library
manifest_url = f'https://raw.githubusercontent.com/zephyrproject-rtos/zephyr/v{version}/west.yml'
with urllib.request.urlopen(manifest_url) as f:
    source_data = f.read().decode()
    manifest = west.manifest.Manifest(source_data=source_data,
        import_flags=west.manifest.ImportFlag.IGNORE)
    projects = manifest.get_projects([])

# projects contains a 'manifest' project for 'self' which we don't want to use
projects = list(filter(lambda project: project.name != 'manifest', projects))
template_params = dict(version=version, tag_sha=tag_sha, projects=projects)

def git_url_to_bitbake(url):
    """
    A template helper function which converts an URL for a Git repository into
    a Bitbake-style URL with a 'protocol' suffix
    """
    parts = urllib.parse.urlparse(url)
    original_sceme = parts.scheme
    parts = parts._replace(scheme='git')
    return parts.geturl() + ';protocol=' + original_sceme

def bitbake_var(name):
    """
    Returns a string suitable for use in a Bitbake variable name
    """
    return name.upper().replace('-', '_')

# Set up the Jinja environment
template_dir = pathlib.Path(__file__).parent
env = jinja2.Environment(loader=jinja2.FileSystemLoader(template_dir))
env.filters['git_url_to_bitbake'] = git_url_to_bitbake
env.filters['bitbake_var'] = bitbake_var
template = env.get_template('zephyr-kernel-src.inc.jinja')

# Output directly to the zephyr-kernel directory
dest_path = pathlib.Path(__file__).parents[1] / 'recipes-kernel' /\
    'zephyr-kernel' / f'zephyr-kernel-src-{version}.inc'

# Generate the Bitbake include file
with open(dest_path, 'w') as f:
    f.write(template.render(**template_params))

ZEPHYRTESTS_remove = "fifo fp_sharing lifo mbox mem_heap mem_pool \
    mem_protect mem_slab msgq mutex pipe profiling sched semaphore \
    stack threads tickless timer workq"


# Exclude tests which does not build for various reasons
ZEPHYRTESTS_remove = "gen_isr_table spinlock smp mp"


# test_context will fail because QEMU for ARM does not emulate CortexM3 BASEPRI register
#ZEPHYRTESTS_remove_arm += ""

# test_critical never finishes in an unpatched QEMU either
#ZEPHYRTESTS_remove_arm += ""

#Remove ARM specific tests
#ZEPHYRTESTS_remove_x86 += ""

#Remove tests not intended for Nios2
#ZEPHYRTESTS_remove_nios2 += ""

# List of all available kernel tests
ZEPHYRTESTS = " \
    boot_page_table \
    common \
    context \
    critical \
    device \
    early_sleep \
    fatal \
    fifo \
    fp_sharing \
    gen_isr_table \
    interrupt \
    lifo \
    mbox \
    mem_heap \
    mem_pool \
    mem_protect \
    mem_slab \
    mp \
    msgq \
    mutex \
    obj_tracing \
    pending \
    pipe \
    poll \
    profiling \
    queue \
    sched \
    semaphore \
    sleep \
    smp \
    spinlock \
    stack \
    threads \
    tickless \
    timer \
    workq \
    xip \
    "


ZEPHYRTESTS_remove = "test_static_idt test_fifo test_fp_sharing \
    test_sema test_stackprot test_obj_tracing test_stack \
    test_tickless test_timer"

#TBD
ZEPHYRTESTS_remove_arm += ""

#Remove ARM specific tests
ZEPHYRTESTS_remove_x86 += "test_context test_arm_irq_vector_table"

# List of all available tests
ZEPHYRTESTS = " \
    test_arm_irq_vector_table  \
    test_context \
    test_critical \
    test_early_sleep \
    test_errno \
    test_events \
    test_fifo \
    test_fifo_priv \
    test_fp_sharing \
    test_irq_offload \
    test_libs \
    test_lifo \
    test_mail \
    test_mail_priv \
    test_map \
    test_map_priv \
    test_mem_safe \
    test_mutex \
    test_nano_work \
    test_obj_tracing \
    test_pend \
    test_pipe \
    test_pipe_priv \
    test_pool \
    test_sema \
    test_sema_priv \
    test_sleep \
    test_stack \
    test_stackprot \
    test_static_idt \
    test_task \
    test_task_priv \
    test_tickless \
    test_timer \
    "

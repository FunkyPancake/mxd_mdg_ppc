cmake_minimum_required(VERSION 3.24)

project(startup LANGUAGES ASM C CXX)

target_sources(${TARGET_NAME}
        PRIVATE
        flashrchw.c
        INTCISRVEC_table.c
        MPC56xx__Interrupt_Init.c
        Vector.c
        startup.S
        intc_sw_handlers.S
)
set_property(SOURCE startup.S APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")
set_property(SOURCE intc_sw_handlers.S APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")


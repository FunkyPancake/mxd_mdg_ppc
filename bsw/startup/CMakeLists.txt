cmake_minimum_required(VERSION 3.24)

project(startup LANGUAGES ASM C CXX)

add_library(startup
        flashrchw.c
        INTCISRVEC_table.c
        MPC56xx__Interrupt_Init.c
        Vector.c
        startup.S
        intc_sw_handlers.S
)
set_property(SOURCE startup.S APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")
set_property(SOURCE intc_sw_handlers.S APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")

target_include_directories(startup PRIVATE
        ${CMAKE_SOURCE_DIR}/bsw/Project_Headers
)
target_compile_options(startup PRIVATE
        -c
        -g3
        -mcpu=e200z4
        #        -specs=nano.specs
        #        -specs=nosys.specs
        -mbig
        -mvle
        -mregnames
)

target_compile_definitions(startup
        PRIVATE
        MPC564xA
        E200Z4
        I_CACHE
        DISABLE_SWT
        SPE_ENABLE
        START_FROM_FLASH
)
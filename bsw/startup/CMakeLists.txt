cmake_minimum_required(VERSION 3.24)

project(startup LANGUAGES ASM C CXX)

add_library(startup
        startup.S)

target_include_directories(startup PRIVATE
        ${CMAKE_SOURCE_DIR}/bsw/Project_Headers
)

target_compile_options(startup PRIVATE
        -c
        -x assembler-with-cpp
        -g3
        -mcpu=e200z4
#        -specs=nano.specs
#        -specs=nosys.specs
        -mbig
        -mvle
        -mregnames
)

target_compile_definitions(${TARGET_NAME}
        PRIVATE
        MPC564xA
        E200Z4
        I_CACHE
        DISABLE_SWT
        SPE_ENABLE
        START_FROM_FLASH
)
cmake_minimum_required(VERSION 3.24)

project(os LANGUAGES ASM CXX C)
set(CMAKE_CXX_STANDARD 17)

target_sources(${TARGET_NAME}
        PRIVATE
        FreeRTOS/croutine.c
        FreeRTOS/event_groups.c
        FreeRTOS/list.c
        FreeRTOS/queue.c
        FreeRTOS/stream_buffer.c
        FreeRTOS/tasks.c
        FreeRTOS/timers.c
        FreeRTOS/portable/Common/mpu_wrappers.c
        FreeRTOS/portable/GCC/PowerPC/port.c
        FreeRTOS/portable/GCC/PowerPC/portasm.s
        FreeRTOS/portable/GCC/PowerPC/porttimer.c
        FreeRTOS/portable/MemMang/heap_4.c
)
target_include_directories(${TARGET_NAME}
        PUBLIC
        .
        FreeRTOS/include
        FreeRTOS/portable/GCC/PowerPC
        ${CMAKE_SOURCE_DIR}/nxp/platform/devices
        ${CMAKE_SOURCE_DIR}/nxp/platform/drivers/inc
)
set_property(SOURCE FreeRTOS/portable/GCC/PowerPC/portasm.s APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp" "-mregnames")

cmake_minimum_required(VERSION 3.24)


project(nxp LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 17)

add_library(nxp
        rtos/FreeRTOS/croutine.c
        rtos/FreeRTOS/event_groups.c
        rtos/FreeRTOS/list.c
        rtos/FreeRTOS/queue.c
        rtos/FreeRTOS/stream_buffer.c
        rtos/FreeRTOS/tasks.c
        rtos/FreeRTOS/timers.c
        rtos/FreeRTOS/portable/Common/mpu_wrappers.c
        rtos/FreeRTOS/portable/GCC/PowerPC/port.c
        rtos/FreeRTOS/portable/GCC/PowerPC/portasm.S
        rtos/FreeRTOS/portable/GCC/PowerPC/porttimer.c
        rtos/FreeRTOS/portable/MemMang/heap_4.c

        rtos/osif/osif_freertos.c

        platform/drivers/src/interrupt/interrupt_manager_MPC57xx.c
        platform/drivers/src/adc_sar/adc_sar_driver.c
        platform/drivers/src/bctu/bctu_driver.c
        platform/drivers/src/clock/MPC57xx/clock_MPC57xx.c


        middleware/eee/source/eee_common.c
        middleware/eee/source/eee_driver.c


)

target_include_directories(nxp
        PUBLIC
        rtos
        rtos/FreeRTOS/include
        rtos/FreeRTOS/portable/GCC/PowerPC
        rtos/osif


        platform/devices
        platform/drivers/inc

        middleware/eee/include

)

set_property(SOURCE FreeRTOS/portable/GCC/PowerPC/portasm.S APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")

cmake_minimum_required(VERSION 3.24)

set(TARGET_NAME mdg)
set(ENGINE_TYPE SPARK)
project(${TARGET_NAME} LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

file(WRITE null.cpp "")

add_executable(${TARGET_NAME}
        null.cpp
        bsw/main.cpp
)
target_include_directories(${TARGET_NAME}
        PUBLIC
        bsw/Project_Headers
)

target_compile_options(${TARGET_NAME} PRIVATE
        -O0 -mcpu=e200z4 -Wall -mbig -mvle -mregnames
        #        -specs=nano.specs
        #        -specs=nosys.specs
        -mhard-float
        -Wl,-print-memory-usage
        -T ${CMAKE_SOURCE_DIR}/linker/56xx_flash.ld
        -Wl,-Map,"freertos_mpc5746r.map"
        -Xlinker
        --gc-sections
        -mcpu=e200z4
#        -x assembler-with-cpp
        #        -specs=ewl_c9x.specs
        -mhard-float
)
#        -O0 -fno-common -g3 -Wall -c -ffunction-sections -fno-rtti -fdata-sections -ffreestanding
#        -fno-builtin -fno-exceptions -fmerge-constants -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
#        -mthumb -fstack-usage -specs=nano.specs)
#
target_compile_definitions(${TARGET_NAME}
        PRIVATE
        MPC564xA
        E200Z4
        I_CACHE
        DISABLE_SWT
        SPE_ENABLE
        START_FROM_FLASH
        #        FSL_RTOS_FREE_RTOS
        #        SDK_OS_FREE_RTOS
        #        SDK_DEBUGCONSOLE=1
        #        __MCUXPRESSO
        #        __USE_CMSIS
        #        NDEBUG
        #        __NEWLIB__
)

add_subdirectory(bsw)
add_subdirectory(mxd_mdg_ecsw)

#target_link_options(${TARGET_NAME} PRIVATE -Wl,-print-memory-usage,--sort-section=alignment,--gc-sections,--cref,-M=${TARGET_NAME}.map -nostdlib -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb  -T Ke16F256.ld)
target_link_options(${TARGET_NAME} PRIVATE  -Wl,-print-memory-usage,--sort-section=alignment,--gc-sections,--cref,-M=${TARGET_NAME}.map -T ${CMAKE_SOURCE_DIR}/linker/56xx_flash.ld)
set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME}.elf)
target_link_libraries(${TARGET_NAME} PRIVATE startup)

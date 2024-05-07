cmake_minimum_required(VERSION 3.24)

set(TARGET_NAME mdg)
set(ENGINE_TYPE SPARK)
project(${TARGET_NAME} LANGUAGES C CXX)
file(WRITE null.cpp "")

add_executable(${TARGET_NAME}
null.cpp)
#TODO change to erika


#target_compile_options(${TARGET_NAME} PRIVATE
#        -O0 -fno-common -g3 -Wall -c -ffunction-sections -fno-rtti -fdata-sections -ffreestanding
#        -fno-builtin -fno-exceptions -fmerge-constants -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
#        -mthumb -fstack-usage -specs=nano.specs)
#
#target_compile_definitions(${TARGET_NAME}
#        PRIVATE
#        CPU_MKE16F256VLH16
#        CPU_MKE16F256VLH16_cm4
#        FSL_RTOS_FREE_RTOS
#        SDK_OS_FREE_RTOS
#        SDK_DEBUGCONSOLE=1
#        __MCUXPRESSO
#        __USE_CMSIS
#        NDEBUG
#        __NEWLIB__
#)
target_link_directories(${TARGET_NAME} PRIVATE linker)
#target_link_options(${TARGET_NAME} PRIVATE -Wl,-print-memory-usage,--sort-section=alignment,--gc-sections,--cref,-M=${TARGET_NAME}.map -nostdlib -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb  -T Ke16F256.ld)

set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME}.elf)

add_subdirectory(bsw)
add_subdirectory(mxd_mdg_ecsw)
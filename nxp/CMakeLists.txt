cmake_minimum_required(VERSION 3.24)


project(nxp)

if(DEFINED(FREERTOS))
    add_subdirectory(rtos)
endif ()
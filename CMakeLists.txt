cmake_minimum_required(VERSION 3.24)

set(TARGET_NAME mdg)

write("" null.cpp)
target_sources(${TARGET_NAME}
PRIVATE
null.cpp)
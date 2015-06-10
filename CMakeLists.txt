# Global settings

cmake_minimum_required (VERSION 2.8.11)
project (Config)


set(CONFIG_3RD_PARTY_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/3rdParty/)
set(CONFIG_LIB_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "-ggdb -std=c++11")
# subdirectories

add_subdirectory(src/cpp)


# Global settings

cmake_minimum_required (VERSION 2.8.11)
project (Config)


set(CONFIG_3RD_PARTY_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/3rdParty/)
set(CONFIG_LIB_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/)

# subdirectories

add_subdirectory(src)


set(LIB_SRCS 
    RangeValidator.cpp
    DiscreteNumericValidator.cpp
    AnyPlatformValidator.cpp
	Common.cpp)

add_library(config ${LIB_SRCS})
target_include_directories(config PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


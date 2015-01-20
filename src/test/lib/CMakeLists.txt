#gmock include dir
include_directories(${CONFIG_3RD_PARTY_SOURCE}/gmock-1.7.0/include/)
include_directories(${CONFIG_3RD_PARTY_SOURCE}/gmock-1.7.0/gtest/include)
include_directories(.)
include_directories(${CONFIG_LIB_SOURCE}/include)

set(TEST_SRC
		RangeValidatorTest.cpp)

add_executable(config_unit_tests ${TEST_SRC})
target_link_libraries(config_unit_tests config)
target_link_libraries(config_unit_tests gmock)
target_link_libraries(config_unit_tests gmock_main)

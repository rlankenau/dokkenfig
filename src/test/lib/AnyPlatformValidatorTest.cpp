#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Types.h"
#include "AnyPlatformValidator.h"
#include "mock/MockOption.h"

using ::testing::Return;
using ::testing::_;
using ::testing::DoAll;
using ::testing::SetArgPointee;

TEST(AnyPlatformValidator, ConvenienceMethod)
{
	MockOption op;
	etw::PlatformValidatorInterface *v = etw::AnyPlatform();
	ASSERT_EQ(etw::RetVal::Success, v->validateOption(std::string("anything"), (etw::OptionInterface *)&op));
	delete v;
}

TEST(AnyPlatformValidator, EmptyString)
{
	MockOption op;
	etw::AnyPlatformValidator v;
	ASSERT_EQ(etw::RetVal::Success, v.validateOption(std::string(), (etw::OptionInterface *)&op));
}

TEST(AnyPlatformValidator, ValidString)
{
	MockOption op;
	etw::AnyPlatformValidator v;
	ASSERT_EQ(etw::RetVal::Success, v.validateOption(std::string("anything"), (etw::OptionInterface *)&op));
}


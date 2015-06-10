#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Types.h"
#include "validators/NumericValidator.h"
#include "mock/MockOption.h"

using ::testing::Return;
using ::testing::_;
using ::testing::DoAll;
using ::testing::SetArgPointee;

TEST(ValidNumericValidator, ConvenienceMethod)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(1000), Return(etw::RetVal::Success)));
	etw::ValidatorInterface *v = etw::ValidNumeric(1000);
	ASSERT_EQ(etw::RetVal::Success, v->validateOption((etw::OptionInterface *)&op));
	delete v;
}

TEST(ValidNumericValidator, LessThanSpecifiedValue)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(-1), Return(etw::RetVal::Success)));
	etw::ValidNumericValidator r(1000);
	ASSERT_EQ(etw::RetVal::Failure, r.validateOption((etw::OptionInterface *)&op));
}

TEST(ValidNumericValidator, SpecifiedValue)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(1000), Return(etw::RetVal::Success)));
	etw::ValidNumericValidator r(1000);
	ASSERT_EQ(etw::RetVal::Success, r.validateOption((etw::OptionInterface *)&op));
}


TEST(ValidNumericValidator, GreaterThanSpecifiedValue)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(10000), Return(etw::RetVal::Success)));
	etw::ValidNumericValidator r(1000);
	ASSERT_EQ(etw::RetVal::Failure, r.validateOption((etw::OptionInterface *)&op));
}

TEST(InvalidNumericValidator, ConvenienceMethod)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(1000), Return(etw::RetVal::Success)));
	etw::ValidatorInterface *v = etw::InvalidNumeric(1000);
	ASSERT_EQ(etw::RetVal::Failure, v->validateOption((etw::OptionInterface *)&op));
	delete v;
}

TEST(InvalidNumericValidator, LessThanSpecifiedValue)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(-1), Return(etw::RetVal::Success)));
	etw::InvalidNumericValidator r(1000);
	ASSERT_EQ(etw::RetVal::Success, r.validateOption((etw::OptionInterface *)&op));
}

TEST(InvalidNumericValidator, SpecifiedValue)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(1000), Return(etw::RetVal::Success)));
	etw::InvalidNumericValidator r(1000);
	ASSERT_EQ(etw::RetVal::Failure, r.validateOption((etw::OptionInterface *)&op));
}


TEST(InvalidNumericValidator, GreaterThanSpecifiedValue)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(10000), Return(etw::RetVal::Success)));
	etw::InvalidNumericValidator r(1000);
	ASSERT_EQ(etw::RetVal::Success, r.validateOption((etw::OptionInterface *)&op));
}

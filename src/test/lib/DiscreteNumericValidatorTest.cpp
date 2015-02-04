#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Types.h"
#include "DiscreteNumericValidator.h"
#include "mock/MockOption.h"

using ::testing::Return;
using ::testing::_;
using ::testing::DoAll;
using ::testing::SetArgPointee;

TEST(DiscreteNumericValidator, ConvenienceMethod)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(1000), Return(etw::RetVal::Success)));
	etw::ValidatorInterface *v = etw::DiscreteNumeric(1000);
	ASSERT_EQ(etw::RetVal::Success, v->validateOption((etw::OptionInterface *)&op));
	delete v;
}

TEST(DiscreteNumericValidator, LessThanValid)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(-1), Return(etw::RetVal::Success)));
	etw::DiscreteNumericValidator r(1000);
	ASSERT_EQ(etw::RetVal::Failure, r.validateOption((etw::OptionInterface *)&op));
}

TEST(DiscreteNumericValidator, Valid)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(1000), Return(etw::RetVal::Success)));
	etw::DiscreteNumericValidator r(1000);
	ASSERT_EQ(etw::RetVal::Success, r.validateOption((etw::OptionInterface *)&op));
}


TEST(DiscreteNumericValidator, GreaterThanValid)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(10000), Return(etw::RetVal::Success)));
	etw::DiscreteNumericValidator r(1000);
	ASSERT_EQ(etw::RetVal::Failure, r.validateOption((etw::OptionInterface *)&op));
}


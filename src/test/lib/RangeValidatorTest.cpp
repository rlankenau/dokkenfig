#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Types.h"
#include "RangeValidator.h"
#include "mock/MockOption.h"

using ::testing::Return;
using ::testing::_;
using ::testing::DoAll;
using ::testing::SetArgPointee;

TEST(RangeValidator, LessThanRange)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(-1), Return(etw::RetVal::Success)));
	etw::RangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Failure, r.validateOption((etw::OptionInterface *)&op));
}

TEST(RangeValidator, RangeMin)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(0), Return(etw::RetVal::Success)));
	etw::RangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Success, r.validateOption((etw::OptionInterface *)&op));
}

TEST(RangeValidator, InRange)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(50), Return(etw::RetVal::Success)));
	etw::RangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Success, r.validateOption((etw::OptionInterface *)&op));
}

TEST(RangeValidator, RangeMax)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(100), Return(etw::RetVal::Success)));
	etw::RangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Success, r.validateOption((etw::OptionInterface *)&op));
}

TEST(RangeValidator, GreaterThanRange)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(200), Return(etw::RetVal::Success)));
	etw::RangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Failure, r.validateOption((etw::OptionInterface *)&op));
}

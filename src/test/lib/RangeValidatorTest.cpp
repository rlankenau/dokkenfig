#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Types.h"
#include "validators/RangeValidator.h"
#include "mock/MockOption.h"

using ::testing::Return;
using ::testing::_;
using ::testing::DoAll;
using ::testing::SetArgPointee;

TEST(ValidRangeValidator, ConvenienceMethod)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(1000), Return(etw::RetVal::Success)));
	etw::ValidatorInterface *v = etw::ValidRange(0,1001);
	ASSERT_EQ(etw::RetVal::Success, v->validateOption((etw::OptionInterface *)&op));
	delete v;
}

TEST(ValidRangeValidator, LessThanRange)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(-1), Return(etw::RetVal::Success)));
	etw::ValidRangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Failure, r.validateOption((etw::OptionInterface *)&op));
}

TEST(ValidRangeValidator, RangeMin)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(0), Return(etw::RetVal::Success)));
	etw::ValidRangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Success, r.validateOption((etw::OptionInterface *)&op));
}

TEST(ValidRangeValidator, InRange)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(50), Return(etw::RetVal::Success)));
	etw::ValidRangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Success, r.validateOption((etw::OptionInterface *)&op));
}

TEST(ValidRangeValidator, RangeMax)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(100), Return(etw::RetVal::Success)));
	etw::ValidRangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Success, r.validateOption((etw::OptionInterface *)&op));
}

TEST(ValidRangeValidator, GreaterThanRange)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(200), Return(etw::RetVal::Success)));
	etw::ValidRangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Failure, r.validateOption((etw::OptionInterface *)&op));
}

TEST(InvalidRangeValidator, ConvenienceMethod)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(1000), Return(etw::RetVal::Success)));
	etw::ValidatorInterface *v = etw::InvalidRange(0,1001);
	ASSERT_EQ(etw::RetVal::Failure, v->validateOption((etw::OptionInterface *)&op));
	delete v;
}

TEST(InvalidRangeValidator, LessThanRange)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(-1), Return(etw::RetVal::Success)));
	etw::InvalidRangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Success, r.validateOption((etw::OptionInterface *)&op));
}

TEST(InvalidRangeValidator, RangeMin)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(0), Return(etw::RetVal::Success)));
	etw::InvalidRangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Failure, r.validateOption((etw::OptionInterface *)&op));
}

TEST(InvalidRangeValidator, InRange)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(50), Return(etw::RetVal::Success)));
	etw::InvalidRangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Failure, r.validateOption((etw::OptionInterface *)&op));
}

TEST(InvalidRangeValidator, RangeMax)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(100), Return(etw::RetVal::Success)));
	etw::InvalidRangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Failure, r.validateOption((etw::OptionInterface *)&op));
}

TEST(InvalidRangeValidator, GreaterThanRange)
{
	MockOption op;
	EXPECT_CALL(op, getNumericValue(_)).WillOnce(DoAll(SetArgPointee<0>(200), Return(etw::RetVal::Success)));
	etw::InvalidRangeValidator r(0,100);
	ASSERT_EQ(etw::RetVal::Success, r.validateOption((etw::OptionInterface *)&op));
}

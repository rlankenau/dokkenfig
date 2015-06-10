#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Types.h"
#include "expressions/BasicExpressions.h"
#include "mock/MockConfiguration.h"
#include "mock/MockOption.h"

using ::testing::Return;
using ::testing::_;
using ::testing::DoAll;
using ::testing::SetArgPointee;

TEST(ValueOf, SimpleTest)
{
	std::string op_name = "MyTestOption";
	etw::ValueOf vo(op_name);
	MockConfiguration cfg;
	MockOption op;
	etw::OptionInterface *op_ptr;
	EXPECT_CALL(cfg, getOption(op_name, &op_ptr)).Times(1).WillOnce(DoAll(SetArgPointee<1>(&op), Return(etw::RetVal::Success)));

	ASSERT_EQ(etw::RetVal::Success, vo.getResult(&cfg, &op_ptr));
	ASSERT_EQ(&op, op_ptr);
}

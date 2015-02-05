#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Types.h"
#include "consistency_validators/NoConsistencyCheck.h"
#include "mock/MockConfiguration.h"
#include "mock/MockOption.h"

using ::testing::Return;
using ::testing::_;

TEST(NoConsistencyCheck, SimpleTest)
{
	etw::NoConsistencyCheck chk;
	MockConfiguration cfg;
	MockOption op;

	ASSERT_EQ(etw::RetVal::Success, chk.validateOption(&cfg, &op));
}

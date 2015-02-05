#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Types.h"
#include "platform_validators/PlatformRestrictionValidator.h"
#include "mock/MockOption.h"
#include "mock/MockValidator.h"

using ::testing::Return;
using ::testing::_;
using ::testing::DoAll;
using ::testing::SetArgPointee;

TEST(PlatformRestrictionValidator, ConvenienceMethod)
{
	MockOption op;
	MockValidator v;
	etw::PlatformValidatorInterface *pv = etw::PlatformRestriction(std::string("Linux"), &v);
	ON_CALL(v, validateOption(_)).WillByDefault(Return(etw::RetVal::Failure));
	
	ASSERT_EQ(etw::RetVal::Success, pv->validateOption(std::string("Not Linux"), (etw::OptionInterface *)&op)) << "A non-matching platform should always succeed.";

	delete pv;
}

TEST(PlatformRestrictionValidator, ValidatorFails)
{
	MockOption op;
	MockValidator v;
	etw::PlatformValidatorInterface *pv = etw::PlatformRestriction(std::string("Linux"), &v);
	EXPECT_CALL(v, validateOption(_)).Times(1).WillOnce(Return(etw::RetVal::Failure));
	
	ASSERT_EQ(etw::RetVal::Failure, pv->validateOption(std::string("Linux"), (etw::OptionInterface *)&op)) << "The validator return should be passed through if the platform matches.";

	delete pv;

}

TEST(PlatformRestrictionValidator, ValidatorSucceeds)
{
	MockOption op;
	MockValidator v;
	etw::PlatformValidatorInterface *pv = etw::PlatformRestriction(std::string("Linux"), &v);
	EXPECT_CALL(v, validateOption(_)).Times(1).WillOnce(Return(etw::RetVal::Success));
	
	ASSERT_EQ(etw::RetVal::Success, pv->validateOption(std::string("Linux"), (etw::OptionInterface *)&op)) <<  "The validator return should be passed through if the platform matches.";

	delete pv;

}



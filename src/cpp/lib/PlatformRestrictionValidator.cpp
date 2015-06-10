#include "platform_validators/PlatformRestrictionValidator.h"
#include "ValidatorInterface.h"
#include "OptionInterface.h"
#include "Types.h"
#include <string>

namespace etw {

	PlatformRestrictionValidator::PlatformRestrictionValidator(std::string platform, ValidatorInterface *v)
	{
		this->my_platform = platform;
		this->my_validator = v;
	}

	int PlatformRestrictionValidator::validateOption(std::string platform, OptionInterface *op)
	{
		int rc = RetVal::Success;
		if(this->my_platform.compare(platform) == 0 ){
			rc = this->my_validator->validateOption(op);
		}
		return rc;
	}

	PlatformValidatorInterface *PlatformRestriction(std::string platform, ValidatorInterface *v)
	{
		return (PlatformValidatorInterface *)new PlatformRestrictionValidator(platform, v);
	}
}

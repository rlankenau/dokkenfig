#ifndef ETW_CONFIG_PLATFORM_RESTRICTION_VALIDATOR_H_
#define ETW_CONFIG_PLATFORM_RESTRICTION_VALIDATOR_H_

#include "ValidatorInterface.h"
#include "PlatformValidatorInterface.h"
#include <string>

namespace etw {

class PlatformRestrictionValidator : public PlatformValidatorInterface 
{
public:
	PlatformRestrictionValidator(std::string platform, ValidatorInterface *v);
	int validateOption(std::string platform, OptionInterface *op);
private:
	std::string my_platform;
	ValidatorInterface *my_validator;
};

PlatformValidatorInterface *PlatformRestriction(std::string platform, ValidatorInterface *v);

}

#endif

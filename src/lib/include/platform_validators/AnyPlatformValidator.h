#ifndef ETW_CONFIG_ANY_PLATFORM_VALIDATOR_H_
#define ETW_CONFIG_ANY_PLATFORM_VALIDATOR_H_

#include "PlatformValidatorInterface.h"

namespace etw {

class AnyPlatformValidator : public PlatformValidatorInterface 
{
public:
	AnyPlatformValidator();
	int validateOption(std::string platform, OptionInterface *op);	
};

AnyPlatformValidator *AnyPlatform();

}

#endif

#ifndef ETW_CONFIG_PLATFORM_VALIDATOR_INTERFACE_H_
#define ETW_CONFIG_PLATFORM_VALIDATOR_INTERFACE_H_

#include <string>

namespace etw {

class OptionInterface;

class PlatformValidatorInterface
{
public:
	virtual int validateOption(std::string platform, OptionInterface *op) = 0;
};

}
#endif


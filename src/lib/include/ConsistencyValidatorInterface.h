#ifndef ETW_CONFIG_CONSISTENCY_VALIDATOR_INTERFACE_H_
#define ETW_CONFIG_CONSISTENCY_VALIDATOR_INTERFACE_H_

#include <string>

namespace etw {

class OptionInterface;
class ConfigurationInterface;

class ConsistencyValidatorInterface
{
public:
	virtual int validateOption(ConfigurationInterface *cfg, OptionInterface *op) = 0;
};

}
#endif

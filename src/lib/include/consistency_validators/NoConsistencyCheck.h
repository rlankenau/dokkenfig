#ifndef ETW_CONFIG_NO_CONSISTENCY_CHECK_H_
#define ETW_CONFIG_NO_CONSISTENCY_CHECK_H_

#include "ConsistencyValidatorInterface.h"

namespace etw {

class NoConsistencyCheck : public ConsistencyValidatorInterface
{
public:
	NoConsistencyCheck();
	int validateOption(ConfigurationInterface *cfg, OptionInterface *op);
};

}

#endif

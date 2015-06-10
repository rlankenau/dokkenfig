#ifndef ETW_CONFIG_EXPRESSION_INTERFACE_H_
#define ETW_CONFIG_EXPRESSION_INTERFACE_H_

#include "ConfigurationInterface.h"
#include "OptionInterface.h"

namespace etw {

class ExpressionInterface
{
public:
	int getResult(ConfigurationInterface *cfg, OptionInterface **op);
};

}

#endif

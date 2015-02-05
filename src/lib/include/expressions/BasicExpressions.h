#ifndef ETW_CONFIG_BASIC_EXPRESSIONS_H_
#define ETW_CONFIG_BASIC_EXPRESSIONS_H_

#include "ExpressionInterface.h"
#include "ConfigurationInterface.h"
#include "OptionInterface.h"

namespace etw {

class ValueOf : public ExpressionInterface
{
public:
	ValueOf(std::string key);
	int getResult(ConfigurationInterface *cfg, OptionInterface **op);
private:
	std::string key;
};


}

#endif

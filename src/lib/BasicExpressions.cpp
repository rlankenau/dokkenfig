#include "expressions/BasicExpressions.h"
#include "ConfigurationInterface.h"
#include "OptionInterface.h"
#include "Option.h"
#include <string>

namespace etw {

ValueOf::ValueOf(std::string key)
{
	this->key = key;
}

int ValueOf::getResult(ConfigurationInterface *cfg, OptionInterface **op)
{
	return cfg->getOption(this->key, op);
}

}

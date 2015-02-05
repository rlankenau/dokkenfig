#ifndef ETW_CONFIG_PREDICATE_INTERFACE_H_
#define ETW_CONFIG_PREDICATE_INTERFACE_H_

namespace etw {

class PredicateInterface
{
public:
	virtual bool evaluate(ConfigurationInterface *cfg, OptionInterface *op) = 0;
};

}

#endif

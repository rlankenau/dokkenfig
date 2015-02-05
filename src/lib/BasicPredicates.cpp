#include "predicates/BasicPredicates.h"
#include <initializer_list>
#include <list>

namespace etw {

Not::Not(PredicateInterface *inner)
{
	this->inner = inner;
}

bool Not::evaluate(ConfigurationInterface *cfg, OptionInterface *op)
{
	return !this->inner->evaluate(cfg, op);
}

And::And(std::initializer_list<PredicateInterface *> all)
{
	operands = std::list<PredicateInterface *>(all);
}

bool And::evaluate(ConfigurationInterface *cfg, OptionInterface *op)
{
	for(auto operand : operands)
	{
		if(operand->evaluate(cfg, op) == false)
		{
			return false;
		}
	}
	return true;
}

Or::Or(std::initializer_list<PredicateInterface *> any)
{
	operands = std::list<PredicateInterface *>(any);
}

bool Or::evaluate(ConfigurationInterface *cfg, OptionInterface *op)
{
	for(auto operand : operands)
	{
		if(operand->evaluate(cfg, op))
		{
			return true;
		}
	}
	return false;
}

}

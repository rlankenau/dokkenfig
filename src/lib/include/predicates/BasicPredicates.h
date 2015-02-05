#ifndef ETW_CONFIG_BASIC_PREDICATES_H_
#define ETW_CONFIG_BASIC_PREDICATES_H_

#include "ConfigurationInterface.h"
#include "OptionInterface.h"
#include "ExpressionInterface.h"
#include "PredicateInterface.h"
#include <initializer_list>
#include <list>

namespace etw {

class Not : public PredicateInterface
{
public:
	Not(PredicateInterface *inner);
	bool evaluate(ConfigurationInterface *cfg, OptionInterface *op);
private:
	PredicateInterface *inner;

};

class And : public PredicateInterface
{
public:
	And(std::initializer_list<PredicateInterface *> all);
	bool evaluate(ConfigurationInterface *cfg, OptionInterface *op);
private:
	std::list<PredicateInterface *> operands;

};

class Or : public PredicateInterface
{
public:
	Or(std::initializer_list<PredicateInterface *> any);
	bool evaluate(ConfigurationInterface *cfg, OptionInterface *op);
private:
	std::list<PredicateInterface *> operands;

};

class EqualTo : public PredicateInterface
{
public:
	EqualTo(ExpressionInterface *expr);
	bool evaluate(ConfigurationInterface *cfg, OptionInterface *op);
};

class NotEqualTo : public PredicateInterface
{
public:
	NotEqualTo(ExpressionInterface *expr);
	bool evaluate(ConfigurationInterface *cfg, OptionInterface *op);
};

class GreaterThan: public PredicateInterface
{
public:
	GreaterThan(ExpressionInterface *expr);
	bool evaluate(ConfigurationInterface *cfg, OptionInterface *op);
};

class GreaterThanOrEqualTo: public PredicateInterface
{
public:
	GreaterThanOrEqualTo(ExpressionInterface *expr);
	bool evaluate(ConfigurationInterface *cfg, OptionInterface *op);
};

class LessThan: public PredicateInterface
{
public:
	LessThan(ExpressionInterface *expr);
	bool evaluate(ConfigurationInterface *cfg, OptionInterface *op);
};

class LessThanOrEqualTo: public PredicateInterface
{
public:
	LessThanOrEqualTo(ExpressionInterface *expr);
	bool evaluate(ConfigurationInterface *cfg, OptionInterface *op);
};

}
#endif

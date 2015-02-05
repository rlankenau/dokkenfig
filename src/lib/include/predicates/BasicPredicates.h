#ifndef ETW_CONFIG_BASIC_PREDICATES_H_
#define ETW_CONFIG_BASIC_PREDICATES_H_

#include "ExpressionInterface.h"
#include "PredicateInterface.h"

namespace etw {

class Not : public PredicateInterface
public:
	Not(PredicateInterface *inner);
	bool evaluate(ConfigurationInterface *cfg, OptionInterface *op);

};

class And : public PredicateInterface
{
public:
	And(PredicateInterface *lhs, PredicateInterface *rhs);
	And(std::initializer_list<PredicateInterface *> all);
	bool evaluate(ConfigurationInterface *cfg, OptionInterface *op);

};

class Or : public PredicateInterface
{
public:
	Or(PredicateInterface *lhs, PredicateInterface *rhs);
	Or(std::initializer_list<PredicateInterface *> any);
	bool evaluate(ConfigurationInterface *cfg, OptionInterface *op);

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

#endif

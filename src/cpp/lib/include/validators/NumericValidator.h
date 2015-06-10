#ifndef ETW_CONFIG_DISCRETE_NUMERIC_VALIDATOR_H_
#define ETW_CONFIG_DISCRETE_NUMERIC_VALIDATOR_H_

#include "ValidatorInterface.h"
#include "Types.h"

namespace etw {

/* Validator that accepts a single disrete numeric option. */
class ValidNumericValidator : public ValidatorInterface {
public:
	ValidNumericValidator(int64_t val);
	virtual int validateOption(OptionInterface *op);

private:
	int64_t allowed_val;

};

ValidatorInterface *ValidNumeric(int64_t val);

class InvalidNumericValidator : public ValidatorInterface {
public:
	InvalidNumericValidator(int64_t val);
	virtual int validateOption(OptionInterface *op);

private:
	int64_t disallowed_val;

};

ValidatorInterface *InvalidNumeric(int64_t val);

}

#endif

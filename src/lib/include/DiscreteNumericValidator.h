#ifndef ETW_CONFIG_DISCRETE_NUMERIC_VALIDATOR_H_
#define ETW_CONFIG_DISCRETE_NUMERIC_VALIDATOR_H_

#include "ValidatorInterface.h"
#include "Types.h"

namespace etw {

/* Validator that accepts a single disrete numeric option. */
class DiscreteNumericValidator : public ValidatorInterface {
public:
	DiscreteNumericValidator(int64_t val);
	virtual int validateOption(OptionInterface *op);

private:
	int64_t allowed_val;

};

}

#endif

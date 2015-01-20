#ifndef ETW_CONFIG_RANGE_VALIDATOR_H_
#define ETW_CONFIG_RANGE_VALIDATOR_H_

#include "ValidatorInterface.h"
#include "Types.h"

namespace etw {

/* Validator that accepts numeric options within a fixed range. */
class RangeValidator : public ValidatorInterface {
public:
	RangeValidator(int64_t min, int64_t max);
	virtual int validateOption(OptionInterface *op);

private:
	int64_t min_val, max_val;

};

}

#endif

#ifndef ETW_CONFIG_RANGE_VALIDATOR_H_
#define ETW_CONFIG_RANGE_VALIDATOR_H_

#include "ValidatorInterface.h"
#include "Types.h"

namespace etw {

/* Validator that accepts numeric options within a fixed range. */
class ValidRangeValidator : public ValidatorInterface {
public:
	ValidRangeValidator(int64_t min, int64_t max);
	virtual int validateOption(OptionInterface *op);

private:
	int64_t min_val, max_val;

};

ValidatorInterface *ValidRange(int64_t min, int64_t max);

class InvalidRangeValidator : public ValidatorInterface {
public:
	InvalidRangeValidator(int64_t min, int64_t max);
	virtual int validateOption(OptionInterface *op);

private:
	int64_t min_val, max_val;

};

ValidatorInterface *InvalidRange(int64_t min, int64_t max);

}

#endif

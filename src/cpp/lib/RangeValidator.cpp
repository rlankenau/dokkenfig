#include "validators/RangeValidator.h"
#include "OptionInterface.h"
#include "Types.h"

namespace etw {

	ValidRangeValidator::ValidRangeValidator(int64_t min, int64_t max)
	{
		this->min_val = min;
		this->max_val = max;
	}

	int ValidRangeValidator::validateOption(OptionInterface *op)
	{
		int rc = RetVal::Failure;
		int64_t val;
	   	if(op->getNumericValue(&val) == RetVal::Success) {
			if(val >= this->min_val && val <= this->max_val)
			{
				rc = RetVal::Success;
			}
		}

		return rc;
	}

	ValidatorInterface *ValidRange(int64_t min, int64_t max)
	{
		return (ValidatorInterface *)new ValidRangeValidator(min, max);
	}

	InvalidRangeValidator::InvalidRangeValidator(int64_t min, int64_t max)
	{
		this->min_val = min;
		this->max_val = max;
	}

	int InvalidRangeValidator::validateOption(OptionInterface *op)
	{
		int rc = RetVal::Failure;
		int64_t val;
	   	if(op->getNumericValue(&val) == RetVal::Success) {
			if(val >= this->min_val && val <= this->max_val)
			{
				rc = RetVal::Failure;
			} else {
				rc = RetVal::Success;
			}
		}

		return rc;
	}

	ValidatorInterface *InvalidRange(int64_t min, int64_t max)
	{
		return (ValidatorInterface *)new InvalidRangeValidator(min, max);
	}
}

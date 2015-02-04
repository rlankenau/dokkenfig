#include "RangeValidator.h"
#include "OptionInterface.h"
#include "Types.h"

namespace etw {

	RangeValidator::RangeValidator(int64_t min, int64_t max)
	{
		this->min_val = min;
		this->max_val = max;
	}

	int RangeValidator::validateOption(OptionInterface *op)
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

	ValidatorInterface *Range(int64_t min, int64_t max)
	{
		return (ValidatorInterface *)new RangeValidator(min, max);
	}
}

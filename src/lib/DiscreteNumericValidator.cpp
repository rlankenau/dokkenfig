#include "DiscreteNumericValidator.h"
#include "OptionInterface.h"
#include "Types.h"

namespace etw {

	DiscreteNumericValidator::DiscreteNumericValidator(int64_t val)
	{
		this->allowed_val = val;
	}

	int DiscreteNumericValidator::validateOption(OptionInterface *op)
	{
		int rc = RetVal::Failure;
		int64_t val;
	   	if(op->getNumericValue(&val) == RetVal::Success) {
			if(val == this->allowed_val)
			{
				rc = RetVal::Success;
			}
		}

		return rc;
	}
}

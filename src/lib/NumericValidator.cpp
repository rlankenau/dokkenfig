#include "validators/NumericValidator.h"
#include "OptionInterface.h"
#include "Types.h"

namespace etw {

	ValidNumericValidator::ValidNumericValidator(int64_t val)
	{
		this->allowed_val = val;
	}

	int ValidNumericValidator::validateOption(OptionInterface *op)
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

	ValidatorInterface *ValidNumeric(int64_t val)
	{
		return (ValidatorInterface *)new ValidNumericValidator(val);
	}

	InvalidNumericValidator::InvalidNumericValidator(int64_t val)
	{
		this->disallowed_val = val;
	}

	int InvalidNumericValidator::validateOption(OptionInterface *op)
	{
		int rc = RetVal::Failure;
		int64_t val;
	   	if(op->getNumericValue(&val) == RetVal::Success) {
			if(val == this->disallowed_val)
			{
				rc = RetVal::Failure;
			} else {
				rc = RetVal::Success;
			}
		}

		return rc;
	}

	ValidatorInterface *InvalidNumeric(int64_t val)
	{
		return (ValidatorInterface *)new InvalidNumericValidator(val);
	}
}

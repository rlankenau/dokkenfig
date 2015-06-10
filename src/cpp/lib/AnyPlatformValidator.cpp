#include "platform_validators/AnyPlatformValidator.h"
#include "OptionInterface.h"
#include "Types.h"
#include <string>

namespace etw {

	AnyPlatformValidator::AnyPlatformValidator()
	{
	}

	/**
	The AnyPlatformValidator does not apply any restrictions beyond those in the standard
	schema validator.
	*/
	int AnyPlatformValidator::validateOption(std::string platform, OptionInterface *op)
	{
		return RetVal::Success;
	}

	AnyPlatformValidator *AnyPlatform()
	{
		return new AnyPlatformValidator();
	}
}

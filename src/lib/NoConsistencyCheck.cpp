#include "Types.h"
#include "consistency_validators/NoConsistencyCheck.h"


namespace etw {

NoConsistencyCheck::NoConsistencyCheck()
{}

int NoConsistencyCheck::validateOption(ConfigurationInterface *cfg, OptionInterface *op)
{
	return RetVal::Success;
}

}

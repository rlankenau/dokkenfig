#include "gmock/gmock.h"
#include <string>
#include <inttypes.h>
#include "ValidatorInterface.h"
#include "OptionInterface.h"

class MockValidator : public etw::ValidatorInterface {
public:
	MOCK_METHOD1(validateOption, int(etw::OptionInterface *op));
};

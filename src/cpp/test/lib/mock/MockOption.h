#include "gmock/gmock.h"
#include <string>
#include <inttypes.h>
#include "OptionInterface.h"

class MockOption : public etw::OptionInterface {
public:
	MOCK_METHOD1(getOptionName, int(std::string *));
	MOCK_METHOD1(getStringValue, int(std::string *));
	MOCK_METHOD1(setStringValue, int(std::string));
	MOCK_METHOD1(getNumericValue, int(int64_t *));
	MOCK_METHOD1(setNumericValue, int(int64_t ));
};

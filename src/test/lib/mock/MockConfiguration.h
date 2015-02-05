#include "gmock/gmock.h"
#include <string>
#include <inttypes.h>
#include "ConfigurationInterface.h"
#include "SchemaInterface.h"

class MockConfiguration : public etw::ConfigurationInterface {
public:
	MOCK_METHOD2(initialize, int(etw::SchemaInterface *s, std::string platform));
	MOCK_METHOD2(getStringOption, int(std::string, std::string*));
	MOCK_METHOD2(setStringOption, int(std::string, std::string));
	MOCK_METHOD2(getNumericOption, int(std::string, int64_t*));
	MOCK_METHOD2(setNumericOption, int(std::string, int64_t));
	MOCK_METHOD2(registerOptionHandler, int(std::string, etw::ConfigurationHandlerInterface*));
	MOCK_METHOD1(apply, int(etw::ValidationError &));

};

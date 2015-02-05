#ifndef ETW_CONFIG_CONFIGURATION_INTERFACE_H_
#define ETW_CONFIG_CONFIGURATION_INTERFACE_H_

#include "ConfigurationHandlerInterface.h"
#include "ValidationError.h"
#include "SchemaInterface.h"

namespace etw {


class ConfigurationInterface {

public:
	virtual int initialize(SchemaInterface *s, std::string platform) = 0;
	virtual int getStringOption(std::string key, std::string *val) = 0;
	virtual int setStringOption(std::string key, std::string val) = 0;
	virtual int getNumericOption(std::string key, int64_t *val) = 0;
	virtual int setNumericOption(std::string key, int64_t val) = 0;
	virtual int registerOptionHandler(std::string key, ConfigurationHandlerInterface *handler) = 0;
	virtual int apply(ValidationError &err) = 0;

};

}

#endif

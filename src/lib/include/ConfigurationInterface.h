#ifndef ETW_CONFIG_CONFIGURATION_INTERFACE_H_
#define ETW_CONFIG_CONFIGURATION_INTERFACE_H_

namespace etw {

class Schema;

class ConfigurationInterface {

public:
	virtual int initialize(Schema *s) = 0;
	virtual int getStringOption(std::string key, std::string *val) = 0;
	virtual int setStringOption(std::string key, std::string val) = 0;
	virtual int getNumericOption(std::string key, int *val) = 0;
	virtual int setNUmericOption(std::string key, int val) = 0;

};

}

#endif

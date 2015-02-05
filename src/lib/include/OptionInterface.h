#ifndef ETW_CONFIG_OPTION_INTERFACE_H_
#define ETW_CONFIG_OPTION_INTERFACE_H_

#include <string>
#include <stdint.h>

namespace etw {

class OptionInterface {

public:
	virtual int getOptionName(std::string *out) = 0;
	virtual int getStringValue(std::string *out) = 0;	
	virtual int setStringValue(std::string in) = 0;
	virtual int getNumericValue(int64_t *out) = 0;
	virtual int setNumericValue(int64_t in) = 0;

};

}

#endif

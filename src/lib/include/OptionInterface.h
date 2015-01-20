#ifndef ETW_CONFIG_OPTION_INTERFACE_H_
#define ETW_CONFIG_OPTION_INTERFACE_H_

namespace etw {

class OptionInterface {

public:
	virtual int getStringValue(std::string *out) = 0;	
	virtual int setStringValue(std::string in) = 0;
	virtual int getNumericValue(int *out) = 0;
	virtual int setNumericValue(int in) = 0;

};

}

#endif

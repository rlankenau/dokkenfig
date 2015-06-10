#ifndef ETW_CONFIG_OPTION_H_
#define ETW_CONFIG_OPTION_H_

#include "OptionInterface.h"

namespace etw {

class Option : public OptionInterface
{
public:
	Option(std::string name, std::string value);
	Option(std::string name, int64_t value);
	virtual int getOptionName(std::string *out);
	virtual int getStringValue(std::string *out);	
	virtual int setStringValue(std::string in);
	virtual int getNumericValue(int64_t *out);
	virtual int setNumericValue(int64_t in);
private:
	std::string name;
	std::string value;
	int type;

};

}

#endif

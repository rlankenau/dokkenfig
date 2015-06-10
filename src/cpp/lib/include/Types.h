#ifndef ETW_CONFIG_TYPES_H_
#define ETW_CONFIG_TYPES_H_

#include <stdint.h>
	
namespace etw {

class RetVal {
public:
	static const int Success;
	static const int Failure;

};

class OptionType {
public:
	static const int String;
	static const int Numeric;

};

}

#endif

#ifndef ETW_CONFIG_DEFAULT_INTERFACE_H_
#define ETW_CONFIG_DEFAULT_INTERFACE_H_

namespace etw {

class Option;

class DefaultInterface() {
public:
	virtual int getDefaultOption(std::string platform, Option** op) = 0;
};

}

#endif

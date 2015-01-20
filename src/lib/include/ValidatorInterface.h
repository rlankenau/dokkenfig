#ifndef ETW_CONFIG_VALIDATOR_INTERFACE_H_
#define ETW_CONFIG_VALIDATOR_INTERFACE_H_


namespace etw {

class Option;

class Validator
{
public:
	virtual int validateOption(Option *op) = 0;
};

}
#endif


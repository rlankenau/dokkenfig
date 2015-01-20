#ifndef ETW_CONFIG_VALIDATOR_INTERFACE_H_
#define ETW_CONFIG_VALIDATOR_INTERFACE_H_


namespace etw {

class OptionInterface;

class ValidatorInterface
{
public:
	virtual int validateOption(OptionInterface *op) = 0;
};

}
#endif


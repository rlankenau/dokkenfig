#ifndef ETW_CONFIG_CONFIGURATION_HANDLER_INTERFACE_H_
#define ETW_CONFIG_CONFIGURATION_HANDLER_INTERFACE_H_

#include "OptionInterface.h"

namespace etw {

class ConfigurationHandlerInterface {
public:
	virtual int handleOption(const OptionInterface *op);

};

}

#endif

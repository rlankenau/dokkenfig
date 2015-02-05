#ifndef ETW_CONFIG_SCHEMA_INTERFACE_H_
#define ETW_CONFIG_SCHEMA_INTERFACE_H_

namespace etw {

class ValidatorInterface;
class PlatformValidatorInterface;
class ConsistencyValidatorInterface;
class DefaultInterface;
class ConfigurationInterface;

class SchemaInterface {

public:
	virtual int initialize() = 0;
	virtual int addOption(std::string name, int type, std::string desc, 
				ValidatorInterface *valid_ops, 
				PlatformValidatorInterface *valid_platforms,
				ConsistencyValidatorInterface *consistency_check,
				DefaultInterface *defaults) = 0;

	virtual int validateConfiguration(ConfigurationInterface *cfg, ValidationError &err) = 0;
};

}

#endif

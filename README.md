# config
Library for configuring software libraries.  Includes multiple levels of configuration as well as the generation of config documentation.

# Basic Concept

Configuration is a critical part of any software library, and over time, can grow unwieldy if not managed well.  Developers often add new options, seldom remove existing options, and sometimes need to change defaults, which is a maintanence issue for users of the product.  Typically, different code handles validation of the schema, validation of the applicability of the options to the current platform, validation of the viability of a particular set of configuration options, and validation of the instantiation of objects that rely on this configuration.  Sometimes, these steps are skipped entirely, and error detection occurs when an object cannot be created or an exception is thrown.  This project aims to provide a declarative way of using configuration that can address all of these validation steps, as well as generate configuration documentation.

# Types and Objects

## Options

A configuration option has a type, a name, and a value.

The only types allowed are strings and numeric values.  Numeric values are signed 64-bit values, and are only provided as a convenience since validation using ranges is extremely common.

Option names are case-sensitive, and consist of the letters a-z, A-Z, the numbers 0-9, and the special characters '.' and '\*'.  Names must match the following grammar:

    name     = <fragment>
               | <name>.<fragment>;

    fragment = <wildcard-fragment>
	       | <literal-fragment>;

    wildcard-fragment = "*";

    literal-fragment = <letter>
                       | <literal-fragment>, { <letter> | <digit> | "_"};
    
    letter = "A" | "B" | "C" | "D" | "E" | "F" | "G"
       | "H" | "I" | "J" | "K" | "L" | "M" | "N"
       | "O" | "P" | "Q" | "R" | "S" | "T" | "U"
       | "V" | "W" | "X" | "Y" | "Z" | "a" | "b" 
       | "c" | "d" | "e" | "f" | "g" | "h" | "i" 
       | "j" | "k" | "l" | "m" | "n" | "o" | "p" 
       | "q" | "r" | "s" | "t" | "u" | "v" | "w" 
       | "x" | "y" | "z" ;
    
    digit = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;

### Named Options

Names should be thought of as a tree structure.  Here are some examples of options that might be included in a product:

* file.name
* file.size
* window.height
* window.width
* output.directory.permissions.user.execute

The option tree may be arbitrarily deep, but shorter options are easier to type, and easier to remember.  Building a logical hierarchy that has consistent naming and easy-to-understand options is just as important as validation and documentation.

### Wildcard Options

Wildcard options are very powerful, because they allow you to specify array-valued options while still doing schema validation. An '\*' character in a path matches any valid literal-fragment in the grammar above.  An example of a wildcard option is something like this:

    storage.areas.*.path

This option would accept any of the following as valid names:

    storage.areas.user.path
    storage.areas.my.path
    storage.areas.area1_where_we_keep_secret_files.path

The API allows all matched values to be fetched as a list.

## Configurations

A configuration is a collection of options that can be validated against a specific schema.  

## Schema

A schema provides the mechanism for validating a configuration, as well as default values, platform notation, deprecation status, and other metadata about configuration options.

# Example

    The Schema API is in flux, so for right now the best example is in the Wiki, under https://github.com/rlankenau/dokkenfig/wiki/Validation.  The following is mostly up to date.


    Schema s;
    s.initialize();
    s.addOption("app.buffer.size",       /* Option name */
            Option::Numeric,         /* Option type */
            "The number of bytes used for buffering data",  /* Description */
            ValidRange(1024, 4096),       /* Validation Object */
            AnyPlatform(),                   /* Platform validator */
            NoConsistencyChecks(),           /* Consistency validator */
            NumericDefault(2048);                    /* Default */
    Configuration c;

    c.initialize(s);
    c.setOptionNumeric("app.buffer.size", 1024); /* Returns success */
    c.setOptionNumeric("app.buffer.size", 1);    /* Returns failure */


    int64_t my_val;
    c.getOptionNumeric("app.buffer.size", &my_val); /* Returns success, fills my_val in with 1024 */ 

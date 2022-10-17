#include <iostream>
#include <string>

#include <map>

#include "Args.h"

namespace Basic {

/**
 * @brief Construct a new Args:: Args object
 * from the argument values passed into main
 *
 * @param argc
 * @param argv
 */
Args::Args(int argc, const char ** argv)
    : mArgv(argv)
    , mArgc(argc) {}


/**
 * @brief Add a key to the data store that will not
 * expect a value tro be attached. A key is made up
 * of a shore key i.e. -a and an alternative key
 * i.e. --alt. Searching for the key must be done with
 * the short key.
 *
 * @param k
 * @param a
 */
void Args::add_key(std::string k, std::string a) {
    int idx=0;
	while(idx<mArgc) {
		// Input file
		if(mArgv[idx] == k || mArgv[idx] == a) {
            mArgs.emplace(k);
			break;
		}

        idx++;
	}
}

/**
 * @brief Add a flag that will have a value attached when it is
 * tested and retrieved.
 *
 * @param key
 * @param alt
 * @param def
 */
void Args::add_string_value(std::string key, std::string alt, std::string def ) {

	std::string value="";
	int idx=0;

	while(idx<mArgc) {
		if(mArgv[idx] == key || mArgv[idx] == alt) {
			if(++idx<mArgc) {
				value = mArgv[idx];
                mArgs.emplace(key);
				break;
			}
		}

		idx++;
	}

    if(value == "") {
        value = def;
    }

    mStrArgs.emplace(key, value);
}

/**
 * @brief Add a value that is expected to be a numeric
 * integer value. It will be converted to an int when it is
 * retrieved. The method can pass in a default value that will
 * be used if the value is absent.
 *
 * @param key
 * @param alt
 * @param def
 */
void Args::add_int_value(std::string key, std::string alt, int def) {

	int value = 0;
	int idx = 0;

    std::string v{""};

	while(idx<mArgc) {
		// Input file
		if(mArgv[idx] == key || mArgv[idx] == alt) {
			if(++idx<mArgc) {
				v = mArgv[idx];
                mArgs.emplace(key);
				break;
			}
		}

		idx++;
	}

    if(v != "")
        value = atoi(v.c_str());
    else
        value = def;

    mIntArgs.emplace(key, value);
}

/**
 * @brief Get the integer value at for this key
 *
 * @param key
 * @return int
 */
int Args::get_int_value(std::string key) {
    auto it = mIntArgs.find(key);

    if(it != mIntArgs.end()) {
        return it->second;
    }

    return -1;
}

/**
 * @brief Get the string value for this key
 *
 * @param key
 * @return std::string
 */
std::string Args::get_string_value(std::string key) {
    auto it = mStrArgs.find(key);

    if(it != mStrArgs.end()) {
        return it->second;
    }

    return "";
}
/**
 * @brief Test if a key is present. this function can
 * be used to test the presence of a key for a flag,
 * string value, or an int value.
 *
 * @param key
 * @return true
 * @return false
 */
bool Args::is_key_present(std::string key) {
    if(mArgs.find(key) != mArgs.end())
        return true;

    return false;
}
}
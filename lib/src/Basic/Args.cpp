#include <iostream>
#include <string>

#include <map>

#include "Args.h"

namespace Basic {

Args::Args(int argc, const char ** argv)
    : mArgv(argv)
    , mArgc(argc) {}



void Args::add_key(std::string k, std::string a) {
    bool flag=false;
    int idx=0;
	while(idx<mArgc) {
		// Input file
		if(mArgv[idx] == k || mArgv[idx] == a) {
			flag=true;
			break;
		}

        idx++;
	}

    mBoolArgs.emplace(k, flag);
}

void Args::add_string_value(std::string key, std::string alt, std::string def ) {

	std::string value="";
	int idx=0;

    std::string k = key;
    std::string a = alt;


	while(idx<mArgc) {
		if(mArgv[idx] == k || mArgv[idx] == a) {
			if(++idx<mArgc) {
				value = mArgv[idx];
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

void Args::add_int_value(std::string key, std::string alt, int def) {

	int value = 0;
	int idx = 0;

    std::string k = key;
    std::string a = alt;
    std::string v{""};


	while(idx<mArgc) {
		// Input file
		if(mArgv[idx] == k || mArgv[idx] == a) {
			if(++idx<mArgc) {
				v = mArgv[idx];
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

int Args::get_int_value(std::string key) {
    auto it = mIntArgs.find(key);

    if(it != mIntArgs.end()) {
        return it->second;
    }

    return -1;
}


std::string Args::get_string_value(std::string key) {
    auto it = mStrArgs.find(key);

    if(it != mStrArgs.end()) {
        return it->second;
    }

    return "";
}

bool Args::is_key_present(std::string key) {
    auto it = mBoolArgs.find(key);

    if(it != mBoolArgs.end())
        return it->second;

    return false;
}

bool Args::is_string_present(std::string key) {
    std::string val = get_string_value(key);
    if(val == "")
        return false;

    return true;
}
}
#ifndef __ARGS__
#define __ARGS__

#include <map>
#include <string>
#include <cstddef>

namespace Basic {

class Args {
public:
    Args(int argc, const char ** argv);
    void add_string_value(std::string idxName, std::string altName, std::string def = "");
    void add_int_value(std::string idxName, std::string altName, int def);
    void add_key(std::string key, std::string alt);
    int get_int_value(std::string key);
    std::string get_string_value(std::string key);
    bool is_key_present(std::string key);
    bool is_string_present(std::string key);

private:
    const char ** mArgv;
    int mArgc;
    std::map<std::string,int> mIntArgs;
    std::map<std::string,std::string>mStrArgs;
    std::map<std::string,bool>mBoolArgs;
};
}
#endif//__ARGS__
#include <iostream>

#include "CmdParser.h"
#include "Exceptions/Exceptions.h"

namespace Numbers {

CmdParser::CmdParser(std::string origCmd)
{
    std::string cmd = origCmd;

    int absolute = 0;
    std::string word {""};
    std::vector<std::string> delims {};

    // We need to account for simple delimiter statement //;
    // and the mor complex multi delimiter statement //[aaa][bbb][ccc]
    if(cmd[0] == '/' && cmd[1] == '/') {
        absolute=2;
        cmd = cmd.substr(2, cmd.size() - 2);

restart:
        // Eat up spaces
        int count=0;
        for(auto c : cmd) {
            if(c != ' ')
            break;

            absolute++;
            count++;
        }

        cmd = cmd.substr(count,cmd.size()-count);

        // The start of multi delimiter statement
        if(cmd[0] == '[') {
            cmd = cmd.substr(1,cmd.size()-1);

            for(size_t place=0;place<cmd.size();place++,absolute++) {
                if(cmd[place] == ']') {
                    std::string del = cmd.substr(0,place);

                    delims.push_back(del);
                    cmd = cmd.substr(place+1,cmd.size()-place+2);
                    goto restart;
                }

                // Error, bad brackets
                if(cmd[place] == '[') {
                    throw Exception::BadBrackets(absolute);
                }
            }
        }
        else if(cmd[1] == '\n') {
            std::string d {cmd[0]};
            delims.push_back(d);
            std::string nums = cmd.substr(1,cmd.size()-1);
            mNumList = std::make_unique<NumberList>(nums,delims);
            return;
        }
        else if(cmd[0] == '\n') {
            std::string nums = cmd.substr(1,cmd.size()-1);
            mNumList = std::make_unique<NumberList>(nums,delims);
            return;
        }

    }

    throw Exception::Generic("invalid input : " + origCmd);
}

int CmdParser::add() {
    if(mNumList) {
        if(!mNumList->to_num_vector()) {
            throw Exception::Generic("failed to parse input");
        }

        return mNumList->add();
    }

    throw Exception::Generic("no number list supplied or constructed");
}




}
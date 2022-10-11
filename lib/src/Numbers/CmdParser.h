#ifndef CMD_PARSER_H
#define CMD_PARSER_H

#include <memory>
#include "NumberList.h"

namespace Numbers {

class CmdParser {
public:
    CmdParser(std::string cmd);
    int add();

private:
    std::unique_ptr<NumberList> mNumList;
};


}

#endif//CMD_PARSER_H
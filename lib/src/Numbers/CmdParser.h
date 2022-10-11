#ifndef CMD_PARSER_H
#define CMD_PARSER_H
/**
 * @file CmdParser.h
 * @author barry.robinson (barry.robinson@alertlogic.com)
 * @brief Defines a basic parser for the command string
 * This splits up up the delimiter commands and the number
 * list adn offloads processing of the number list to a
 * NumberList class in the same library.
 * @version 1.0
 * @date 11-10-2022
 *
 * @copyright Copyright (C) 2022 Alert Logic
 *
 */
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
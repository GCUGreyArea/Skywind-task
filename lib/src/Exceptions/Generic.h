#ifndef GENERIC_H
#define GENERIC_H
/**
 * @file Generic.h
 * @author Barry Robinson (barry.w.robinson64@agmail.com)
 * @brief Defines a generic exception based on the std::exception
 * class. The point of sub classing this is to be able to catch and
 * respond to specific exception types.
 * @version 1.0
 * @date 10-10-2022
 *
 */
#include <exception>
#include <string>

namespace Exception {

class Generic : public std::exception {
public:
    Generic(std::string msg)
        : mMsg(msg) {}

    const char * what() const throw () {
        return mMsg.c_str();
    }

private:
    std::string mMsg;
};

};

#endif//GENERIC_H
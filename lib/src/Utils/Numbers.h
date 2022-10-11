#ifndef NUMBERS_H
#define NUMBERS_H
/**
 * @file Numbers.h
 * @author barry.robinson (barry.w.robinson64@agmail.com)
 * @brief Class that allows for the identification and translation
 * of string numeric values to their C++ equivalent types.
 * @version 1.0
 * @date 10-10-2022
 *
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Exceptions/Exceptions.h"

namespace Utils {

class Numbers {
public:
  /**
   * @brief Determine if the literal is a valid number
   *
   * @param s
   * @return unsigned int as the base of number, or zero if it
   * is not a valid numerical string.
   */
  static unsigned int is_number(std::string s) {
    const char *str = s.data();

    unsigned int ret = 10;
    bool neg = false;

    // Catch negative numbers
    if (*str == '-') {
      neg = true;
      str++;
    }

    if (*str == '0') {
      // This is just 0 so assume base 10
      if (*(str + 1) == '\0')
        return 10;

      str++;

      if (*str == 'x' || *str == 'X') {
        ret = 16;
        str++;
      } else if (*str == 'b' || *str == 'B') {
        ret = 2;
        str++;
      } else {
        // Octal numbers in c++ are prefixed by 0
        ret = 8;
      }
    }

    while (*str != '\0') {
      switch (*str) {
      case '0':
      case '1':
        break;
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
        if (ret == 2)
          return 0;
        break;
      case '8':
      case '9':
        if (ret == 8) {
          std::cerr << "WARNING: Octal number contains no octal value " << *str
                    << std::endl;
          std::cerr << "Falling back to decimal" << std::endl;
          ret = 10;
        }
        break;
      case 'A':
      case 'B':
      case 'C':
      case 'D':
      case 'E':
      case 'F':
      case 'a':
      case 'b':
      case 'c':
      case 'd':
      case 'e':
      case 'f':
        if (ret != 16)
          return 0;
        break;

      default:
        return 0;
      }
      str++;
    }

    return ret;
  }

  static uint64_t to_int(std::string str, unsigned int base) {
    int ret = 0;
    char *end = nullptr;
    char *n = nullptr;
    switch (base) {
        case 2: {

            n = (char *)str.data() + 2; // Remove "0b"
            ret = strtol(n, &end, 2);
            break;
        }
        case 8:
            sscanf(str.c_str(), "%o", &ret);
            break;
        case 10:
            sscanf(str.c_str(), "%d", &ret);
            break;
        case 16:
            sscanf(str.c_str(), "%x", &ret);
            break;

        default:
            throw Exception::Internal("not a valid base " + std::to_string(base));
    }

    return ret;
  }

  static bool is_numeric(char c) {
    switch (c) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      return true;

    default:
      break;
    }

    return false;
  }
};

} // namespace Utils

#endif // NUMBERS_H
#ifndef NUMBER_LIST_H
#define NUMBER_LIST_H
/**
 * @file NumberList.h
 * @author barry robinson (barry.w.robinson64@gmail.com)
 * @brief A class to evaluate a list of numbers given a
 * set of delimiters
 * @version 1.0
 * @date 10-10-2022
 *
 * @copyright Copyright (C) 2022 Alert Logic
 *
 */
#include <string>
#include <vector>
#include <unordered_set>

#include "Exceptions/Exceptions.h"

namespace Numbers
{

class NumberList {
public:
    NumberList(std::string list,std::vector<std::string> delims, int max = 1000)
        : mNumList(list)
        , mDelims(delims)
        , mMax(max) {
            for(auto d : mDelims) {
                mDelimSet.emplace(d);
            }

        }

    int add();

    bool to_num_vector();

    std::vector<int>& get_numbers() {
        return mNums;
    }

private:
    bool map_delimeter(std::string word);
    bool map_number(std::string word);
    bool is_numeric(char c);

    std::string mNumList;
    std::vector<int> mNums;
    std::vector<std::string> mDelims;
    std::unordered_set<std::string> mDelimSet;
    int mMax;
};
} // namespace Numbers


#endif//NUMBER_LIST_H
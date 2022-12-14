#include <re2/re2.h>

#include "Utils/Numbers.h"
#include "NumberList.h"
#include "Exceptions/Exceptions.h"

namespace Numbers {

/**
 * @brief Get the sum of the numbers in the integer number
 * vector accounting for a maximum value. The maximum value is
 * configurable through the constructor.
 *
 * @return int
 */
int NumberList::add() {
    int total = 0;
    for(auto n : mNums) {
        while(n > mMax) {
            n = n % mMax;
        }

        total += n;
    }

    return total;
}

/**
 * @brief Parse the string number list into a vector
 * of integer using the supplied delimiter values.
 * @throw Exception::NegativeNumber, Exception::IllegalNumber,
 * Exception::EndOfContent
 */
void NumberList::to_num_vector() {
    char * list = (char*) mNumList.c_str();

    std::string word;

    enum State {
        UNKNOWN,
        NUMBER,
        WORD
    } state = UNKNOWN;

    while(*list != '\0') {
        switch(*list)
        {
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
                if(state == WORD) {
                    if(!map_delimeter(word)) {
                        // TODO: This should be more elegant
                        if(word == "-") {
                            while(*list != '\0' && Utils::Numbers::is_numeric(*list)) {
                                word += *list;
                                list++;
                            }
                            throw Exception::NegativeNumber(word, mNumList);
                        }
                        else if(word[word.size()-1] == '-') {
                            word = "-";
                            while(*list != '\0' && Utils::Numbers::is_numeric(*list)) {
                                word += *list;
                                list++;
                            }
                            throw Exception::NegativeNumber(word, mNumList);
                        }

                        throw Exception::IllegalDelimiter(word);
                    }
                    word = "";
                }

                word += *list;
                state = NUMBER;
                list++;
                continue;

            // Eat up new lines
            case '\n':
                list++;
                continue;

            default:
                if(state == NUMBER) {
                    if(!map_number(word))
                        throw Exception::IllegalNumber(word);
                    word = "";
                }
                word += *list;
                state = WORD;
                list++;
                continue;
        }
    }

    if(state == WORD ) {
        throw Exception::EndOfContent(word);
    }

    if(!map_number(word))
        throw Exception::IllegalNumber(word);
}

/**
 * @brief Map a word as a delimiter and add it
 * to the available set.
 *
 * @param word
 * @return true
 * @return false
 */
bool NumberList::map_delimeter(std::string word) {
    if(mDelimSet.find(word) == mDelimSet.end())
        return false;

    return true;
}

/**
 * @brief Map a work string value top value
 * to an integer value.
 *
 * @param word
 * @return true
 * @return false
 */
bool NumberList::map_number(std::string word) {
    int base = Utils::Numbers::is_number(word);
    if(base == 0)
        return false;


    mNums.push_back(Utils::Numbers::to_int(word,base));

    return true;
}


}
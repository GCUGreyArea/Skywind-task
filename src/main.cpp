/**
 * @file main.cpp
 * @author Barry Robinson (barry.w.robinson64@gmail.com)
 * @brief main executable file for project
 * @version 0.1
 * @date 11/10/2022
 *
 * @copyright Copyright Barry Robinson(c) 2022
 *
 * @addtogroup application
 * @{
 * @addtogroup main
 * @{
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <signal.h>
#include <unistd.h>

#include <libTask.h>

void static inline do_help() {
	std::cout << "./build/task -n \"//[.][,]\\n1,2.3.4\"" << std::endl;
	std::cout << "\nValid input" << std::endl;
	std::cout << "\tInput                ::= <Start> <DelimiterList> <End> <NumberList>" << std::endl;
	std::cout << "\tStart                ::= '//'" << std::endl;
	std::cout << "\tDelimiterList        ::= <SimpleDelimiter> || <ComplexDelimiterList>" << std::endl;
	std::cout << "\tSimpleDelimiter      ::= [0-9A-Za-z\\,\\-\\.\\*\\&\\^\\%\\$\\£\\@\\!\\+]+" << std::endl;
	std::cout << "\tComplexDelimiterList ::= '[' <SimpleDelimiter> ']' || '[' <SimpleDelimiter> ']' <ComplexDelimiterList>" << std::endl;
	std::cout << "\tEnd                  ::= '\\n'" << std::endl;
	std::cout << "\tNumberList           ::= [0-9]+ || [0-9]+ <SimpleDelimiter> <NumberList>" << std::endl;
}
/**
 * @brief Program entry point
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, const char ** argv)
{
	Basic::Args args(argc,argv);

	args.add_key("-h","--help");
	args.add_string_value("-n","--numbers");

	if(args.is_key_present("-h")) {
		do_help();
		return 0;
	}


	if(args.is_key_present("-n")) {
		std::string cmd = args.get_string_value("-n");

		// TODO: move this functionality into Args

		size_t index = cmd.find("\\n");
		while(index != -1) {
			cmd = cmd.replace(index, 2, "\n");
			index = cmd.find("\\n");
		}

		try{
			Numbers::CmdParser parser(cmd);
			std::string value = std::to_string(parser.add());

			std::cout << "The sum of the number list is : " << value << std::endl;
		}
		catch(Exception::Generic& e) {
			std::cerr << "Exception caught : " << e.what() << std::endl;
			return -1;
		}
	}

	do_help();

	return 0;
}

/**
 * @}
 * @}
 */

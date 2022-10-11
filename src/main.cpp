/**
 * @file main.cpp
 * @author Barry Robinson (barry.w.robinson64@gmail.com)
 * @brief main executable file for project
 * @version 0.1
 * @date 26/09/2021
 *
 * @copyright Copyright Barry Robinson(c) 2022
 * @defgroup main
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
	std::cout << "Help output" << std::endl;
}

int main(int argc, const char ** argv)
{
	Basic::Args args(argc,argv);

	args.add_key("-h","--help");
	args.add_string_value("-n","--numbers");

	if(args.is_key_present("-h")) {
		do_help();
		return 0;
	}


	if(args.is_string_present("-n")) {
		std::string cmd = args.get_string_value("-n");
		const size_t index = cmd.find("\\n");
		if(index)
			cmd = cmd.replace(index, 2, "\n");
		else
			throw Exception::Generic("invalid input : " + cmd);

		Numbers::CmdParser parser(cmd);

		std::cout << "Value is : " << std::to_string(parser.add()) << std::endl;
	}

	return 0;
}

/**
 * @}
 */

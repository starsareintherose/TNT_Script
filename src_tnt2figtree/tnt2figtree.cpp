#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>

std::string remove_useless(std::string input_str1)
{
	std::string result_str1 =
	    std::regex_replace(input_str1, std::regex(" /*"), " ");
	result_str1 = std::regex_replace(result_str1, std::regex("\\["), "{");
	result_str1 = std::regex_replace(result_str1, std::regex("\\]"), "}");
	return result_str1;
}

std::string add_support(std::string input_str2)
{
	std::string result_str2 = "";
	size_t i = 0;
	while (i < input_str2.length()) {
		if (input_str2[i] == ')') {
			result_str2 += input_str2[i];
			i++;
			std::string support_str = "";
			while (i < input_str2.length() &&
			       std::regex_match(std::string(1, input_str2[i]),
						std::regex("[/0-9{}?]"))) {
				support_str += input_str2[i];
				i++;
			}
			result_str2 += "[&support=\"" + support_str + "\"]";
		}
		else {
			result_str2 += input_str2[i];
			i++;
		}
	}
	return result_str2;
}

std::string add_blen(std::string input_str3)
{
	std::string result_str3 = "";
	int i = 0;
	for (char c : input_str3) {
		if (c == '(') {
			i++;
			result_str3 += c;
		}
		else if (c == ')') {
			result_str3 += ":" + std::to_string(i) + c;
			i--;
		}
		else if (c == ',') {
			result_str3 += ":" + std::to_string(i) + c;
		}
		else {
			result_str3 += c;
		}
	}
	return result_str3;
}

std::string remove_slash(std::string input_str4)
{
	std::string result_str4 = std::regex_replace(
	    input_str4, std::regex("\\[&support=\"[\\/\\s]*\"\\]"), "");
	return result_str4;
}

std::vector<std::string> get_lines(std::string filename)
{
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cout << "Failed to open the input file." << std::endl;
	}

	std::vector<std::string> lines;
	std::string line;
	while (std::getline(file, line)) {
		lines.push_back(line);
	}
	file.close();
	return lines;
}

std::vector<std::string> process_line(std::vector<std::string> lines,
				      size_t lineNum)
{
	std::string line = remove_useless(lines[lineNum]);
	line = add_blen(line);
	line = add_support(line);

	lines[lineNum] = remove_slash(line);
	return lines;
}

void write_lines(const std::vector<std::string>& lines,
		 const std::string& filename)
{
	std::ofstream outfile(filename);

	if (!outfile.is_open()) {
		std::cout << "Failed to open the output file." << std::endl;
	}

	for (const std::string& line : lines) {
		outfile << line << std::endl;
	}

	outfile.close();
}

void interactive_commands(std::vector<std::string> lines)
{
	std::string command, filename1, filename2;
	std::cout
	    << "~|~|\\ |~|~~)|~o(~|~|~._ _ _\n | | \\| | /_|~| _| | | }_}_"
	    << std::endl;
	std::cout << "TNT2FigTree\nMIT, Guoyi Zhang, 2024\nplease type help "
		     "to see more commands"
		  << std::endl;
	while (true) {
		std::cout << "tnt2figtree> ";
		getline(std::cin, command);
		if (command == "help") {
			std::cout << "help\t\t\tshow interactive commands "
				     "help\nimport <filename>\timport a TNT "
				     "output nexus format tree by TNT export "
				     "command\nexport <filename>\texport a "
				     "nexus format tree file\nquit\t\t\tquit "
				     "the program\nexit\t\t\texit the program"
				  << std::endl;
		}
		else if (command.find("import ") == 0) {
			std::stringstream ss(command.substr(7));
			ss >> filename1;
			if (filename1.empty()) {
				std::cout << "tnt2figtree> please specify a "
					     "filename."
					  << std::endl;
			}
			else {
				lines = get_lines(filename1);
			}
		}
		else if (command.find("export ") == 0) {
			std::stringstream ss(command.substr(7));
			ss >> filename2;
			if (filename2.empty()) {
				std::cout << "tnt2figtree> please specify a "
					     "filename."
					  << std::endl;
			}
			else {
				for (size_t i = 0; i < lines.size(); i++) {
					if (lines[i][0] == '(') {
						lines = process_line(lines, i);
					}
				}
				write_lines(lines, filename2);
			}
		}
		else if (command == "quit" || command == "exit") {
			break;
		}
		else {
			std::cout << "tnt2figtree> unrecognized command. Type "
				     "'help' for "
				     "a list of commands."
				  << std::endl;
		}
	}
}

int main(int argc, char* argv[])
{
	std::vector<std::string> lines;
	if (argc == 1) {
		interactive_commands(lines);
		return 0;
	}
	else if (argc == 3) {
		lines = get_lines(argv[1]);
		for (size_t i = 0; i < lines.size(); i++) {
			if (lines[i][0] == '(') {
				lines = process_line(lines, i);
			}
		}
		write_lines(lines, argv[2]);
	}
	else {
		std::cout << "Usage: " << argv[0]
			  << " <input_tnt_treefile> <output_nexus_treefile>"
			  << std::endl;
	}
	return 0;
}


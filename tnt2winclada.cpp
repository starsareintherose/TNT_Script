#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>

using namespace std;

string inputFileName, outputFileName, tnt_format, winclada_format;

void argument(int argc, char** argv);
int read_tnt();
void showhelp(int help_num);
void parse_line(int trelen);
void add_space (string winclada, char x);
bool isNum(string strnum);

void show_help (int help_num){
if (help_num == 0) {
	cout << "~|~|\\ |~|~  ~)  |    |o._ |~| _  _| _ " << endl;
	cout << " | | \\| |   /_   \\/\\/ || ||_|(_|(_|(_|" << endl;
	cout  << "TNT2WinClada\nMIT, Guoyi Zhang, 2023\nplease use -h to see more options" << endl;
	} else {
		cout << "~|~|\\ |~|~  ~)  |    |o._ |~| _  _| _ " << endl;
		cout << " | | \\| |   /_   \\/\\/ || ||_|(_|(_|(_|" << endl;
		cout << "Usage: tnt2winclada -i ${input_file} -o ${output_file}\n-h help;\n-i input: -i ${input_file};\n-o output: -o ${output_file}" << endl;
	}
}

void argument(int argc, char **argv) {
	// -i -h -o option
	for (int i = 0; i < argc; i++) {
		if (argc == 2 && string(argv[1]) == "-h") {
			show_help(1);
			exit(0);
		}
		if (argc != 5 || string(argv[1]) != "-i" || string(argv[3]) != "-o") {
			cout << "input or output can't be empty." << endl;
			show_help(0);
			exit(0);
		}
		if (string(argv[i]) == "-i") {
			i++;
			inputFileName = argv[i];
		}
		if (string(argv[i]) == "-o") {
			i++;
			outputFileName = argv[i];
		}
	}
}

int read_tnt() {
	int trelen;
	ifstream inputFile(inputFileName);
	if (inputFile.is_open()) {
		getline(inputFile, tnt_format);
		inputFile.close();
		trelen = tnt_format.length();
	} else {
		cout << "File can't be opened" << endl;
	}
	inputFile.close();
	return trelen;
}

void add_space (char x) {
	int i = 0;
	string winclada;
	for (i=0; i<(int)tnt_format.length(); i++) {
		if (tnt_format[i] != x) {
			winclada=winclada+tnt_format[i];
		} else {
			winclada=winclada+" "+tnt_format[i]+" ";
		} 
	}
	tnt_format=winclada;
}

bool isNum(string strnum) {
	char* p;
	strtol(strnum.c_str(), &p, 10);
	return *p == 0;
}

void parse_line (int trelen) {
	// add space
	char x1 = '(', x2 = ')', x3= ',';
	add_space(x1);
	add_space(x2);
	add_space(x3);
	// use space as separator
	istringstream istr(tnt_format);
	string buffer;
	int tem;
	while (getline(istr, buffer, ' ')) {
		istr >> buffer;
		if(isNum(buffer)){
			tem = stoi(buffer)-1;
			buffer = to_string(tem);
		}
		winclada_format=winclada_format+buffer;
	}
}

void write_winclada() {
	ofstream outputFile(outputFileName);
	if (outputFile.is_open()) {
		outputFile << "tread" << endl;
		outputFile << winclada_format << endl;
		outputFile << "proc-;" ;
	} else {
		cout << "File can't be written" << endl;
	}
	outputFile.close();
}

int main (int argc, char **argv){
	argument(argc, argv);
	int trelen;
	trelen = read_tnt();
	parse_line(trelen);
	write_winclada();
	return 0;
}

/*
	Author - Ryan Beck
	Version - 1.0
	Date - 9/16/2019
	PA2 now reads input from a file and prints it to the prompt with a certain format.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <vector>
#include <iomanip>
#include "FileReader.h"
#include "DataParser.h"
using namespace std;

int main()
{
	try {
		// temporary name for the input file
		string temp_file;
		// temporary name for the new output file
		string new_name;
		// first letter of color to remove
		char color_to_remove = 'r';

		//Prompt user for input file
		cout << "Please enter source file name: ";
		cin >> temp_file;
		cout << endl;

		//Prompt user for color to remove
		cout << "Please enter a color to remove\n"
			<< "(Choices are r, g, b.): ";
		cin >> color_to_remove;

		//Prompt user for new file name
		cout << "Please enter what you want your new file to be named" <<
			endl << "(We only save as .ppm.)";
		cin >> new_name;

		// get the lines from the file into a vector
		vector<string> lines = file_reader(temp_file);

		//Error check
		if (lines.size() == 0) {
			throw "File was not found.";
		}else if (color_to_remove == ' ') {
			throw "No color selected";
		}

		/*for (int i = 0; i < lines.size(); i++) {
			cout << lines[i] << endl;
		}*/

		//Edit the data lines to remove a color r = red, g = green, b = blue
		DataParser(lines, color_to_remove);

		/*for (int i = 0; i < lines.size(); i++) {
			cout << lines[i] << endl;
		}*/

		//write every line by each line to a new file name given by the user
		ofstream save_As{ new_name };
		for (int i = 0; i < lines.size(); i++) {

			save_As << lines[i] << endl;
		}
		save_As.close();

		return 0;

	}

	//catches all of my errors 
	catch (const char* msg) {
		cerr << msg << endl;
	}
}



	

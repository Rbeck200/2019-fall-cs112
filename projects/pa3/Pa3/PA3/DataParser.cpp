#include "DataParser.h"
using namespace std;

void DataParser(vector<string>& vect, const char& remove_Color) {

	vector<int> data{};
	try {

		//check to see if the vector hass been passed successfully
		if (vect.size() == 0) {
			throw "Vector was not passed";
		}
		else {

			for (size_t i = 3; i < vect.size(); i++) {

				int _counter = 0;
				string _new_line;

				istringstream line{ vect[i] };
				while (line.good() == true) {

					string temp;
					getline(line, temp, ' ');

					//if nothing in temp or if space
					if (temp.length() == 0 || temp == " ") {

					}else{


						//switch case to remove color based on modulo result
						// 'r' = remainder 0
						// 'g' = remainder 1 
						// 'b' = remainder 2
						switch (remove_Color) {
						case 'r' :{
								if (_counter % 3 == 0) {

									temp = "0";
								}
							}
								  break;

						case 'g':{
							if (_counter % 3 == 1) {

								temp = "0";
							}
						}
								 break;

						case 'b': {
							if (_counter % 3 == 2) {

								temp = "0";
							}
						}
								  break;
							
						}
						_counter++;
						temp += " ";
						_new_line += temp;
					}

					
					//data.push_back(stoi(temp));
					
				}
				vect[i] = _new_line;
			}

		}
	
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	
}
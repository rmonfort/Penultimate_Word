#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::getline;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line, word;
	vector<string> bunch_of_words;

	// Retrive a line from input file
	while (getline(ifs, line))
	{
		istringstream iss(line);

		// Break line into words and load into vector
		while (iss >> word)
		{
			bunch_of_words.push_back(word);
		}

		// Check for proper size and skip sentences with only one word
		if (bunch_of_words.size() >= 2)
		{
			bunch_of_words.pop_back(); // Remove last element in vector
			cout << bunch_of_words.back() << endl; // Print new last element
		}

		//Clear vector
		bunch_of_words.clear();
	}

	return 0;
}
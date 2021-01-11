
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

// All letters to lowercase.
std::string toLower(std::string input) {
	// convert string to lower case
	int toLower(int c);
	std::for_each(input.begin(), input.end(), [](char& c) {
		c = ::tolower(c);
		});
	return input;
}

std::vector<std::string> findWord(std::vector<std::string>* data, std::string input) {
	std::vector<std::string> output;
	int wordNumber = 1;
	for (int i = 0; i < (*data).size(); i++) {
		size_t found = (*data)[i].find(input);
		if (found != std::string::npos) {
			printf("Found word %d: %s\n", wordNumber, (*data)[i].c_str());
			output.push_back((*data)[i]);
			wordNumber++;
		}
	}
	printf("\n");
	return output;
}

void setWord(std::vector<std::string>* data, std::string word) {
	word = toLower(word);
	(*data).push_back(word);
}

// Removes all names from the vector, after confirming.
void initialiseDatabase(std::vector<std::string>* data) {
	bool input;
	printf("\nAre you sure you want to delete all data?\n1: Yes\n0: No\nInput: ");
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (input)
	{
	case 0:
		printf("Aborting operation\n");
		break;
	case 1:
		printf("Deleting data\n");
		(*data).clear();
		printf("Done\n");
		break;
	default:
		printf("Invalid value\n");
		break;
	}
}

// Incert a new value to the vector.
void insert(std::vector<std::string>* data) {
	std::string word;
	printf("Write a word: ");
	std::getline(std::cin, word);
	word = toLower(word);
	(*data).push_back(word);
}

// Print all values containing the incerted string.
void search(std::vector<std::string>* data) {
	std::string word;
	printf("Search: ");
	std::getline(std::cin, word);
	word = toLower(word);
	findWord(data, word);
}

// Deletes the incerted value from the vector if found.
void deleteVal(std::vector<std::string>* data) {
	std::string word;
	int input;
	printf("Search word to delete: ");
	std::getline(std::cin, word);
	word = toLower(word);

	std::vector<std::string> targets = findWord(data, word);
	printf("Write the number of the word to delete: ");
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < (*data).size(); i++) {
		if ((*data)[i] == targets[input - 1])
			(*data).erase((*data).begin() + i);
	}
}

// Prints the contents of the vector.
void print(std::vector<std::string>* data) {
	for (int i = 0; i < (*data).size(); i++) {
		printf("\n%s", (*data)[i].c_str());
	}
	printf("\n");
}

void save(std::vector<std::string>* data) {
	std::ofstream fout;
	fout.open("saveData.txt", std::ios::out);
	if (fout.is_open()) {
		printf("\nSaving data\n");
		for (int i = 0; i < data->size(); i++) {
			fout << (*data)[i];
			fout << "\n";
		}
		fout.close();
		printf("Saving DONE\n");
	}
}

void load(std::vector<std::string>* data) {
	data->clear();
	std::fstream fin;
	fin.open("saveData.txt", std::ios::in);
	if (fin.is_open()) {
		printf("\nLoading data\n");
		int index = 0;
		while (!fin.eof()) {
			std::string text;
			std::getline(fin, text);
			data->push_back(text);
		}
		printf("Loading DONE\n");
	}
}

void menuLoop(std::vector<std::string>* data) {
	char input;
	bool programOn = true;
	while (programOn) {
		printf("\nMenu\n\n1: Initialise Database\n2: Insert\n3: Search\n4: Delete\n5: Print\n6: Save\n7: Load\n0: QUIT\n\nInput: ");
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (input)
		{
		case '1':
			initialiseDatabase(data);
			break;
		case '2':
			insert(data);
			break;
		case '3':
			search(data);
			break;
		case '4':
			deleteVal(data);
			break;
		case '5':
			print(data);
			break;
		case '6':
			save(data);
			break;
		case '7':
			load(data);
			break;
		case '0':
			printf("\nGood Bye\n");
			programOn = false;
			break;
		default:
			printf("Invalid value\n");
			break;
		}
	}
}

int main(void) {
	std::vector<std::string> *data = new std::vector<std::string>();
	setWord(data, "teemu");
	setWord(data, "teppo");
	setWord(data, "kalle");
	setWord(data, "en kort mening");
	menuLoop(data);
}
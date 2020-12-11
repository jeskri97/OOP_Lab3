
#include <iostream>

void replaceChars(char* arr, char search, char replace) {
	int index = 0;
	while (*(arr + index) != '\0') {
		if (*(arr + index) == search) {
			*(arr + index) = replace;
		}
		index++;
	}
}

int main(void) {
	char arr[100], search, replace;
	char* ptr = arr;
	printf("Write a string: ");
	std::cin.getline(arr, 100);
	//printf("%s", arr);
	printf("Letter to replace: ");
	std::cin >> search;
	//printf("%c", search);
	printf("Replacement letter: ");
	std::cin >> replace;
	//printf("%c", replace);

	replaceChars(ptr, search, replace);
	printf("\nResult: %s", arr);
}
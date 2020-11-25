
#include <iostream>

int strLen(char *charStr) {
	int len = 0;
	while (*(charStr + len) != '\0') {
		len++;
	}
	return len;
}

int main(void) {
	char arr[] = "This isn't a word";
	char* ptr = arr;
	int len = strLen(ptr);
	printf("\nString Lenght is %d\n", len);
}
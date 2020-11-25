
#include <iostream>

void swapSortPtr(int *a, int *b, int *c, bool acending) {

}

int main(void) {
	int num1, num2, num3;
	bool ascend;

	printf("(Write 0 to end)\nNumber 1: ");
	std::cin >> num1;
	if (num1 == 0) {
		printf("Bye Bye\n");
		return 0;
	}
	printf("Number 2: ");
	std::cin >> num2;
	printf("Number 3: ");
	std::cin >> num3;
	printf("Ascending or Descending (1/0): ");
	std::cin >> ascend;
}
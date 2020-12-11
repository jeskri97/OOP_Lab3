
#include <iostream>

void swapSortPtr(int *a, int *b, int *c, bool ascending) {
	if (ascending) {
		// smallest to biggest
		// 1 2 3
		if (*a > *c) {
			int temp = *a;
			*a = *c;
			*c = temp;
		}
		if (*b < *a) {
			int temp = *b;
			*b = *a;
			*a = temp;
		}
		if (*b > *c) {
			int temp = *b;
			*b = *c;
			*c = temp;
		}
	}
	else {
		// Biggest to smallest
		// 3 2 1
		if (*a < *c) {
			int temp = *a;
			*a = *c;
			*c = temp;
		}
		if (*b > *a) {
			int temp = *b;
			*b = *a;
			*a = temp;
		}
		if (*b < *c) {
			int temp = *b;
			*b = *c;
			*c = temp;
		}
	}
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

	swapSortPtr(&num1, &num2, &num3, ascend);

	printf("\n%d %d %d\n", num1, num2, num3);
}
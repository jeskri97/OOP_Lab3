
#include <iostream>

int averageSalary(int *salaryArr, int employees) {
	int totalSal = 0;

	for (int i = 0; i < employees; i++) {
		totalSal += *(salaryArr + i);
	}

	return totalSal / employees;
}

int main(void) {
	int arr[100];
	int *ptr = arr;
	int employees;
	printf("How many employees: ");
	std::cin >> employees;
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < employees; i++) {
		int salary;
		printf("Salary for employee %d: ", i + 1);
		std::cin >> salary;
		*(ptr + i) = salary;
	}
	int averageSal = averageSalary(ptr, employees);
	printf("\nAverage Salary is: %d\n", averageSal);
}
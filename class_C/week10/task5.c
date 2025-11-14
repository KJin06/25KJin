#include <stdio.h>

int sumArray(int* arr, int len) {
	int result = 0;

	for (int i = 0; i < len; i++) {
		result += arr[i];
	}

	return result;
}

int main() {
	int data[5] = { 10, 20, 30, 40, 50 };
	
	int result = sumArray(data, 5);

	printf("[ 배열 요소의 합 ] : %d\n", result);

	return 0;
}
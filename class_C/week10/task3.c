#include <stdio.h>

int main() {
	int input_arr[10];
	int result_arr[10];
	int even = 9, odd = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &input_arr[i]);
	}
	for (int i = 0; i < 10; i++) {
		if (input_arr[i] % 2 == 1) {
			result_arr[odd] = input_arr[i];
			odd++;
		}
		else {
			result_arr[even] = input_arr[i];
			even--;
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", result_arr[i]);
	}
}
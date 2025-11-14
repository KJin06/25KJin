#include <stdio.h>

void even(int*arr) {
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] % 2 == 0) printf("%d ", arr[i]);
	}
	printf("\n");
}

void odd(int* arr) {
	for (int i = 0; i < 10; i++) {
		if (arr[i] % 2 == 1) printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
	printf("[ 홀수 ] : ");
	odd(arr);
	printf("[ 짝수 ] : ");
	even(arr);
	return 0;
}

#include <stdio.h>

void inputArray(int* arr, int n) {
	printf("[ input array ] : ");
	for (int i = 0; i < n; i++) {
		scanf("%d", (arr + i));
	}
}

void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

int sumArray(int* arr, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

int maxValue(int* arr, int n) {
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i + 1] > arr[i]) {
			max = arr[i + 1];
		}
	}
	return max;
}

void doubleVlues(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] * 2;
	}
}

int main() {
	int arr[30];
	int n;

	printf("배열의 크기 입력 : ");
	scanf("%d", &n);

	inputArray(arr, n);

	printf("\n[ 배열 출력 ] : ");
	printArray(arr, n);

	int sum = sumArray(arr, n);
	printf("\n배열의 합 : %d\n", sum);

	int max = maxValue(arr, n);
	printf("최댓값 : %d\n", max);

	printf("\n[ 배열의 값 2배로 변경 ] : ");
	doubleVlues(arr, n);
	printArray(arr, n);

	return 0;
}
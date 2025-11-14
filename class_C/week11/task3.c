//버블정렬

#include <stdio.h>

int* sort(int* array) {
	for (int i = (10 - 1); i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
	return array;
}

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(&arr);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
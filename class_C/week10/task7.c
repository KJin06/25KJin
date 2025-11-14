#include <stdio.h>

void getStats(int * arr, int len, double *result) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i];
	}
	*result = sum / (double)len;
}

int main() {
	int scores[4] = { 70, 80, 90, 100 };
	double avg;

	getStats(scores, 4, &avg);

	printf("점수 평군 : %.2f\n", avg);

	return 0;
}
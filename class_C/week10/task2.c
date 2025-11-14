#include <stdio.h>

double by(int n) {
	int tmp = n % 2;
	if (n == 1) {
		return 1;
	}
	return (by(n / 2) * 10 + tmp);
}

int main() {
	int num;
	scanf("%d", &num);
	double result = by(num);
	printf("%.0lf", result);
	return 0;
}
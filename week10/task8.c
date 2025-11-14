#include <stdio.h>

void charUpper(char* str) {
	for (int i = 0; *(str + i) != '\0'; i++)
	{
		if (*(str + i) >= 97 && *(str + i) <= 122) {
			*(str + i) = *(str + i) - 32;
		}
		printf("%c", *(str + i));
	}
}
void charLower(char* str) {
	for (int i = 0; *(str + i) != '\0'; i++)
	{
		if (*(str + i) >= 65 && *(str + i) <= 90) {
			*(str + i) = *(str + i) + 32;
		}
		printf("%c", *(str + i));
	}
}

int main() {

	char str[30] = "Hello Hi Everyone";

	charUpper(str);
	printf("\n");
	charLower(str);

	return 0;
}
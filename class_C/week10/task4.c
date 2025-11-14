#include <stdio.h>
#define MAX 100

int main() {
    char arr[MAX];
    int len = 0, TorF = 0;
    printf("[ 문자열 입력 ] : ");
    scanf("%s", arr);
    for (int i = 0; arr[i] != '\0'; i++) {
        len++;
    }
    len--;
    for (int i = 0; i <= len/2; i++)
    {
        if (arr[i] != arr[len - i]) TorF = 1;
    }
    if (TorF == 0) printf("회문입니다.");
}

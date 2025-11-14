#include <stdio.h>

int main() {
    int sum=0, num;
    scanf("%d", &num);
    while (num != 0) {
        sum += num%10;
        num = num/10;
    }
    printf("%d", sum);
    return 0;
}
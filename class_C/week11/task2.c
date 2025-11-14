#include <stdio.h>

int isPerfectNumber(int n) {
    int k = 0;
    for (int j = n-1; j > 0; j--)
    {
        if (n % j == 0){
            k += j;
        }
    }
    if(k == n) return n;
    else return 0;
}

int main() {
    for( int i = 1; i < 1001; i++)
    if( isPerfectNumber(i) ) {
        printf("%d ", i);
    }
}

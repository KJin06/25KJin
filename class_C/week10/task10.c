#include <stdio.h>
#define MAX 10
#define LEN 50

void inputStrings(char buf[MAX][LEN], char* arr[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("[ 문자열 입력 %d ] : ", (i+1));
        scanf("%s", &buf[i][LEN]);
        arr[i] = &buf[i][LEN];
    }
}

void printStrings(char *arr[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
}

int findLongest(char* arr[MAX], int n) {
    int maxLen = 0;
    int idx = 0;
    int len = 0;
    for (int i = 0; i < n; i++) {
        len = 0;
        for (int j = 0; arr[i][j] != '\0'; j++) {
            len++;
        }
        if (maxLen < len) {
            maxLen = len;
            idx = i;
        }
    }
    return idx;
}

int main() {
    int n;

    printf("[ 문자열 개수 입력 ] : ");
    scanf("%d", &n);

    // 1차원 배열만 사용: 문자열 저장 버퍼
    static char strBuf[MAX][LEN];   // 실제 문자열 저장소
    char* arr[MAX];                 // 문자열을 가리키는 포인터 배열(1차원)

    inputStrings(strBuf, arr, n);

    printf("\n[ 문자열 출력 ] : ");
    printStrings(arr, n);

    int idx = findLongest(arr, n);
    printf("\n\n[ 가장 긴 문자열 ] : %s\n", arr[idx]);


    return 0;
}

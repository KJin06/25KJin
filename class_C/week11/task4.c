//퍼즐

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void arrayPrint(int[3][3]);
void arrayReturn(int arr[3][3], int byte2, int a, int b);

int main() {
    int arr[3][3] = { 0, };

    int count = 1;
    int result[9][2];
    int len = 0;
    int byte1, byte2;
    int nain[2];
    int TorF = 1;

    while (count <= 9) {
        for (int i = 0; i < 9; i++)
        {
            result[i][0] = 0;
            result[i][1] = 0;
        }
        len = 0;

        srand(time(NULL));

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] == 0) {
                    result[len][0] = i;
                    result[len][1] = j;
                    len++;
                }
            }
        }

        int tmp = rand() % len;

        int a = result[tmp][0];
        int b = result[tmp][1];
        arr[a][b] = count;
        count++;

    }
    
    arrayPrint(arr);

    while (1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] == 9) {
                    nain[0] = i;
                    nain[1] = j;
                }
            }
        }

        byte1 = _getch();
        byte2 = _getch();

        //printf("%d\n", byte2);

        int a = nain[0];
        int b = nain[1];
        TorF = 0;

        arrayReturn(&arr, byte2, a, b);

        arrayPrint(arr);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                if (arr[i][j] == TorF) TorF++;
            }
        }
        if (TorF == 8) printf("your win!!");

    }//while
    
}//main

void arrayPrint(int arr[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] != 9) printf("%3d", arr[i][j]);
            else printf("%3d", 0);
        }
        printf("\n");
    }
}

void arrayReturn(int arr[3][3], int byte2, int a, int b) {
    int tmp = 0;
    switch (byte2) {
        //up
    case 72:
        if ((a - 1) >= 0) {
            tmp = arr[a - 1][b];
            arr[a - 1][b] = arr[a][b];
            arr[a][b] = tmp;
        }
        else;
        break;

        //down
    case 80:
        if ((a + 1) <= 2) {
            tmp = arr[a + 1][b];
            arr[a + 1][b] = arr[a][b];
            arr[a][b] = tmp;
        }
        else;
        break;

        //right
    case 77:
        if ((b + 1) <= 2) {
            tmp = arr[a][b + 1];
            arr[a][b + 1] = arr[a][b];
            arr[a][b] = tmp;
        }
        else;
        break;

        //left
    case 75:
        if ((b - 1) >= 0) {
            tmp = arr[a][b - 1];
            arr[a][b - 1] = arr[a][b];
            arr[a][b] = tmp;
        }
        break;
    }
}
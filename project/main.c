#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "ingame.h"

// 한컴타자 게임 만들기

typedef struct People {
	char name[20];
	int score;
	int num;
}people;

int guestOfNum = 0;
int inGame(people** player);
int is_guestName(people** ptr, int num, char name[20]);

int inGame(people** player) {
	int choiceMenu;
	printf("\n\n");
	for (int i = 0; i < 45; i++) {
		printf("=");
	}printf("\n");
	printf("%26s\n", "init play");
	for (int i = 0; i < 45; i++) {
		printf("=");
	}printf("\n");printf("\n");

	printf("%31s\n", "1. 애국가");
	printf("%31s\n", "2. 껍대기는 가라 - 신");
	printf("%26s\n", "3. 빈집 - 기형도");
	printf("%26s\n", "4. 혼자 가는 먼 집 - 허수경");
	printf("%26s\n\n", "5. exit");

	for (int i = 0; i < 45; i++) {
		printf("=");
	}printf("\n");

	printf("[ choice menu ] : ");
	scanf("%d", &choiceMenu);
	return choiceMenu;
}

int readyPlay() {
	int choiceMenu = 0;

	printf("\n\n");
	for (int i = 0; i < 45; i++) {
		printf("=");
	}printf("\n");
	printf("%26s\n", "init play");
	for (int i = 0; i < 45; i++) {
		printf("=");
	}
	printf("\n");
	printf("\n");

	printf("%31s\n", "1. guest game player");
	printf("%31s\n", "2. view game player");
	printf("%26s\n", "3. sign up");
	printf("%26s\n", "4. sign in");
	printf("%26s\n\n", "5. exit");

	for (int i = 0; i < 45; i++) {
		printf("=");
	}printf("\n");

	printf("[ choice menu ] : ");
	scanf("%d", &choiceMenu);
	return choiceMenu;
}//readyPlay

int guestPlayerAdd(people** ptr, int num) {
	char tmp[20];
	people* tmp_ = *ptr;
	*(ptr + num) = (people*)malloc((sizeof(people)) + 1);
	(*ptr + num)->num = num + 1 + 100;
	printf("[ input guest name ] : ");
	scanf("%s", tmp);
	if (is_guestName(ptr, num, tmp) == 1) {
		return 0;
	}

	strcpy((*ptr + num)->name, tmp);
	(*ptr + num)->score = 0;
	return 1;
}//playerAdd

int is_guestName(people** ptr, int num, char name[20]) {
	for (int i = 0; i < num; i++) {
		if (strcmp((*ptr + i)->name, name) == 0) {
			printf("[ system ] : \"%s\" is already exist", name);
			return 1;
		}
	}
	return 0;
}

int find_guestName(people** ptr, int num, char name[20], people ** player) {
	char message[100] = "loading...";
	int nameFlag = 0;
	printf("\n[ system ] : ");
	for (int i = 0; message[i] != '\0'; i++) {
		printf("%c", message[i]);
		Sleep(500);
	}
	printf("\n");
	printf("[ system ] : ");
	for (int i = 0; i < guestOfNum; i++) {
		if (strcmp((*ptr + i)->name, name) == 0 && nameFlag == 0) {

			*player = malloc(sizeof(people) + 1);
			strcpy((*player)->name, name);
			(*player)->score = 0;
			(*player)->num = i + 100 + 1;

			strcpy(message, "welcome guest, ");
			strcat(message, (*ptr + i)->name);
			for (int j = 0; message[j] != '\0'; j++) {
				printf("%c", message[j]);
				Sleep(100);
			}
			
			return 1;
		}
	}
	strcpy(message, "not found your name");
	for (int j = 0; message[j] != '\0'; j++) {
		printf("%c", message[j]);
		Sleep(100);
	}
	return 0;
}

int playerSignUp() {
	FILE* file, * memberCount_file;
	char id[20], pw[20], name[20], tmp[20];
	int score = 0, num = 0;
	file = fopen("text.txt", "a");
	memberCount_file = fopen("member_count.txt", "r");

	if (file != NULL) {
		fscanf(memberCount_file, "%d", &num);
		num++;
		fclose(memberCount_file);
		memberCount_file = NULL;

		printf("[ ID ] : ");
		scanf("%s", id);
		fprintf(file, "id %s\n", id);

		printf("[ PW ] : ");
		scanf("%s", pw);
		fprintf(file, "pw %s\n", pw);

		printf("[ NAME ] : ");
		scanf("%s", name);
		fprintf(file, "name %s\n", name);

		fprintf(file, "score %d\n", score);
		fprintf(file, "num %d\n\n", num+200);
		fclose(file);

		memberCount_file = fopen("member_count.txt", "w");
		fprintf(memberCount_file, "%d", num);
		fclose(memberCount_file);
	}
}//singUp

int find_memberInfo(char inputId[20], char inputPw[20], people** player) {
	enum { ID = 1, PW, NAME };
	FILE* file, * member;
	int num, tmpInt, score, status = 0, memberNumber;
	char tmpStr[20], id[20], pw[20], name[20], message[100] = { '\0' };
	char playerId[20] = { '\0' }, playerPw[20] = { '\0' };
	file = fopen("text.txt", "r");
	member = fopen("member_count.txt", "r");
	fscanf(member, "%d", &num);
	printf("\n[ system ] : ");
	strcpy(message, "loading...");
	for (int i = 0; message[i] != '\0'; i++) {
		printf("%c", message[i]);
		Sleep(500);
	}
	for (int i = 0; i < num; i++) {
		fscanf(file, "%s %s", tmpStr, id);
		fscanf(file, "%s %s", tmpStr, pw);
		fscanf(file, "%s %s", tmpStr, name);
		fscanf(file, "%s %d", tmpStr, &score);
		fscanf(file, "%s %d", tmpStr, &memberNumber);

		if (strcmp(inputId, id) == 0) {
			status = 1;
			break;
		}
	}
	if (status == 0) {
		printf("\n[ system ] : ");
		strcpy(message, "not found your id \" ");
		strcat(message, inputId);
		strcat(message, " \"\n");
		for (int j = 0; message[j] != '\0'; j++) {
			printf("%c", message[j]);
			Sleep(100);
		}
		return 0;
	}
	else {
		if (strcmp(inputPw, pw) == 0) {
			printf("\n[ system ] : ");
			strcpy(message, "welcome member, ");
			strcat(message, name);
			strcat(message, "\0");
			for (int j = 0; message[j] != '\0'; j++) {
				printf("%c", message[j]);
				Sleep(100);
			}
			*player = malloc(sizeof(people) + 1);
			strcpy((*player)->name, name);
			(*player)->score = score;
			(*player)->num = memberNumber;
			return 1;
		}
		else {
			printf("\n[ system ] : ");
			strcpy(message, "password is incorrect\n");
			for (int j = 0; message[j] != '\0'; j++) {
				printf("%c", message[j]);
				Sleep(100);
			}
			return 0;
		}
	}
}

int playerSignIn(people** ptr, people** player) {
	FILE* file, * memberCount_file;
	char id[20], pw[20], name[20], tmp[20], userType, guestName[20];
	int status = -1;
	char message[20] = "Loading...";
	file = fopen("text.txt", "a");
	memberCount_file = fopen("member_count.txt", "r");

	printf("[ guest input G, member input M ] : ");
	scanf(" %c", &userType);
	if (userType == 'G')
	{
		printf("[ NAME ] : ");
		scanf("%s", guestName);
		if (find_guestName(ptr, guestOfNum, guestName, player) == 1) {
			return 2;
		}
		
	}
	else if (userType == 'M') {
		printf("[ ID ] : ");
		scanf("%s", id);
		printf("[ PW ] : ");
		scanf("%s", pw);
		if (find_memberInfo(id, pw, player) == 1) {
			return 2;
		}
		else {
			printf("[ systmp ] : please guest or member sign in");
			return 1;
		}
	}
}

void print(int fir, int playerNum) {
	fir++;
	FILE* file, * member;
	char tmp[10], id[20], pw[20], name[20];
	int length = 0, score, num;
	file = fopen("text.txt", "r");
	member = fopen("member_count.txt", "r");
	fscanf(member, "%d", &length);
	for (int i = 0; i < length; i++) {
		fscanf(file, "%s %s", tmp, id);
		fscanf(file, "%s %s", tmp, pw);
		fscanf(file, "%s %s", tmp, name);
		fscanf(file, "%s %d", tmp, &score);
		fscanf(file, "%s %d", tmp, &num);
		if (playerNum != num) printf("  %-10d%-30s%-20d\n", num, name, score);
	}
	fclose(file);
	fclose(member);
}

int playerPrint(people** ptr, int num, people** player) {
	int fir = 0;

	printf("\n\n");
	for (int i = 0; i < 55; i++) {
		printf("=");
	}printf("\n");

	printf("%32s\n", "info player");
	for (int i = 0; i < 55; i++) {
		printf("-");
	}printf("\n");

	printf("  %-10s%-30s%-20s\n", "n.", "name", "score");
	for (int i = 0; i < 55; i++) {
		printf("-");
	}printf("\n");

	if (*player != '\0') {
		printf("  %-10d%-30s%-20d\n", (*player)->num, (*player)->name, (*player)->score);
		for (int i = 0; i < 55; i++) {
			printf("-");
		}
		printf("\n");
		for (; fir < num; fir++) {
			if ((*player)->num != (*ptr + fir)->num) {
				printf("  %-10d", (*ptr + fir)->num);
				printf("%-30s", (*ptr + fir)->name);
				printf("%-20d\n", (*ptr + fir)->score);
			}
		}
	}
	else {
		for (; fir < num; fir++) {
			printf("  %-10d", (*ptr + fir)->num);
			printf("%-30s", (*ptr + fir)->name);
			printf("%-20d\n", (*ptr + fir)->score);
		}
	}
	print(fir, (*player)->num);

}//playerPrint

int num = 0;


int main() {
	people* guest;
	people* player = '\0';
	static int roop = 1;
	while (roop) {
		if(roop == 1)
		{
			switch (readyPlay()) {
			case 1:
				guestOfNum += guestPlayerAdd(&guest, guestOfNum);
				break;
			case 2:
				playerPrint(&guest, guestOfNum, &player);
				break;
			case 3:
				playerSignUp();
				break;
			case 4:
				roop = playerSignIn(&guest, &player);
				break;
			case 5:
				exit(0);
				break;
						}
		}
		else if (roop == 2) {
			int menu = inGame(player);
			int result = 0;
			result = playGame(menu, &player);
			if (result == -1) {
				for (int i = 0; i < guestOfNum; i++) {
					if ((guest+ i)->num == player->num) {
						(guest + i)->score = player->score;
					}
				}
				roop = 1;
			}
			else {
				player->score += result;
			}
		}
	}
}
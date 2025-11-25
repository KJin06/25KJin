#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 한컴타자 게임 만들기

typedef struct Peple {
	char name[20];
	int score;
	int num;
}peple;

int readyPlay() {
	int choiceMenu = 0;

	printf("\n\n");
	for (int i = 0; i < 45; i++) {
		printf("=");
	}printf("\n");
	printf("%26s\n", "init play");
	for (int i = 0; i < 45; i++) {
		printf("=");
	}printf("\n");printf("\n");

	printf("%31s\n", "1. guest game player");
	printf("%31s\n", "2. view game player");
	printf("%26s\n", "3. sign up");
	printf("%26s\n", "4. sign in");
	printf("%26s\n\n", "5. sign out");

	for (int i = 0; i < 45; i++) {
		printf("=");
	}printf("\n");


	
	printf("[ choice menu ] : ");
	scanf("%d", &choiceMenu);
	return choiceMenu;
}//readyPlay

int guestPlayerAdd(peple** ptr, int num) {
	char tmp[20];
	peple* tmp_ = *ptr;
	int tmp_num;
	printf("\n\n[ input Number of player ] : ");
	scanf("%d", &tmp_num);
	*(ptr + num) = (peple*)malloc((sizeof(peple) * tmp_num) + 1);
	for (int i = 0 ; i < tmp_num; i++) {
		(*ptr + (num + i))->num = (num + i);
		printf("[ player %d name ] : ", i);
		scanf("%s", tmp);
		strcpy((*ptr + (num + i))->name, tmp);
		(*ptr + (num + i))->score = 0;
	}
	return tmp_num;
}//playerAdd

int playerSignUp() {
	FILE* file, *memberCount_file;
	char id[20], pw[20], name[20], tmp[20];
	int score = 0, num = 0;
	file = fopen("text.txt", "a");
	memberCount_file = fopen("member_count.txt", "r");
	if (file != NULL) {		
		fscanf(memberCount_file, "%d", &num);
		num++;
		fclose(memberCount_file);
		memberCount_file = NULL;
		memberCount_file = fopen("member_count.txt", "w");
		fprintf(memberCount_file, "%d", num);
		fclose(memberCount_file);
		
		printf("[ ID ] : ");
		scanf("%s", id);
		fprintf(file, "id %s\n", id);

		printf("[ PW ] : ");
		scanf("%s", pw);
		fprintf(file, "pw %s\n", pw);

		printf("[ NAME ] : ");
		scanf("%s", name);
		fprintf(file, "name %s\n", name);

		fprintf(file, "score %d\n\n", score);
		fclose(file);
	}
}//singUp

void playerSignIn() {
	FILE* file, *memberCount_file;
	char id[20], pw[20], name[20], tmp[20], userType, guestName[20];
	file = fopen("text.txt", "a");
	memberCount_file = fopen("member_count.txt", "r");

	printf("[ guest input G, member input M ] : ");
	scanf(" %c", &userType);
	if (userType == 'G')
	{
		printf("[ NAME ] : ");
		scanf("%s", guestName);
	}
	else if (userType == 'M') {
		printf("[ ID ] : ");
		scanf("%s", id);
		printf("[ PW ] : ");
		scanf("%s", pw);
	}
}

void print(int fir) {
	FILE* file, *member;
	char tmp[10], id[20], pw[20], name[20];
	int length = 0, score;
	file = fopen("text.txt", "r");
	member = fopen("member_count.txt", "r");
	fscanf(member, "%d", &length);
	for (int i = 0; i < length; i++) {
		fscanf(file, "%s %s", tmp, id);
		fscanf(file, "%s %s", tmp, pw);
		fscanf(file, "%s %s", tmp, name);
		fscanf(file, "%s %d", tmp, &score);
		printf("  %-10d%-30s%-20d\n", fir+i, name, score);
	}
	fclose(file);
	fclose(member);
}

int playerPrint(peple** ptr, int num) {
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

	for (; fir < num; fir++) {
		printf("  %-10d", (*ptr + fir)->num);
		printf("%-30s", (*ptr + fir)->name);
		printf("%-20d\n", (*ptr + fir)->score);
	}

	print(fir);

}//playerPrint

peple * player;
int num = 0;
int playerOfNum = 1;

int main() {
	peple* player;
	player = malloc(sizeof(peple) + 1);
	player->num = 0;
	strcpy(player->name, "admin");
	player->score = 0;

	while (1) {
		switch (readyPlay()) {
		case 1:
			playerOfNum += guestPlayerAdd(&player, playerOfNum);
			break;
		case 2:
			playerPrint(&player, playerOfNum);
			break;
		case 3:
			playerSignUp();
			break;
		case 4:
			playerSignIn();
			break;
		case 5:
			break;
		case 6:
			exit(0);
			break;
		}
	}
	return 0;
}
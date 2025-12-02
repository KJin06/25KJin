#include <stdio.h>
#include <string.h>


FILE* file, *player_file, *member;

void findPlayer(int player);

int playGame(int menu, int player) {
	enum {애국가 = 1, 껍대기는가라, 빈집, 혼자가는먼집};
	char message[1000] = { '\0' }, input[1000];
	int tmp = 0, len = 0;
	int score = 0, perfect = 0;
	switch (menu) {
	case 애국가:
		file = fopen("n1.txt", "r");
		tmp = fgetc(file);
		len++;
		message[0] = tmp;
		while (tmp != EOF) {
			if (tmp != '\n') {
				putchar(tmp);
				tmp = fgetc(file);
				message[len] = tmp;
				len++;
			}
			else {
				getchar();
				printf("\n");
				scanf("%[^\n]s", input);
				strcat(input, "\n");
				tmp = 0;
				if (strcmp(message, input) == 0) {
					score += len;
					perfect += len;
				}
				else {
					perfect += len;
				}

				for (int i = 0; i < 1000; i++)
				{
					message[i] = '\0';
				}
				len = 0;
			}
		}//EOF
		printf("\n[ system ] : your score %d/%d", score, perfect);
		findPlayer(player);
		return score;
		break;
	case 5:
		return -1;
	}//switch
	//findPlayer((*player)->num);
}

void findPlayer(int player) {
	player_file = fopen("member_count.txt", "r");
	file = fopen("text.txt", "r");
	char score[255] = "score", *p;
	player -= 200;
	int count = 0;

	char tmp = player + 48;
	char ptr[2] = { tmp };
	
	strcat(score, ptr);
	strcat(score, "\0");

	int ofNumber = 0;
	int tempINT;
	char tempSTR[1000], playerNumber;

	fscanf(player_file, "%d", &ofNumber);

	for (int i = 0; i < (ofNumber * 6); i++)
	{
		fgets(tempSTR, 100, file);
		p = strstr(tempSTR, score);
		
	}
}
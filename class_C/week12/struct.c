#include <stdio.h>
#include <string.h>

typedef struct {
	int id;
	int pwd;
	int money;
} Account;

typedef struct Record {
	char menu[10];
	char etc[20];
	int amount;
	int balance;
}record;

Account accounts[10];
int numOfAccounts = 0;
static int loginFlag;
enum { Login = 1, Join, Exit, Print };

int printCatholicMenu() {
	int tmp;
	printf("\n--Catholic Bank--\n");
	printf("1. Login\n");
	printf("2. Join\n");
	printf("3. Exit\n");
	printf("4. PrintALL\n");
	printf("Choice> ");
	scanf("%d", &tmp);
	return tmp;
}

int login(int num) {
	int tmpID;
	int tmpPWD;
	printf("ID : ");
	scanf("%d", &tmpID);
	printf("Pwd : ");
	scanf("%d", &tmpPWD);
	for (int i = 0; i < num; i++) {
		if (accounts[i].id == tmpID) {
			if (accounts[i].pwd == tmpPWD) {
				printf("로그인 성공\n");
				loginFlag = i;
				return 1;
			}
			else {
				printf("패스워드 틀림\n");
				return 0;
			}
		}
	}
	printf("아이디가 존재하지 않습니다.\n");
	return 0;
}

int join(int num) {
	printf("ID : ");
	scanf("%d", &accounts[num].id);
	printf("Pwd : ");
	scanf("%d", &accounts[num].pwd);
	accounts[num].money = 1000;
	num++;
	printf("\n회원수 : %d\n", num);
	return num;
}

void print(int num) {
	char* tmpID = "ID";
	char* tmpPWD = "PWD";
	char* tmpMoney = "Money";
	printf("%-20s%-20s%-20s\n", tmpID, tmpPWD, tmpMoney);
	for (int i = 0; i < num; i++) {
		printf("%-20d%-20d%-20d\n", accounts[i].id, accounts[i].pwd, accounts[i].money);
	}
}

int printBankMenu() {
	int tmp;
	printf("\n\nlogin user %d", accounts[loginFlag].id);
	printf("\n--Catholic Bank--\n");
	printf("1. 입금\n");
	printf("2. 출금\n");
	printf("3. 조회\n");
	printf("4. 송금\n");
	printf("5. 로그아웃\n");
	printf("Choice> ");
	scanf("%d", &tmp);

	return tmp;
}

int bankLogin() {
	int tmp, transferID, TorF = 0, transferFlag, recordNum = 0;
	record loginRecord[10];
	char tmpList[10];
	enum { input = 1, output, inquiry, transfer, logout };
	do
	{
		TorF = 0;
		int choice = printBankMenu();
		switch (choice) {
		case input:
			printf("입금액 : ");
			scanf("%d", &tmp);
			accounts[loginFlag].money += tmp;
			strcpy(loginRecord[recordNum].menu, "input");
			loginRecord[recordNum].amount = tmp;
			loginRecord[recordNum].balance = accounts[loginFlag].money;
			strcpy(loginRecord[recordNum].etc, "-");
			recordNum++;
			break;
		case output: {
			printf("출금액 : ");
			scanf("%d", &tmp);
			if (accounts[loginFlag].money - tmp < 0) printf("출금 금액이 부족합니다.");
			else accounts[loginFlag].money -= tmp;
			strcpy(loginRecord[recordNum].menu, "output");
			loginRecord[recordNum].amount = tmp;
			loginRecord[recordNum].balance = accounts[loginFlag].money;
			strcpy(loginRecord[recordNum].etc, "-");
			recordNum++;
			break;
		}
		case inquiry: {
			printf("%-10s%-20s%-20s%-20s%-20s%\n", "n.", "menu", "amount", "balance", "etc.");
			for (int i = 0; i < recordNum; i++) {
				printf("%-10d%-20s%-20d%-20d%-20s%\n", i, loginRecord[i].menu, loginRecord[i].amount, loginRecord[i].balance, loginRecord[i].etc);
			}
			break;
		}
		case transfer: {
			printf("송금 아이디 : ");
			scanf("%d", &transferID);
			for (int i = 0; i < numOfAccounts; i++) {
				if (accounts[i].id == transferID) {
					TorF = 1;
					transferFlag = i;
				}
			}
			if (TorF == 0) {
				printf("송금 id가 존재하지 않습니다.");
				break;
			}
			printf("송금 금액 : ");
			scanf("%d", &tmp);
			if (accounts[loginFlag].money - tmp < 0) {
				printf("송금 금액이 부족합니다.");
				break;
			}
			else {
				accounts[loginFlag].money -= tmp;
				accounts[transferFlag].money += tmp;
			}
			strcpy(loginRecord[recordNum].menu, "trasfer");
			loginRecord[recordNum].amount = tmp;
			loginRecord[recordNum].balance = accounts[loginFlag].money;
			sprintf(tmpList, "%d", accounts[transferFlag].id);
			strcpy(loginRecord[recordNum].etc, tmpList);
			recordNum++;
			break;
		}
		case logout: {
			printf("\nbye %d!\n", accounts[loginFlag].id);
			return 0;
			break;
		}
		}
	} while (1);
}

int main() {
	int auth;
	do {
		int choice = printCatholicMenu();
		switch (choice) {
		case Login:
			auth = login(numOfAccounts);
			while (auth) {
				auth = bankLogin();
			}
			break;
		case Join:
			numOfAccounts = join(numOfAccounts);
			break;
		case Exit:
			printf("\nbye!\n");
			exit(0);
			break;
		case Print:
			print(numOfAccounts);
			break;
		}
	} while (1);
}
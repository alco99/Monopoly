#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h>
#include <time.h>
#include <windows.h> 

struct map_initialise {
	char name[10]; //地名 
	int own;  //有沒有人買 
	int owner;  //地主代號 
	int level;  //等級 
	int tolls;  //過路費 
	int price;  //價錢
	int original_price;
};

struct player_initialise {
	int money;  //錢
	int realty;   //玩家代號  
	int move;  //可不可以移動 
	int location;  //現在位置 
	int bankrupt; //破產狀態
	char printOnMap[24];  //顯示在地圖上
	int total;  //
};

//骰子
int dice()	 
{
	printf("\n請骰骰子\n");
	puts("");
	system("pause");
	puts("");
	srand(time(NULL)); //產生亂數，參數以目前的時間傳入
	int die = 1 + rand() % 6;//有六個數，從一開始(1~6)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
	printf("■■■■■■■\n");
	switch(die)
	{
		case 1:
			printf("■          ■\n");
			printf("■          ■\n");
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			printf("◎    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			printf("■          ■\n");
			printf("■          ■\n");
			printf("■■■■■■■\n");
			return 1;
		case 2:
			printf("■          ■\n");
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			printf("■          ■\n");
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			printf("■          ■\n");
			printf("■■■■■■■\n");
			return 2;
		case 3:
			printf("■          ■\n");
			
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■          ■\n");
			printf("■■■■■■■\n");
			return 3;
		case 4:
			printf("■          ■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■          ■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■          ■\n");
			printf("■■■■■■■\n");
			return 4;
		case 5:
			printf("■          ■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■          ■\n");
			printf("■■■■■■■\n");
			return 5;
		case 6:
			printf("■          ■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			
			printf("■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
			printf("◎  ◎  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
			printf("■\n");
			printf("■          ■\n");
			printf("■■■■■■■\n");
			return 6;
	}	
	printf("%d", die);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
}

//地圖 
void map_print(struct map_initialise map[], struct player_initialise player[])
{
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■          ■  水  星  ■  金  星  ■          ■  火  星  ■  木  星  ■  土  星  ■          ■\n");
	printf("■          ■地價:%05d■地價:%05d■          ■地價:%05d■地價:%05d■地價:%05d■          ■\n", map[1].price, map[2].price, map[4].price, map[5].price, map[6].price);
	printf("■  起  點  ■等級:L%d(%d)■等級:L%d(%d)■  機  會  ■等級:L%d(%d)■等級:L%d(%d)■等級:L%d(%d)■ 小行星帶 ■\n", map[1].level, map[1].owner, map[2].level, map[2].owner, map[4].level, map[4].owner, map[5].level, map[5].owner, map[6].level, map[6].owner);
	printf("■   →→   ■toll:%04d ■toll:%04d ■          ■toll:%04d ■toll:%04d ■toll:%04d ■          ■\n", map[1].tolls, map[2].tolls, map[4].tolls, map[5].tolls, map[6].tolls);
	printf("■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■\n", player[0].printOnMap[0], player[1].printOnMap[0], player[2].printOnMap[0], player[3].printOnMap[0], player[0].printOnMap[1], player[1].printOnMap[1], player[2].printOnMap[1], player[3].printOnMap[1], player[0].printOnMap[2], player[1].printOnMap[2], player[2].printOnMap[2], player[3].printOnMap[2], player[0].printOnMap[3], player[1].printOnMap[3], player[2].printOnMap[3], player[3].printOnMap[3], player[0].printOnMap[4], player[1].printOnMap[4], player[2].printOnMap[4], player[3].printOnMap[4], player[0].printOnMap[5], player[1].printOnMap[5], player[2].printOnMap[5], player[3].printOnMap[5], player[0].printOnMap[6], player[1].printOnMap[6], player[2].printOnMap[6], player[3].printOnMap[6], player[0].printOnMap[7], player[1].printOnMap[7], player[2].printOnMap[7], player[3].printOnMap[7]);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■  地  球  ■                                                                      ■  天王星  ■\n");
	printf("■地價:%05d■                                                                      ■地價:%05d■\n", map[23].price, map[8].price);
	printf("■等級:L%d(%d)■     press any botton to start(except 0)                              ■等級:L%d(%d)■\n", map[23].level, map[23].owner, map[8].level, map[8].owner);	
	printf("■toll:%04d ■                                                                      ■toll:%04d ■\n", map[23].tolls, map[8].tolls);	
	printf("■ %c %c %c %c  ■     @ 玩家一:目前金額%05d                                           ■ %c %c %c %c  ■\n", player[0].printOnMap[23], player[1].printOnMap[23], player[2].printOnMap[23], player[3].printOnMap[23], player[0].money, player[0].printOnMap[8], player[1].printOnMap[8], player[2].printOnMap[8], player[3].printOnMap[8]);	
	printf("■■■■■■■                                                                      ■■■■■■■\n");
	printf("■  神秘星  ■     # 玩家二:目前金額%05d                                           ■          ■\n", player[1].money);	
	printf("■地價:%05d■                                                                      ■          ■\n", map[22].price);	
	printf("■等級:L%d(%d)■     & 玩家三:目前金額%05d                                           ■  命  運  ■\n", map[22].level, map[22].owner, player[2].money);	
	printf("■toll:%04d ■                                                                      ■          ■\n", map[22].tolls);
	printf("■ %c %c %c %c  ■     $ 玩家四:目前金額%05d                                           ■ %c %c %c %c  ■\n", player[0].printOnMap[22], player[1].printOnMap[22], player[2].printOnMap[22], player[3].printOnMap[22], player[3].money, player[0].printOnMap[9], player[1].printOnMap[9], player[2].printOnMap[9], player[3].printOnMap[9]);	
	printf("■■■■■■■                                                                      ■■■■■■■\n");
	printf("■          ■                                                                      ■  海王星  ■\n");	
	printf("■          ■                                                                      ■地價:%05d■\n", map[10].price);	
	printf("■  命  運  ■                                                                      ■等級:L%d(%d)■\n", map[10].level, map[10].owner);	
	printf("■          ■                                                                      ■toll:%04d ■\n", map[10].tolls);
	printf("■ %c %c %c %c  ■                                 →Pause the game please enter 1      ■ %c %c %c %c  ■\n", player[0].printOnMap[21], player[1].printOnMap[21], player[2].printOnMap[21], player[3].printOnMap[21], player[0].printOnMap[10], player[1].printOnMap[10], player[2].printOnMap[10], player[3].printOnMap[10]);
	printf("■■■■■■■                                                                      ■■■■■■■\n");
	printf("■  旺旺星  ■                                 →Restart the game please enter 2    ■  駭客星  ■\n");
	printf("■地價:%05d■                                                                      ■地價:%05d■\n", map[20].price, map[11].price);
	printf("■等級:L%d(%d)■                                 →Want to leave please enter 0       ■等級:L%d(%d)■\n", map[20].level, map[20].owner, map[11].level, map[11].owner);
	printf("■toll:%04d ■                                                                      ■toll:%04d ■\n", map[20].tolls, map[11].tolls);
	printf("■ %c %c %c %c  ■                                                                      ■ %c %c %c %c  ■\n", player[0].printOnMap[20], player[1].printOnMap[20], player[2].printOnMap[20], player[3].printOnMap[20], player[0].printOnMap[11], player[1].printOnMap[11], player[2].printOnMap[11], player[3].printOnMap[11]);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■          ■  逢甲星  ■  美食星  ■  方塊星  ■          ■  植物星  ■  月  球  ■          ■\n");
	printf("■          ■地價:%05d■地價:%05d■地價:%05d■          ■地價:%05d■地價:%05d■          ■\n", map[18].price, map[17].price, map[16].price, map[14].price, map[13].price);
	printf("■ 太空墳場 ■等級:L%d(%d)■等級:L%d(%d)■等級:L%d(%d)■  機  會  ■等級:L%d(%d)■等級:L%d(%d)■  監  獄  ■\n", map[18].level, map[18].owner, map[17].level, map[17].owner, map[16].level, map[16].owner, map[14].level, map[14].owner, map[13].level, map[13].owner);
	printf("■          ■toll:%04d ■toll:%04d ■toll:%04d ■          ■toll:%04d ■toll:%04d ■          ■\n", map[18].tolls, map[17].tolls, map[16].tolls, map[14].tolls, map[13].tolls);
	printf("■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■ %c %c %c %c  ■\n", player[0].printOnMap[19], player[1].printOnMap[19], player[2].printOnMap[19], player[3].printOnMap[19], player[0].printOnMap[18], player[1].printOnMap[18], player[2].printOnMap[18], player[3].printOnMap[18], player[0].printOnMap[17], player[1].printOnMap[17], player[2].printOnMap[17], player[3].printOnMap[17], player[0].printOnMap[16], player[1].printOnMap[16], player[2].printOnMap[16], player[3].printOnMap[16], player[0].printOnMap[15], player[1].printOnMap[15], player[2].printOnMap[15], player[3].printOnMap[15], player[0].printOnMap[14], player[1].printOnMap[14], player[2].printOnMap[14], player[3].printOnMap[14], player[0].printOnMap[13], player[1].printOnMap[13], player[2].printOnMap[13], player[3].printOnMap[13], player[0].printOnMap[12], player[1].printOnMap[12], player[2].printOnMap[12], player[3].printOnMap[12]);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");	
}

//結束畫面
void end()
{
	char n;
	system("cls");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■               ■■■■■  ■    ■      ■■      ■    ■  ■   ■    ■■■                ■\n");
	printf("■                   ■      ■    ■     ■  ■     ■■  ■  ■ ■     ■                     ■\n");
	printf("■                   ■      ■■■■    ■■■■    ■ ■ ■  ■■       ■■■                ■\n");	
	printf("■                   ■      ■    ■   ■      ■   ■  ■■  ■  ■          ■               ■\n");
	printf("■                   ■      ■    ■  ■        ■  ■   ■   ■    ■   ■■■                ■\n");	
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■          	                                                                                ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                  ■■■    ■■    ■■■■                                  ■\n");
	printf("■                                  ■      ■    ■  ■     ■                                 ■\n");
	printf("■                                  ■■■  ■    ■  ■■■■                                  ■\n");
	printf("■                                  ■      ■    ■  ■  ■                                    ■\n");
	printf("■                                  ■        ■■    ■    ■                                  ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■           ■■■   ■          ■■      ■    ■  ■■■■■   ■   ■   ■■■             ■\n");
	printf("■          ■    ■  ■         ■  ■      ■  ■       ■      ■■  ■  ■                  ■\n");
	printf("■           ■■■   ■        ■■■■      ■■        ■      ■ ■ ■  ■   ■■           ■\n");
	printf("■          ■        ■       ■      ■      ■         ■      ■  ■■  ■    ■■          ■\n");
	printf("■          ■        ■■■  ■        ■     ■     ■■■■■  ■   ■    ■■■ ■          ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■                                                                                              ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	scanf("%*c");
		exit(0);
}

struct player_initialise chance(struct player_initialise player[],int i){
	printf("\n");
	printf("+--------+\n");
	printf("|        |\n");
	printf("|   機   |\n");
	printf("|        |\n");
	printf("|   會   |\n");
	printf("|        |\n");		
	printf("+--------+\n");
	system("pause");
	int num;
	srand(time(NULL));
	num = rand() % 3 + 1;	//編號 (1-3)
	switch(num){
		case 1:
			printf("\n內容: 骰到 3 以上的的數字獲得 2000 元\n");
			if(dice() >= 3){
				player[i].money = player[i].money + 2000;
			}
			break;
		case 2:
			printf("\n內容: 支付太空船燃料費用 1000 元\n");
			player[i].money = player[i].money - 1000;
			break;
		case 3:
			printf("\n內容: 投資股票獲利，獲得 1000 元\n");
			player[i].money = player[i].money + 1000;
			break;		
	}
	printf("\n");
	return 	player[i];	
}

struct player_initialise fate(struct player_initialise player[],int i){
	printf("\n");
	printf("+--------+\n");
	printf("|        |\n");
	printf("|   命   |\n");
	printf("|        |\n");
	printf("|   運   |\n");
	printf("|        |\n");		
	printf("+--------+\n");	
	system("pause");
	int num,m;
	char symbol;	
	srand(time(NULL));
	num = rand() % 3 + 1;	//編號 (1-3)
	switch(num){
		case 1:
			printf("\n內容: 遭到外星人攻擊，損失 2000 元\n");
			player[i].money = player[i].money - 2000;
			break;
		case 2:
			printf("\n內容: 半路上意外撿到 1000 元\n");
			player[i].money = player[i].money + 1000;
			break;
		case 3:
			printf("\n內容: 退回起點\n");
			player[i].location = 0;
			for(m=0; m<24; m++){
				if(player[i].printOnMap[m] != ' '){
					symbol = player[i].printOnMap[m];
					player[i].printOnMap[m] = ' ';
				}
			}
			player[i].printOnMap[player[i].location] = symbol;
			break;		
	}
	printf("\n");
	return 	player[i];
}

void countWinner(struct map_initialise map[], struct player_initialise player[]){
	int k;
	int l,max;
	int sum[4]={0};
	for(k=0;k<4;k++){
		if(player[k].bankrupt){
			sum[k]=0;
			continue;
		}
		for(l=0;l<24;l++){
			if(map[l].owner==player[k].realty){
				sum[k] = sum[k]+map[l].price;
			}
		}
		sum[k] = sum[k]+player[k].money;
	}
	max = sum[0];
	int winner[4],n;
	for(k=1;k<4;k++){
		if(sum[k]>max){
			max = sum[k];
		}
	}
	for(k=0;k<4;k++){
		if(sum[k]==max) {
			printf("PLAYER %d WIN!\n",k+1);
			if(k + 1 == 1)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");	
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("■■■   ■            ■■      ■    ■  ■■■  ■■■■      ■              ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("■    ■  ■           ■  ■      ■  ■   ■      ■     ■    ■■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("■■■   ■          ■■■■      ■■    ■■■  ■■■■       ■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("■        ■         ■      ■      ■     ■      ■  ■         ■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");	
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("■        ■■■■  ■        ■     ■     ■■■  ■    ■   ■■■■           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■          	                                                                                ■\n");
				printf("■                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆                             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆              ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■          	                                                                                ■\n");
				printf("■                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆                       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                           ■      ■      ■  ■■■■■   ■     ■                         ■\n");
				printf("■                            ■    ■■    ■       ■      ■ ■   ■                         ■\n");
				printf("■               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■  ■  ■  ■        ■      ■  ■  ■       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆        ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                              ■■    ■■         ■      ■   ■ ■                         ■\n");
				printf("■                               ■      ■      ■■■■■  ■     ■                          ■\n");
				printf("■                                                                                              ■\n");
				printf("■                            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                     ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				system("pause");
				end();
			}
			if(k + 1 ==2)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");	
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("■■■   ■            ■■      ■    ■  ■■■  ■■■■      ■■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("■    ■  ■           ■  ■      ■  ■   ■      ■     ■   ■   ■           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("■■■   ■          ■■■■      ■■    ■■■  ■■■■        ■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("■        ■         ■      ■      ■     ■      ■  ■        ■              ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");	
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("■        ■■■■  ■        ■     ■     ■■■  ■    ■   ■■■■           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■          	                                                                                ■\n");
				printf("■                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆              ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■          	                                                                                ■\n");
				printf("■                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                           ■      ■      ■  ■■■■■   ■     ■                         ■\n");
				printf("■                            ■    ■■    ■       ■      ■ ■   ■                         ■\n");
				printf("■               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■  ■  ■  ■        ■      ■  ■  ■       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆        ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                              ■■    ■■         ■      ■   ■ ■                         ■\n");
				printf("■                               ■      ■      ■■■■■  ■     ■                          ■\n");
				printf("■                                                                                              ■\n");
				printf("■                            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                     ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				system("pause");
				end();
			}
			if(k + 1 == 3)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");	
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("■■■   ■            ■■      ■    ■  ■■■  ■■■■    ■■■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("■    ■  ■           ■  ■      ■  ■   ■      ■     ■        ■           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("■■■   ■          ■■■■      ■■    ■■■  ■■■■      ■■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("■        ■         ■      ■      ■     ■      ■  ■           ■           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");	
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("■        ■■■■  ■        ■     ■     ■■■  ■    ■    ■■■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■          	                                                                                ■\n");
				printf("■                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆                             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆              ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■          	                                                                                ■\n");
				printf("■                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆                       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                           ■      ■      ■  ■■■■■   ■     ■                         ■\n");
				printf("■                            ■    ■■    ■       ■      ■ ■   ■                         ■\n");
				printf("■               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■  ■  ■  ■        ■      ■  ■  ■       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆        ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                              ■■    ■■         ■      ■   ■ ■                         ■\n");
				printf("■                               ■      ■      ■■■■■  ■     ■                          ■\n");
				printf("■                                                                                              ■\n");
				printf("■                            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                     ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("☆                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				system("pause");
				end();
			}
			if(k + 1 == 4)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");	
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("■■■   ■            ■■      ■    ■  ■■■  ■■■■     ■ ■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("■    ■  ■           ■  ■      ■  ■   ■      ■     ■   ■  ■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("■■■   ■          ■■■■      ■■    ■■■  ■■■■   ■■■■           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("■        ■         ■      ■      ■     ■      ■  ■          ■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");	
				printf("■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5 | FOREGROUND_INTENSITY);
				printf("■        ■■■■  ■        ■     ■     ■■■  ■    ■        ■            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■          	                                                                                ■\n");
				printf("■                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆                             ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆              ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■          	                                                                                ■\n");
				printf("■                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆                       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");	
				printf("■                                                                                              ■\n");
				printf("■                           ■      ■      ■  ■■■■■   ■     ■                         ■\n");
				printf("■                            ■    ■■    ■       ■      ■ ■   ■                         ■\n");
				printf("■               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■  ■  ■  ■        ■      ■  ■  ■       ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆        ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                              ■■    ■■         ■      ■   ■ ■                         ■\n");
				printf("■                               ■      ■      ■■■■■  ■     ■                          ■\n");
				printf("■                                                                                              ■\n");
				printf("■                            ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                    ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 | FOREGROUND_INTENSITY);
				printf("☆               ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                         ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                     ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 | FOREGROUND_INTENSITY);
				printf("☆                           ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | FOREGROUND_INTENSITY);
				printf("☆                      ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | FOREGROUND_INTENSITY);
				printf("☆                  ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
				printf("■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■                                                                                              ■\n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");	
				system("pause");
				end();
			}
		}
	}
}

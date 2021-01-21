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

int dice();
void map_print(struct map_initialise map[], struct player_initialise player[]);
struct player_initialise chance(struct player_initialise player[],int i);
struct player_initialise fate(struct player_initialise player[],int i);
void countWinner(struct map_initialise map[], struct player_initialise player[]);
void end();

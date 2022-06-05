#ifndef PLAYER_H
#define PLAYER_H

#include<stdio.h>
#include<stdlib.h>

typedef struct{

	char pseudo[75];
	int mode;
	int score;

}Player;

Player create_player();
void update_high_score(Player player, int height , int width , int nmb_bomb);

#endif

#ifndef GAME_H
#define GAME_h

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"Box.h"

int control(Box *board[], int column , int line , int height , int width);
void place_the_bomb(Box *board[] , int nmb_bomb , int height , int width);
int is_finish(Box *board[] , int height , int width);
int game_set(int *line , int *column , int height , int width);
int game(Box *board[] , int nmb_flag , int line , int column , int mode , int height , int width);
int place_flag(Box *board[], int i , int j);
int discover_box(Box *board[], int i , int j , int height , int width);

#endif

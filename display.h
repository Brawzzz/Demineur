#ifndef DISPLAY_H
#define DISPLAY_H

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"Box.h"

char pion(int p);
void show_board(Box *board[], int height , int width);
void logo();
void logo_result();
void display_high_score();

#endif

#include"Game.h"
#include"display.h"
#include"Player.h"
#include"tools.h"
#include"Box.h"
#include"color.h"

int main(void){

	srand(time(NULL));
	
	Player player;
	
	int width = 0;
	int height = 0;
	int mode = 0;
	
	int nmb_bomb = 0;
	int nmb_max_bomb = 0;
	int nmb_flag = 0;
	
	int set_game = 0;
	int real_game = 0;
	
	int line = 0;
	int column = 0;
	
	int min = 0;
	int score = 0;
	
	int see = 0;
	int a;
	
	Box **real_board;
	Box *board;
	
	logo();
	
	player = create_player();
	
	mode = player.mode;
	
	if(mode == 0){
		width = 9;
		height = 9;
		nmb_bomb = 10;
	}
	else if(mode == 1){
		width = 16;
		height = 16;
		nmb_bomb = 40; 
	}
	
	else if(mode == 2){
	
		color("1");
	
		do{
			printf("Saisir la largeur de la grille (largeur max : 26) : ");
			a = scanf("%d",&width);
			clean_stdin();
			
			printf("Saisir la hauteur de la grille (hauteur max : 40) : ");
			a = scanf("%d",&height);
			clean_stdin();
			
			printf("\n");
			
		}while(width <= 0 || width > 26 || height <= 0 || height > 40 || a == 0);
		
		nmb_max_bomb = ((width * height)-(width * height)/10)- 1;
		
		do{
			printf("Saisir le nombre de bombes (nombres de bombes max : %d) : ", nmb_max_bomb);
			a = scanf("%d",&nmb_bomb);
			clean_stdin();
			
			printf("\n");
			
		}while(nmb_bomb > nmb_max_bomb || nmb_bomb < 0 || a == 0);
		
		printf("Nombre de bombes : %d\n\n", nmb_bomb);
		
		color("0");
	}
	
	//// 2D board allocation////
	real_board = malloc(width*sizeof(Box*));
	
	if(real_board == NULL){
		exit(1);
	}
	
	for(int i = 0 ; i < width ; i++){
	
		board = malloc(height * sizeof(Box));
		
		if(board == NULL){
			exit(1);
		}
		
		for(int j = 0 ; j < height ; j++){
			board[j].item = 0;
			board[j].state = -1;
		}
		
		real_board[i] = board;
	}
	////			
	
	place_the_bomb(real_board , nmb_bomb , height , width);
	nmb_flag = nmb_bomb;
	
	color("1");
	printf("Voici la grille :\n\n");
	color("0");
	show_board(real_board, height , width);
	
	/*
	for(int i = 0 ; i < width ; i++){
		
		for(int j = 0 ; j < height ; j++){
			real_board[i][j].state = -1;
		}
	}
	*/
	
	time_t time_1 = time(NULL);
	
	real_game = game(real_board , nmb_flag , line , column , mode , height , width);
	
	time_t time_2 = time(NULL);
	
	score = stopwatch(time_1, time_2);
	
	logo_result(real_game);
	
	if(real_game == 1){
		
		player.score = score;
		
		convert_score(&min , &score);
		affiche_score(min, score);
			
		update_high_score(player , width , height , nmb_bomb);
	}
	
	do{
		printf("-Saisir 1 pour voir la liste des high score\n-Saisir 2 pour ne pas voir la liste des high score : ");
		a = scanf("%d",&see);
		clean_stdin();
		
	}while(see != 1 && see != 2 || a == 0);
	
	if(see == 1){
		display_high_score();
	}
	
	return(0);
}

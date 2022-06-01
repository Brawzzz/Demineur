#include"Player.h"
#include"tools.h"
#include"color.h"

FILE *high_score = NULL;

/*
This function is a construct function for player struct
*/

Player create_player(){
	
	Player player;
	int a;
	
	color("1");
	
	printf("Saisir un pseudo : ");
	scanf("%s", player.pseudo);
	
	color("0");
	
	do{
		color("1");
		
		printf("- Saisir 0 pour le mode normal 9*9 et 10 bombes\n- Saisir 1 pour le mode difficile 16*16 et 40 bombes : ");
		a = scanf("%d", &player.mode);
		clean_stdin();
		printf("\n");
		
		color("0");
		
	} while(player.mode != 0 && player.mode != 1 || a == 0);
	
	player.score = 0;
	
	return player;
}

/*
This function write the score of the player in a file
*/

void update_high_score(Player player){

	int min = 0;
	
	convert_score(&min , &player.score);
	
	high_score = fopen("high_score.txt" , "a+");
	
	if(high_score == NULL){
		exit(1);
	}
	
	if(player.mode == 0){
	
		if(player.score > 9){
			fprintf(high_score , "Pseudo : %s | mode : normale | Score : %d:%d \n", player.pseudo , min , player.score);
		}
		else{
			fprintf(high_score , "Pseudo : %s | mode : normale | Score : %d:0%d \n", player.pseudo , min , player.score);
		}
	}
	
	else if(player.mode == 1){
	
		if(player.score > 9){
			fprintf(high_score , "Pseudo : %s | mode : normale | Score : %d:%d \n", player.pseudo , min , player.score);
		}
		else{
			fprintf(high_score , "Pseudo : %s | mode : normale | Score : %d:0%d \n", player.pseudo , min , player.score);
		}
	}
	
	fclose(high_score);
}


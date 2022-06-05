#include"Game.h"
#include"tools.h"
#include"display.h"
#include"Box.h"
#include"color.h"

/*
This function look if board[i][j] exist and if board[i][j] is a bomb.
If board[i][j] is a bomb or board[i][j] dosen't exist it's return 1 else it's return 0
*/

int control(Box *board[], int column , int line , int height , int width){	
	
	if(column < 0 || column > width-1 || line < 0 || line > height-1){
	
		return 1;
	} 
	
	else{
		if(board[column][line].item == 9){
			return 1;
		}
		else if (board[column][line].item >= 0 || board[column][line].item < 9){
			return 0;
		}	
	}
}

/*
This function place bombs randomly on the board and update the box arround.
Empty is a board in which there are the indexes of the empties boxs of board. We fill empty with linear indexes from 0 to number of box of board. In order to have the line and the column related to the linear indexes we divid the index by width. The quotient is the line and the rest is the column. 
Each time we place a bomb we are modifing empty. The box in which we place the bomb is remove from empty. Then the next time we chose a box for a bomb the box which was removed won't be in the choice.
*/

void place_the_bomb(Box *board[] , int nmb_bomb , int height , int width){

	int line = 0;
	int column = 0;
	int control_array = 0;
	
	int nb_slots = width*height;
	int* empty = (int*)malloc(nb_slots*sizeof(int));
	int nb = 0;
	
	for( int i = 0 ; i < nb_slots; i++) {
	
		line = i / width;
		column = i % width;
		
		if ( board[column][line].item == 0 ) {
			empty[nb] = i;
			nb++;
		}
	}
	
	for(int i = 0 ; i < nmb_bomb ; i++){
	
		int index = empty[rand()%nb];
		
		line = index / width;
		column = index % width;
		
		board[column][line].item = 9;
		
		nb = 0;
		
		for( int i = 0 ; i < nb_slots; i++) {
		
			int pline = i/width;
			int pcolumn = i%width;
			
			if ( board[pcolumn][pline].item != 9 ) {
				empty[nb] = i;
				nb++;
			}
		}
			
		for(int pi = -1 ; pi <= 1 ; pi++){
			for(int pj = -1 ; pj <= 1 ; pj++){
					
				if(pi != 0 || pj != 0){
						
					control_array = control(board , column + pj , line + pi , height , width);
							
					if(control_array == 0){
						board[column + pj][line + pi].item += 1; 
						
					}
				}
			}
		}
	}
}

/*
This function checks if the player has won. It's look over the board and if there is a box which is not a bomb and wich is not discovered it's return 0. Else it's return 1.
*/
int is_finish(Box *board[] , int height , int width){
	
	for(int i = 0 ; i < height ; i++){
		for(int j = 0 ; j < width ; j++){
		
			if(board[i][j].state == -1){
				if(board[i][j].item >= 0 && board[i][j].item < 9){
					return 0;
				}
			
			}			
		}
	}
	
	return 1;
}

/*
This function ask to the the player if he wants to place a flag or discover a box and returns the decison
*/

int game_set(int *line , int *column , int height , int width){

	char col; 
	int lig = 0;
	int decision;
	int a;
	
	color("1");
	
	do{
		printf("- Saisir 1 pour découvrir une case\n");
		printf("- Saisir 2 pour placer un drapeau : ");
		a = scanf("%d", &decision);
		clean_stdin();
		
	}while(decision != 1 && decision != 2 || a == 0);
	
	printf("\n\n");
	
	if(decision == 1){
		
		do{
			printf("Saisir les coordonnées de la case à découvrir (ex: B7) : ");
			
			scanf("%c", &col);
			scanf("%d", &lig);
			clean_stdin();
			
		}while(col > 65 + (width-1) || col < 65 || lig > height-1 || lig < 0);
		
		col -= 65;
		
		*(line) = lig;
		*(column) = col;
				
		printf("\n");
	}
	
	else if(decision == 2){
		
		printf("(Pour retirer un drapeau cliquez sur la même case)\n\n");
		
		do{
			printf("Saisir les coordonnées de la case dans laquelle placer le drapeau (ex: B7) : ");
			
			scanf("%c", &col);
			scanf("%d", &lig);
			clean_stdin();
			
		}while(col > 65 + (width-1) || col < 65 || lig > height-1 || lig < 0);
		
		col -= 65;
		
		*(line) = lig;
		*(column) = col;
				
		printf("\n");
	}
	
	color("0");
	
	return decision;
}

/*
This function controls game turns. It tells to the player how many flags he has, then it shows the board with the player's decision and repeat this until the player lose or win.
*/

int game(Box *board[] , int nmb_flag , int line , int column , int mode , int height , int width){

	int discover = 0;
	int flag = 0;
	int end = 0;
	int set_game = 0;

	do{
		color("1");
		printf("Nombre de drapeaux disponibles : %d\n\n", nmb_flag);
		color("0");
		
		end = is_finish(board , width , height);
		
		if(end == 0){
		
			set_game = game_set(&line , &column , height , width);
			
			if(set_game == 1){
					
				discover = discover_box(board , column , line , height , width);
				
				if(discover == -1){
					board[column][line].state = 1;
					show_board(board , height , width);
					end = 2;
				}
					
				else if(discover == -2){
					color("31");
					printf("Vous ne pouvez pas découvrir cette case !\n\n");
					color("0");
					show_board(board , height , width);
				}
				else{
					show_board(board , height , width);
				}
			}
				
			else if(set_game == 2){
				
				if(nmb_flag > 0){
				
					flag = place_flag(board , column , line);
						
					if(flag == -1){
						color("31");
						printf("Vous ne pouvez pas placer de drapeau ici !\n\n");
						color("0");
						show_board(board , height , width);
					}
						
					else if(flag == 0){
						show_board(board , height , width);
						nmb_flag -= 1;
					}
					
					else if(flag == 1){
						show_board(board , height , width);
						nmb_flag += 1;
					}	
				}
				
				else{
					color("31");
					printf("Vous n'avez plus de drapeaux disponibles\n");
					color("0");
				}
			}
		}
		
	}while( end != 1 && end != 2);
	
	return end;
}

int place_flag(Box *board[], int i , int j){

	if(board[i][j].state == 1){
		return -1;
	}
	
	else if(board[i][j].state == -1){
	
		board[i][j].state = 2;
		
		return 0;
	}
	
	else if(board[i][j].state == 2){
	
		board[i][j].state = -1;
		
		return 1;
	}
}

/*
This function enable to discover a box. If the box which is selected is empty all the box arround, which are empty, are uncovered.
If the box which is selected is a flag it return -2.
If the box which is selected is already discovered it return 1.
If the box which is selected is not discovered the function looks if the item is between 1 and 8 or if it's 0. If the item is between 1 and 8 the box is uncovered and if the item is 0 the box and all the box around which are not bomb are uncovered.
*/

int discover_box(Box *board[], int i , int j , int height , int width){
	
	int control_array = 0; 
	
	if(board[i][j].state == 2){
		return -2;
	}
	
	else if(board[i][j].state == 1){
		return 1;
	}
	
	else if(board[i][j].state == -1){
		
		if(board[i][j].item == 9){
			return -1;
		}
		
		else if(board[i][j].item < 9 && board[i][j].item > 0 && board[i][j].state != 2){
					
			board[i][j].state = 1;
			return 0;
		}
			
		else if(board[i][j].item == 0 && board[i][j].state != 2){
				
			board[i][j].state = 1;
			
			for(int k = -1 ; k <= 1 ; k++){
				for(int p = -1 ; p <= 1 ; p++){
					
					if(k != 0 || p != 0){
							
						control_array = control(board , i+k , j+p , height , width);
								
						if(control_array == 0){
							discover_box(board , i+k , j+p , height , width);
						}
					}
				}
			}
		}	
	}
}

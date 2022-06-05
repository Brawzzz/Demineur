#include"display.h"
#include"tools.h"
#include"Box.h"
#include"color.h"

/*
This function display the game title
*/

void logo(){

	printf("\n");
	
	color("1");
		
	printf("DDDDDDDDDDDDD      EEEEEEEEEEEEEEEEEEEEEEMMMMMMMM               MMMMMMMMIIIIIIIIIINNNNNNNN        NNNNNNNNEEEEEEEEEEEEEEEEEEEEEEUUUUUUUU     UUUUUUUURRRRRRRRRRRRRRRRR   \n");
	printf("D::::::::::::DDD   E::::::::::::::::::::EM:::::::M             M:::::::MI::::::::IN:::::::N       N::::::NE::::::::::::::::::::EU::::::U     U::::::UR::::::::::::::::R  \n");
	printf("D:::::::::::::::DD E::::::::::::::::::::EM::::::::M           M::::::::MI::::::::IN::::::::N      N::::::NE::::::::::::::::::::EU::::::U     U::::::UR::::::RRRRRR:::::R \n");
	printf("DDD:::::DDDDD:::::DEE::::::EEEEEEEEE::::EM:::::::::M         M:::::::::MII::::::IIN:::::::::N     N::::::NEE::::::EEEEEEEEE::::EUU:::::U     U:::::UURR:::::R     R:::::R\n");
	printf("  D:::::D    D:::::D E:::::E       EEEEEEM::::::::::M       M::::::::::M  I::::I  N::::::::::N    N::::::N  E:::::E       EEEEEE U:::::U     U:::::U   R::::R     R:::::R\n");
	printf("  D:::::D     D:::::DE:::::E             M:::::::::::M     M:::::::::::M  I::::I  N:::::::::::N   N::::::N  E:::::E              U:::::D     D:::::U   R::::R     R:::::R\n");
	printf("  D:::::D     D:::::DE::::::EEEEEEEEEE   M:::::::M::::M   M::::M:::::::M  I::::I  N:::::::N::::N  N::::::N  E::::::EEEEEEEEEE    U:::::D     D:::::U   R::::RRRRRR:::::R \n");
	printf("  D:::::D     D:::::DE:::::::::::::::E   M::::::M M::::M M::::M M::::::M  I::::I  N::::::N N::::N N::::::N  E:::::::::::::::E    U:::::D     D:::::U   R:::::::::::::RR  \n");
	printf("  D:::::D     D:::::DE:::::::::::::::E   M::::::M  M::::M::::M  M::::::M  I::::I  N::::::N  N::::N:::::::N  E:::::::::::::::E    U:::::D     D:::::U   R::::RRRRRR:::::R \n");
	printf("  D:::::D     D:::::DE::::::EEEEEEEEEE   M::::::M   M:::::::M   M::::::M  I::::I  N::::::N   N:::::::::::N  E::::::EEEEEEEEEE    U:::::D     D:::::U   R::::R     R:::::R\n");
	printf("  D:::::D     D:::::DE:::::E             M::::::M    M:::::M    M::::::M  I::::I  N::::::N    N::::::::::N  E:::::E              U:::::D     D:::::U   R::::R     R:::::R\n");
	printf("  D:::::D    D:::::D E:::::E       EEEEEEM::::::M     MMMMM     M::::::M  I::::I  N::::::N     N:::::::::N  E:::::E       EEEEEE U::::::U   U::::::U   R::::R     R:::::R\n");
	printf("DDD:::::DDDDD:::::DEE::::::EEEEEEEE:::::EM::::::M               M::::::MII::::::IIN::::::N      N::::::::NEE::::::EEEEEEEE:::::E U:::::::UUU:::::::U RR:::::R     R:::::R\n");
	printf("D:::::::::::::::DD E::::::::::::::::::::EM::::::M               M::::::MI::::::::IN::::::N       N:::::::NE::::::::::::::::::::E  UU:::::::::::::UU  R::::::R     R:::::R\n");
	printf("D::::::::::::DDD   E::::::::::::::::::::EM::::::M               M::::::MI::::::::IN::::::N        N::::::NE::::::::::::::::::::E    UU:::::::::UU    R::::::R     R:::::R\n");
	printf("DDDDDDDDDDDDD      EEEEEEEEEEEEEEEEEEEEEEMMMMMMMM               MMMMMMMMIIIIIIIIIINNNNNNNN         NNNNNNNEEEEEEEEEEEEEEEEEEEEEE      UUUUUUUUU      RRRRRRRR     RRRRRRR\n");
	
	color("0");
	
	printf("\n");
}

/*
This function display the result of the game 
*/
void logo_result(int end){

	if(end == 2){
	
		color("1");
	
printf("         GGGGGGGGGGGGG              AAA              MMMMMMMM               MMMMMMMEEEEEEEEEEEEEEEEEEEEEE          OOOOOOOOO    VVVVVVVV           VVVVVVVEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRRRRRRR \n");  
printf("      GGG::::::::::::G             A:::A             M:::::::M             M:::::::E::::::::::::::::::::E        OO:::::::::OO  V::::::V           V::::::E::::::::::::::::::::R::::::::::::::::R \n"); 
printf("    GG:::::::::::::::G            A:::::A            M::::::::M           M::::::::E::::::::::::::::::::E      OO:::::::::::::OOV::::::V           V::::::E::::::::::::::::::::R::::::RRRRRR:::::R \n");
printf("   G:::::GGGGGGGG::::G           A:::::::A           M:::::::::M         M:::::::::EE::::::EEEEEEEEE::::E     O:::::::OOO:::::::V::::::V           V::::::EE::::::EEEEEEEEE::::RR:::::R     R:::::R\n");
printf("  G:::::G       GGGGGG          A:::::::::A          M::::::::::M       M::::::::::M E:::::E       EEEEEE     O::::::O   O::::::OV:::::V           V:::::V  E:::::E       EEEEEE R::::R     R:::::R\n");
printf(" G:::::G                       A:::::A:::::A         M:::::::::::M     M:::::::::::M E:::::E                  O:::::O     O:::::O V:::::V         V:::::V   E:::::E              R::::R     R:::::R\n");
printf(" G:::::G                      A:::::A A:::::A        M:::::::M::::M   M::::M:::::::M E::::::EEEEEEEEEE        O:::::O     O:::::O  V:::::V       V:::::V    E::::::EEEEEEEEEE    R::::RRRRRR:::::R\n"); 
printf(" G:::::G    GGGGGGGGGG       A:::::A   A:::::A       M::::::M M::::M M::::M M::::::M E:::::::::::::::E        O:::::O     O:::::O   V:::::V     V:::::V     E:::::::::::::::E    R:::::::::::::RR \n"); 
printf(" G:::::G    G::::::::G      A:::::A     A:::::A      M::::::M  M::::M::::M  M::::::M E:::::::::::::::E        O:::::O     O:::::O    V:::::V   V:::::V      E:::::::::::::::E    R::::RRRRRR:::::R\n");
printf(" G:::::G    GGGGG::::G     A:::::AAAAAAAAA:::::A     M::::::M   M:::::::M   M::::::M E::::::EEEEEEEEEE        O:::::O     O:::::O     V:::::V V:::::V       E::::::EEEEEEEEEE    R::::R     R:::::R\n");
printf(" G:::::G        G::::G    A:::::::::::::::::::::A    M::::::M    M:::::M    M::::::M E:::::E                  O:::::O     O:::::O      V:::::V:::::V        E:::::E              R::::R     R:::::R\n");
printf("  G:::::G       G::::G   A:::::AAAAAAAAAAAAA:::::A   M::::::M     MMMMM     M::::::M E:::::E       EEEEEE     O::::::O   O::::::O       V:::::::::V         E:::::E       EEEEEE R::::R     R:::::R\n");
printf("   G:::::GGGGGGGG::::G  A:::::A             A:::::A  M::::::M               M::::::EE::::::EEEEEEEE:::::E     O:::::::OOO:::::::O        V:::::::V        EE::::::EEEEEEEE:::::RR:::::R     R:::::R\n");
printf("    GG:::::::::::::::G A:::::A               A:::::A M::::::M               M::::::E::::::::::::::::::::E      OO:::::::::::::OO          V:::::V         E::::::::::::::::::::R::::::R     R:::::R\n");
printf("      GGG::::::GGG:::GA:::::A                 A:::::AM::::::M               M::::::E::::::::::::::::::::E        OO:::::::::OO             V:::V          E::::::::::::::::::::R::::::R     R:::::R\n");
printf("         GGGGGG   GGGAAAAAAA                   AAAAAAMMMMMMMM               MMMMMMMEEEEEEEEEEEEEEEEEEEEEE          OOOOOOOOO                VVV           EEEEEEEEEEEEEEEEEEEEERRRRRRRR     RRRRRRR\n");

		color("0");
		printf("\n");
	}
	
	else if(end == 1){
	
		color("1");
	
printf("  !!! !!!      VVVVVVVV           VVVVVVVIIIIIIIIII     CCCCCCCCCCCCTTTTTTTTTTTTTTTTTTTTTTT    OOOOOOOOO    RRRRRRRRRRRRRRRRR  YYYYYYY       YYYYYYY      !!! !!! \n");
printf(" !!:!!!:!!     V::::::V           V::::::I::::::::I  CCC::::::::::::T:::::::::::::::::::::T  OO:::::::::OO  R::::::::::::::::R Y:::::Y       Y:::::Y     !!:!!!:!!\n");
printf(" !:::!:::!     V::::::V           V::::::I::::::::ICC:::::::::::::::T:::::::::::::::::::::TOO:::::::::::::OOR::::::RRRRRR:::::RY:::::Y       Y:::::Y     !:::!:::!\n");
printf(" !:::!:::!     V::::::V           V::::::II::::::IC:::::CCCCCCCC::::T:::::TT:::::::TT:::::O:::::::OOO:::::::RR:::::R     R:::::Y::::::Y     Y::::::Y     !:::!:::!\n");
printf(" !:::!:::!      V:::::V           V:::::V  I::::IC:::::C       CCCCCTTTTTT  T:::::T  TTTTTO::::::O   O::::::O R::::R     R:::::YYY:::::Y   Y:::::YYY     !:::!:::!\n");
printf(" !:::!:::!       V:::::V         V:::::V   I::::C:::::C                     T:::::T       O:::::O     O:::::O R::::R     R:::::R  Y:::::Y Y:::::Y        !:::!:::!\n");
printf(" !:::!:::!        V:::::V       V:::::V    I::::C:::::C                     T:::::T       O:::::O     O:::::O R::::RRRRRR:::::R    Y:::::Y:::::Y         !:::!:::!\n");
printf(" !:::!:::!         V:::::V     V:::::V     I::::C:::::C                     T:::::T       O:::::O     O:::::O R:::::::::::::RR      Y:::::::::Y          !:::!:::!\n");
printf(" !:::!:::!          V:::::V   V:::::V      I::::C:::::C                     T:::::T       O:::::O     O:::::O R::::RRRRRR:::::R      Y:::::::Y           !:::!:::!\n");
printf(" !:::!:::!           V:::::V V:::::V       I::::C:::::C                     T:::::T       O:::::O     O:::::O R::::R     R:::::R      Y:::::Y            !:::!:::!\n");
printf(" !!:!!!:!!            V:::::V:::::V        I::::C:::::C                     T:::::T       O:::::O     O:::::O R::::R     R:::::R      Y:::::Y            !!:!!!:!!\n");
printf("  !!! !!!              V:::::::::V         I::::IC:::::C       CCCCCC       T:::::T       O::::::O   O::::::O R::::R     R:::::R      Y:::::Y             !!! !!! \n");
printf("                        V:::::::V        II::::::IC:::::CCCCCCCC::::C     TT:::::::TT     O:::::::OOO:::::::RR:::::R     R:::::R      Y:::::Y                     \n");
printf("  !!! !!!                V:::::V         I::::::::ICC:::::::::::::::C     T:::::::::T      OO:::::::::::::OOR::::::R     R:::::R   YYYY:::::YYYY          !!! !!! \n");
printf(" !!:!!!:!!                V:::V          I::::::::I  CCC::::::::::::C     T:::::::::T        OO:::::::::OO  R::::::R     R:::::R   Y:::::::::::Y         !!:!!!:!!\n");
printf("  !!! !!!                  VVV           IIIIIIIIII     CCCCCCCCCCCCC     TTTTTTTTTTT          OOOOOOOOO    RRRRRRRR     RRRRRRR   YYYYYYYYYYYYY          !!! !!! \n");
	
		color("0");
		printf("\n");
	
	}
}



/*
This function display the correct pictures of a box depending on the item and the state of the box
*/

char pion(int p){

	if(p == 9){
		return '*';
	}
	else if(p == 0){
		return ' ';
	}
	else if(p == -1){
		return '~';
	}
	else if(p == 2){
		return 'Y';
	}
}

/*
This function display the correct board depending on the mode of the game and the state of the box
*/

void show_board(Box *board[], int height , int width){

	printf("   ");
	
	for(int i = 0 ; i < width ; i++){
		printf("%c ", 65 + i);	
	}
	printf("\n");
	
	for(int j = 0 ; j < height ; j++){
	
		if(j > 9){
			printf("%d",j);
		}
		
		else{
			printf("%d ",j);
		}
		
		for(int k = 0 ; k < width ; k++){
			
			if(board[k][j].state == 1){
				
				if(board[k][j].item == 0){
				
					printf("|%c", pion(board[k][j].item));
				}
				
				else if(board[k][j].item == 9){
					
					printf("|");
					//color("5");
					color("1");
					color("31");
					printf("%c", pion(board[k][j].item));
					color("0");
				}
				
				else{
					printf("|");
					color("1");
					printf("%d", board[k][j].item);
					color("0");
				}
			}
			
			else if(board[k][j].state == -1){
			
				printf("|%c", pion(board[k][j].state));
			}
			
			else if(board[k][j].state == 2){
				
				printf("|");
				color("32");
				printf("%c", pion(board[k][j].state));
				color("0");
			}
			
		}
			
		printf("|\n");
	}
	
	printf("\n\n");
}

/*
This function display the high score file
*/

void display_high_score(){

	FILE *high_score = NULL;
	
	high_score = fopen("high_score.txt" , "a+");
	
	if(high_score == NULL){
		exit(1);
	}
	
	char c = fgetc(high_score);
	
	while( c != EOF){
		printf("%c", c);
		c = fgetc(high_score);	
	}
	
	printf("\n");
}


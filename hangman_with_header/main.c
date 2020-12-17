
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hangman.h"

int main()

{
        int score_player1 = 0;
        int score_player2 = 0;
        int i;
        printf("\nWelcome to my hangman game! \n");

        printf("Are you ready to begin? (y/n)  ");

        char response[1];

        scanf("%s", response);
        response_check(response);

                while (response[0] != 'n'){

                        system("clear");
                        printf("Player_1 types the word, and Player 2 has to guess it! \n\n");

                        i = play_game();
                        if ( i == 0 ){
                                printf("\n\nYou lost! Player_1 wins!\n");
                                score_player1++;}
                        else if ( i == 1 ) {printf("\n\nYou won! Player_2 wins!\n");
                                score_player2++;}

                        scoreboard(score_player1, score_player2);

                        printf("\nDo you want to continue? (y/n)  ");

                        scanf("%s", response);
                        response_check(response);

                        if (response[0] == 'y'){
                                system("clear");
                                printf("Player_2 type the word, and Player_1 has to guess it! \n\n");

                                i = play_game();
                                if ( i == 0 ){
                                        printf("\n\nYou lost! Player_2 wins!\n");
                                        score_player2++;}
                                else if ( i == 1 ) {printf("\n\nYou won! Player_1 wins!\n");
                                        score_player1++;}

                                scoreboard(score_player1, score_player2);

                                printf("\nDo you want to play again? (y/n)  ");

                                scanf("%s", response);
                                response_check(response);}
                        }
return 0;}	

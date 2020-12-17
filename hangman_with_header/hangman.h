#ifndef HANGMAN_H
#define HANGMAN_H

void hangman_sketch(int, char[]);
int letter_check(char[], int);
int lowercase_check(char[], int);
int play_game(void);
void scoreboard(int, int);
void response_check(char[]);

#endif	

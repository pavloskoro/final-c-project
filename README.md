# final-c-project
CS 102-B final c project

Hangman game
this program allows two users to play the game hangman. The one player enters a word, while the other player tries guessing by entering letters (and vice versa). If the player guesses the word within a certain amount of tries, he earns a point. Else, the other player earns a point.

To run the programm compile main.c by using the makefile.

# hangman_sketch function

This function prints the hangman figure after the player guesses a letter. Depending on the mistakes the player has left, the figure will have more parts completed.

	void hangman_sketch(int mistakes_left, char hangman[6])
	{

	if (mistakes_left == 5){hangman[0] = 'o';};
	if (mistakes_left == 4){hangman[1] = '|';};
	if (mistakes_left == 3){hangman[2] = '/';};
	if (mistakes_left == 2){hangman[3] = '\\';};
	if (mistakes_left == 1){hangman[4] = '/';};
	if (mistakes_left == 0){hangman[5] = '\\';};

	 printf("\t            \n"
       		"\t   ______   \n"
      		"\t   |/   |   \n"
       		"\t   |    %c  \n"
       		"\t   |   %c%c%c \n"
       		"\t   |    %c   \n"
       		"\t   |   %c %c \n"
       		"\t   |        \n"
       		"\t___|___     \n"
       		"\t            \n", hangman[0], hangman[2], hangman[1], hangman[3], hangman[1], hangman[4], hangman[5] );
	
	return;}

# letter_check function

This function checks if a letter has been guesses twice. In this case, it will return 1 and a different letter will be asked to enter.

	int letter_check(char letter[26], int guess)

	{
		int i;
        	for (i = 0; i < guess; i++){
                if (letter[guess] == letter[i]) {return 1;}
                
		}
	
	return 0;}

# lowercase_check function

This function checks if either the word that the player has to guess, or the letters he enters are lowercase letters. If one or more characters are not lowercase letters, the function will return 1 and the player will be asked to enter a different letter/word.

	int lowercase_check(char string[], int length)

	{
		int i;
		for (i = 0; i < length; i++)
			{if ( (int)string[i] < 97 || (int)string[i] > 122)
			{return 1;}
			}
	
	return 0;}

# play_game function

This function uses the previous functions for one round of hangman. The one player enters a word and the other player has to enter characters to guess the letters. The function ends if the player guesses the word, or if he is out of tries.

	int play_game()
	{	
	
        char letter_guess[1];
	char word[50];
        char hiddenword[50];
        char hangman[6] = "      ";  
	char letter[26];
	
	int length ,i, mistake_alert;
        int mistakes_left = 6;
        int guess = 0;
	
	
	printf("Enter word to guess:  ");
        scanf("%s", word);
        system("clear");
        length = strlen(word);
	
	while ( lowercase_check(word, length) != 0){
		
		printf("You can only use lowercase letters! Try again! \n\n");
		printf("Enter word to guess:  ");
		scanf("%s", word);
        	system("clear"); 
        	length = strlen(word);}
	 
	hangman_sketch(mistakes_left, hangman);
		
        for (i=0; i < length; i++){
        hiddenword[i] = '_';
	printf("%c ", hiddenword[i]);
	}
        
	while ((strcmp(hiddenword, word)) != 0 && mistakes_left != 0 ){
	
		
		printf("\n\nEnter a letter: ");
		
		scanf("%s", letter_guess);
		
		letter[guess] = letter_guess[0];
		
		if ( lowercase_check(letter, guess + 1) == 1 ) 
		{printf("You can only insert lower-case letters! Try again! \n");}
		
		else if ( letter_check(letter, guess) == 1) 
		{printf("You have already used this letter! Try again! \n");} 		
		
		else {
			
			mistake_alert = 1;
		
			for (i=0; i < length; i++){
				if (letter[guess] == word[i])
				{hiddenword[i] = word[i];
				mistake_alert = 0;}
			
			}
			guess = guess + 1;
					
			system("clear");
		
			if (mistake_alert == 1) {mistakes_left--;}
			hangman_sketch(mistakes_left, hangman);
		 
        		for (i=0; i < length; i++){printf("%c ", hiddenword[i]);}
			printf("                        letters used: ");
			for (i=0; i < guess; i++){printf("%c, ", letter[i]);}
			}

	}  
        
	if (mistakes_left != 0){return 1;}
	else {printf("\n\nThe word was: %s ", word);}
	return 0;}

# socreboard function

This function prints the scores of player 1 and player 2 at the end of each round

	void scoreboard(int score1, int score2)

	{	 printf("\t			\n"
			"\t       Score		\n"
			"\t-------------------  \n"
			"\t			\n"
			"\t Player 1: %d	\n"
			"\t			\n"
			"\t Player 2: %d	\n", score1, score2);
	return;}

# response_check function

This function checks if the response of the player is 'y' for yes, or 'n' for no. If a different character is entered, the player will be asked to either enter 'y' for the game to continue, or 'n' for the game to end.

	void response_check(char response[])

	{		 
		while (response[0] != 'y' && response[0] != 'n'){
			printf("\nEnter 'y' for yes, or 'n' for no:  ");
			scanf("%s", response);}
	return;}

# main

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

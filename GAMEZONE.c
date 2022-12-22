#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function Declaration For Game 1

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int checkwin();
void board();

//Function Declaration For Game 2

int generateRandomNumber(int );
int greater(char c1, char c2);

//Function Declaration For Game 3

int GetPlayerToss(char player1[],char player2[],int oversToplay);
int batting(char battingplayer[],char bowlingplayer[],int oversToplay);

//Function Declaration For Game 4

void guess(int N);



int main()

{   
    
    int choi=0;

    printf("\t\t\t>>>>>>>>>> Welcome To Game Zone <<<<<<<<<<<\n");
    
    printf("1- Tik\n");
    printf("2- Stone Paper\n");
    printf("3- Cricket\n");
    printf("4- Guess the number\n");
    printf("Please Choose A Game :");
    scanf("%d",&choi);
    
    if(choi==1) 
    {
        int player = 1, i, choice;
         char mark;
         do
         {
         board();
         player = (player % 2) ? 1 : 2;
         printf(" Player %d, enter a number: ", player);
         scanf("%d", &choice);
         mark = (player == 1) ? 'X' : 'O';
         if (choice == 1 && square[1] == '1')
         square[1] = mark;
         else if (choice == 2 && square[2] == '2')
         square[2] = mark;
         else if (choice == 3 && square[3] == '3')
         square[3] = mark;
         else if (choice == 4 && square[4] == '4')
         square[4] = mark;
         else if (choice == 5 && square[5] == '5')
         square[5] = mark;
         else if (choice == 6 && square[6] == '6')
         square[6] = mark;
         else if (choice == 7 && square[7] == '7')
         square[7] = mark;
         else if (choice == 8 && square[8] == '8')
         square[8] = mark;
         else if (choice == 9 && square[9] == '9')
         square[9] = mark;
         else
         {
         printf(" Invalid move ");
         player--;
         
         }
         i = checkwin();
         player++;
         }while (i == - 1);
         board();
         if (i == 1)
         printf(" ==>\aPlayer %d win ", --player);
         else
         printf(" ==>\aGame draw");
            }
            
            
    else if(choi==2)
    {
    int playerScore = 0, compScore = 0, temp;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};
    printf("\tWelcome to the Rock Paper Scissors\n");
    printf("\t----------------------------------\n\n");
    for (int i = 0; i < 3; i++)
    {
        // Take player input
        printf("Press 1 for Rock, Press 2 for Paper, Press 3 for Scissors\n\n");
        printf("\tPlayer's turn: ");
        scanf("%d", &temp);
        getchar();
        playerChar = dict[temp - 1];
        printf(" -----------------\n");
        printf("| You choose: %c   |\n", playerChar);
        printf(" -----------------\n\n");
        //computer generate
        printf("Press 1 for Rock, Press 2 for Paper, Press 3 for Scissors\n\n");
        printf("\tComputer's turn\n");
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];
        printf(" --------------------\n");
        printf("| Computer choose: %c |\n", compChar);
        printf(" --------------------\n\n");
        // compater character and increment the score
        if (greater(compChar, playerChar) == 1)
        {
            compScore++;
            printf("\t\tComputer Got It!\n\n");
        }
        else if (greater(compChar, playerChar) == -1)
        {
            compScore++;
            playerScore++;
            printf("\t\tIt's a draw. Both got 1 point!\n\n");
        }
        else
        {
            playerScore++;
            printf("\t\tYou Got It!\n\n");
        }
        printf(" -------------\n");
        printf("| You: %d      |\n", playerScore);
        printf("| Computer: %d |\n", compScore);
        printf(" -------------\n\n");
        printf("===========================================================\n\n");
    }
    printf(" -----------------\n");
    printf("|   Final Score   |\n");
    printf(" -----------------\n");
    printf("|  You | Computer |\n");
    printf("|------|----------|\n");
    printf("|   %d  |    %d     |\n", playerScore, compScore);
    printf(" -----------------\n\n");
    // compare score
    if (playerScore > compScore)
    {
        printf("\n\t -------------------\n");
        printf("\t| You Win the match |\n");
        printf("\t -------------------\n");
    }
    else if (playerScore < compScore)
    {
        printf("\n\t ------------------------\n");
        printf("\t| Computer Win the match |\n");
        printf("\t ------------------------\n");
    }
    else
    {
        printf("\n\t -------------\n");
        printf("\t| It's a draw |\n");
        printf("\t -------------\n");
    }
    }
    
    
    
    
    else if(choi==3)
    {
      
              int i,j,overs,noovers,player1Toss,player2Toss;
         char player1[50],player2[50];
         srand(time(NULL));
         printf("-----------------------------------WELCOME TO HAND CRICKET GAME-------------------------------------\n");
         printf("Enter Player 1 Name:");
         fflush(stdin);
         gets(player1);
         printf("Enter Player 2 Name:");
         fflush(stdin);
         gets(player2);
         printf("Enter\n1 - Fixed Overs\n2 - Play Until Out\n3 - How to Play?\n4 - Exit: ");
         scanf("%d",&noovers);
          do{
         if(noovers==1)
         {
          printf("Enter No Of Overs: ");
          scanf("%d",&overs);
          player1Toss=GetPlayerToss(player1,player2,overs); 
          
         }
         else if(noovers==2)
         {
          player1Toss=GetPlayerToss(player1,player2,0);
         }
         else if(noovers==3)
         {
          printf("How To Play?\n");
          printf("Until a player Won the toss Follow the Output and give whatever it asks you to give\n");
          printf("Then the Player who won the toss chooses either to Bat or to Bowl\n");
          printf("The Player who chose batting and bowling has to proceed by pressing enter Key one by one\n");
          printf("Where System will generate Random number as runs for both players.Player 1 runs keeps on adding until his runs equals to player 2 runs\n");
          printf("Finally When Player 1 is Out.Till then his runs are his final Score.The Same process will be Conducted for player 2.\n");
          printf("Finally whoever is having Highest Score is the Winner.\n\n");
          printf("For Example: Player 1 Won the Toss And Chose Batting.Then When Player 1 Press Enter Key,A score will be generated for Player 1\n");
          printf("Suppose runs are 5 So Player 1 Score=5.Then Player 2 Also Presses Enter key.Then if he got a Score of 4.So Player 2 Score =4\n");
          printf("As Player 1 Score is not equal to player 2 Score Then Player 1 is not out and hi score will be 5 after 1st ball \n");
          printf("In 2nd ball Player 1 got 3 runs and Player 2 got 4.Since again both are not equal.Player 1 Score=5+3=8\n");
          printf("If in the 3rd Ball Player 1 got 4 runs and Player 2 also got 4 runs Then Player 1 Score is equal to Player 2's Score Then Player 1 is Out\n");
          printf("Then Final Score of player 1 is 8 runs.\n");
          printf("The Same Process is done for Player 2.So Finaly who ever got more score is Winner\n");
         }
         else
         {
          printf("--------------------------------------------Invalid Choice--------------------------------------------\n");
         }
         printf("Enter 1 - Fixed Overs\n2 - Play Until Out\n3 - How to Play?\n4 - Exit: ");
         scanf("%d",&noovers);
          }while(noovers>=1 && noovers<=3);
             
    }
    
    if(choi==4)
    {
        int N = 100;

    	// Function call
    	guess(N);

    	
    }
    

    return 0;
}


int checkwin()
{
 if (square[1] == square[2] && square[2] == square[3])
 return 1;
 else if (square[4] == square[5] && square[5] == square[6])
 return 1;
 else if (square[7] == square[8] && square[8] == square[9])
 return 1;
 else if (square[1] == square[4] && square[4] == square[7])
 return 1;
 else if (square[2] == square[5] && square[5] == square[8])
 return 1;
 else if (square[3] == square[6] && square[6] == square[9])
 return 1;
 else if (square[1] == square[5] && square[5] == square[9])
 return 1;
 else if (square[3] == square[5] && square[5] == square[7])
 return 1;
 else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
 square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
 != '7' && square[8] != '8' && square[9] != '9')
 return 0;
 else
 return - 1;
}
/***********************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ************************/
void board()
{
 //system("cls");
 printf("\n\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
 printf("\t Tic Tac Toe");
 printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
 printf(" Player 1 (X) - Player 2 (O)\n\n");
 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
 printf("\t|   |   |   |\n");
 printf("\t| %c | %c | %c |\n", square[1], square[2], square[3]);
 printf("\t|___|___|___|\n");
 printf("\t|   |   |   |\n");
 printf("\t| %c | %c | %c |\n", square[4], square[5], square[6]);
 printf("\t|___|___|___|\n");
 printf("\t|   |   |   |\n");
 printf("\t| %c | %c | %c |\n", square[7], square[8], square[9]);
 printf("\t|   |   |   |\n");
 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
}


//Functions for Rock Paper

int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}
int greater(char c1, char c2)
{
    if (c1 == c2)
    {
        return -1;
    }
    else if (c1 == 'r' && c2 == 's')
    {
        return 1;
    }
    else if (c2 == 'r' && c1 == 's')
    {
        return 0;
    }
    else if (c1 == 'p' && c2 == 'r')
    {
        return 1;
    }
    else if (c2 == 'p' && c1 == 'r')
    {
        return 0;
    }
    else if (c1 == 's' && c2 == 'p')
    {
        return 1;
    }
    else if (c2 == 's' && c1 == 'p')
    {
        return 0;
    }
}






//function for CRICKET
int GetPlayerToss(char player1[],char player2[],int oversToplay)
{
 int player1Choice,player2Choice,toss,player1Toss,batorbowlChoice,player2Score,player1Score;
     printf("%s Choose your choice either 1 for head or 2 for tail: ",player1);
  scanf("%d",&player1Choice);
  if(player1Choice==1)
  {
   player2Choice=2;
   printf("%s Choice is Tail\n",player2);
  }
  else if(player1Choice==2)
  {
   player2Choice=1;
   printf("%s Choice is Head\n",player2);
  }
  else
  {
   printf("--------------------------------------------Invalid Choice--------------------------------------------\n");
   return(0);
  }
  toss=rand()%2;
  toss=toss+1;
  if(toss==1)
  printf("Toss is Head\n");
  else
  printf("Toss is Tail\n");
  if(toss==player1Choice)
  {
   player1Toss=1;
   printf("Player 1 %s Won the Toss\n",player1);
   printf("Choose\n1 - Batting\n2 - Bowl: ");
   scanf("%d",&batorbowlChoice);
   if(batorbowlChoice==1)
   {
        printf("----------------%s is Going to bat Now-----------------------\n",player1);
    player1Score=batting(player1,player2,oversToplay);
    printf("----------------%s is Going to bat Now-----------------------\n",player2);
    player2Score=batting(player2,player1,oversToplay);
    printf("----------------Its Time for Results-----------------------\n");
   }
   else
   {
    printf("----------------%s is Going to bat Now-----------------------\n",player2);
    player2Score=batting(player2,player1,oversToplay);
    printf("----------------%s is Going to bat Now-----------------------\n",player1);
    player1Score=batting(player1,player2,oversToplay);
    printf("----------------Its Time for Results-----------------------\n");
   }
  }
  else if(toss==player2Choice)
  {
   player1Toss=2;
   printf("Player 2 %s Won the Toss\n",player2);
   printf("Choose\n1 - Batting\n2 - Bowl: ");
   scanf("%d",&batorbowlChoice);
   if(batorbowlChoice==1)
   {
    printf("----------------%s is Going to bat Now-----------------------\n",player2);
    player2Score=batting(player2,player1,oversToplay);
    printf("----------------%s is Going to bat Now-----------------------\n",player1);
    player1Score=batting(player1,player2,oversToplay);
    printf("----------------Its Time for Results-----------------------\n");
   }
   else
   {
    printf("----------------%s is Going to bat Now-----------------------\n",player1);
    player1Score=batting(player1,player2,oversToplay);
    printf("----------------%s is Going to bat Now-----------------------\n",player2);
    player2Score=batting(player2,player1,oversToplay);
    printf("----------------Its Time for Results-----------------------\n");
   }
  }
  else
  {
   printf("------------------------------------------------Error-------------------------------------------------\n");
   return(0);
  }
  if(player1Score==player2Score)
  {
   printf("Draw Match\nThanks For Playing the Game\n");
  }
  if(player1Score>player2Score)
  printf("%s Won the Match\nThanks for Playing the Game\n",player1);
  if(player1Score<player2Score)
  printf("%s Won the Match\nThanks for Playing the Game\n",player2);
  return(player1Toss);
}

int batting(char battingplayer[],char bowlingplayer[],int oversToplay)
{
 int i,j,battingScore,sum=0,bowlerSocre,flag=1;
 char c;
 if(oversToplay>0)
 {
  for(i=1;i<=oversToplay;i++)
  {
   for(j=1;j<=6;j++)
   {
    printf("%d.%d ball\n",i,j);
    printf("%s Press Enter key to bowl :",bowlingplayer);
    fflush(stdin);
    scanf("%c",&c);
    fflush(stdin);
    bowlerSocre=(int)rand()%7;//Generate from 0-6 where 0 means no ball
    printf("%s Press Enter key to bat :",battingplayer);
    fflush(stdin);
    scanf("%c",&c);
    fflush(stdin);
    battingScore=rand()%7;//Generate 0-6 runs
    if(battingScore==bowlerSocre)
    {
     flag=0;
     printf("-----------------%s is Out----------------\n",battingplayer);
     printf("%s Total Score=%d\n",battingplayer,sum);
     if(sum==0)
            printf("-----------Hehehe Duck Out-----------------\n");
     break;
    }
    else
    {
     printf("Got %d runs\n",battingScore);
                    if(battingScore==6)
                    printf("Sixerrrrrr Keep it Up\n");
                    if(battingScore==4)
               printf("Its a Four Great Man\n");
     sum=sum+battingScore;
     printf("%s Score=%d\n",battingplayer,sum);
    }
   }
   if(flag==0)
   break;
  }
 
  return(sum);
 }
 
   if(oversToplay==0)
   {
      while(flag)
      {
        printf("%s Press Enter key to bowl :",bowlingplayer);
  fflush(stdin);
  scanf("%c",&c);
  fflush(stdin);
  bowlerSocre=(int)rand()%7;//Generate from 0-6 where 0 means no ball
  printf("%s Press Enter key to bat :",battingplayer);
  fflush(stdin);
  scanf("%c",&c);
  fflush(stdin);
  battingScore=rand()%7;//Generate 0-6 runs
  
  if(battingScore==bowlerSocre)
  {
   flag=0;
   printf("-----------------%s is Out----------------\n",battingplayer);
   printf("%s Total Score=%d\n",battingplayer,sum);
   if(sum==0)
   printf("-----------Hehehe Duck Out-----------------\n");
   break;
  }
  
  else
  {
   printf("Got %d runs\n",battingScore);
            if(battingScore==6)
            printf("Sixerrrrrr Keep it Up\n");
            if(battingScore==4)
       printf("Its a Four Great Man\n");
   sum+=battingScore;
   printf("%s Score=%d\n",battingplayer,sum);
  }
      }
      return(sum);
   }
 
}



//Function for guess the number
// Function that generate a number in

// the range [1, N] and checks if the

// generated number is the same as the

// guessed number or not

void guess(int N)
{
	int number, guess, numberofguess = 0;

	// Generate a random number
	
	number = rand() % N;

	printf("Guess a number between"
		" 1 and %d\n",
		N);

	// Using a do-while loop that will
	// work until user guesses
	// the correct number
	
	do {

		if (numberofguess > 9) {
			printf("\nYou Loose!\n");
			break;
		}

		// Input by user
		
		scanf("%d", &guess);

		// When user guesses lower
		// than actual number
		
		if (guess > number)

		{
			printf("Lower number "
				"please!\n");
			numberofguess++;
		}

		// When user guesses higher
		// than actual number
		
		else if (number > guess)

		{
			printf("Higher number"
				" please!\n");
			numberofguess++;
		}

		// Printing number of times
		// user has taken to guess
		// the number
		
		else
			printf("You guessed the"
				" number in %d "
				"attempts!\n",
				numberofguess);

	} while (guess != number);
}

#include <stdio.h>

void make_entry(); // function to store the players' moves, check for re-entry.
int check_for_win();  // function to check for the winning move
void DisplayBoard();

static int a[9]={0};  // main array to store the players' moves
static int count = 0; // counter to allow only 9 moves in total
static int z[9]={0}; // another array to enter players' moves' value --- +1 for Player1 and -1 for Player2

void main()
{
	int  i=0, j=0, winner=2; 
	char isContinue = '0' ;

	while(1)
	{
		count = 0;
		for(i=0;i<9;i++){
			z[i]= 0 ;
			a[i]= 0 ; 
		}
	printf("\n\n\tWelcome to the game of Tic-Tac-Toe\n");
	printf("\tPlease enter numbers only from 1 to 9\n\n");
	printf("\n\tThe Blocks are numbered as below, for reference");
	printf("\n\t\t   |   |  \n\t\t 1 | 2 | 3 \n\t\t___|___|___  \n\t\t 4 | 5 | 6 \n\t\t___|___|___  \n\t\t 7 | 8 | 9 \n\t\t   |   |  \n\n");
	while(count<9)
	{
		if((count%2) == 0)
		{
		printf("   Player 1 make your move:\t");
		make_entry();

		winner = check_for_win();
		
		}

		if((count%2)==1)
		{
		 	printf("   Player 2 make your move:\t");
		 	make_entry();
		 winner = check_for_win();
		}
		count++;

		if(winner == 1) // if winner is Player1
		{
			printf("\n Player 1 wins!!! Congratulations\n");

		/*
			for(j=0;j<9;j++)
			printf("%d\t", z[j]);  */
			break;
		}

		if(winner == -1) // if winner is Player2
		{
			printf("\n Player 2 wins!!! Congratulations\n");

		/*
			for(j=0;j<9;j++)
			printf("%d\t", z[j]); */
			break;
		}

		if(winner == 3) // Draw :(
		{
			printf("\n Match Drawn\n");

		/*	for(j=0;j<9;j++)
			printf("%d\t", z[j]); */
			break;
		}
		DisplayBoard();
	}
	printf("Do you wish to continue[y/n]\n" );
	scanf("%c",&isContinue);
	if(isContinue == 'n'){
		printf("Exiting the game\nThanks for playing see you soon!!!!\n");
		break;
	}
}

/*	if(count==9)
	{
		for(j=0;j<9;j++)
	printf("%d\t", a[j]);
	}
*/


}

void make_entry()
{
static int i=0, b[9]={0}, x=0;
int k=0, flag =0;

	scanf("%d", &a[i]);

	/****************************** checking for valid entry from 1 to 9 *****************************/

	//if(a[i]==1 || a[i]==2 || a[i]==3 || a[i]==4 || a[i]==5 || a[i]==6 || a[i]==7 || a[i]==8 || a[i]==9) 
	if(a[i] > 0 && a[i] < 10)
	{
	x= a[i];
	printf("Move number: %d\n", count);
if((count%2) == 0)
	z[x-1] = 1;

if((count%2) == 1)
	z[x-1] = -1;



	for(k=0;k<9;k++)
	{
		 if((a[i])==(b[k]) && flag ==0)
		 {
		 	printf("That block is already filled. Enter again: ");
			flag = 1;
			break;	
		}
	}

	if(flag==1 && count!=9)
	{
		
		make_entry();

	}

	if(flag==0 && count!=9)
	{

	b[i]= a[i];
	i++;
}
}

else
{
	printf("\n\nEnter numbers only from 1 to 9!!!\n");
	make_entry();
}


}

int check_for_win()
{

	//int win=5;
	/* *************************** checking win for player 1 *******************************************/

//    printf("%d , %d \n",(z[0]==  z[1]== z[2] == 1) , (z[0]==  z[1]== z[2] == -1) );
	if(z[0] == z[1] && z[0] == z[2] && z[2] == z[1]   )  // 0 - 1 - 2
	{
		return z[0];
	}	

	if(z[3]==1 && z[4]==1 && z[5]==1) // 3 - 4 - 5 
	{
		return z[3];
	}

	if(z[6]==1 && z[7]==1 && z[8]==1) // 6 - 7 - 8
	{
		return z[6];
	}

	if(z[0]==1 && z[4]==1 && z[8]==1) // diagonal 0 - 4 - 8
	{
		return z[0];
	}

	if(z[2]==1 && z[4]==1 && z[6]==1) // diagonal 2 - 4 - 6
	{
		return z[2];
	}

	if(z[0]==1 && z[3]==1 && z[6]==1) // column 0 - 3 - 6
	{
		return z[0];
	}

	if(z[1]==1 && z[4]==1 && z[7]==1) // column 1 - 4 - 7
	{
		return z[1];
	}

	if(z[2]==1 && z[5]==1 && z[8]==1) // column 2 - 5 - 8
	{
		return z[2];
	}


/* *************************** checking win for player 2 *******************************************/
/*
	if(z[0]==-1 && z[1]==-1 && z[2]==-1)  // 0 - 1 - 2
	{
		return win = 1;
	}	

	if(z[3]==-1 && z[4]==-1 && z[5]==-1) // 3 - 4 - 5 
	{
		return win = 1;
	}

	if(z[6]==-1 && z[7]==-1 && z[8]==-1) // 6 - 7 - 8
	{
		return win = 1;
	}

	if(z[0]==-1 && z[4]==-1 && z[8]==-1) // diagonal 0 - 4 - 8
	{
		return win = 1;
	}

	if(z[2]==-1 && z[4]==-1 && z[6]==-1) // diagonal 2 - 4 - 6
	{
		return win = 1;
	}

	if(z[0]==-1 && z[3]==-1 && z[6]==-1) // column 0 - 3 - 6
	{
		return win = 1;
	}

	if(z[1]==-1 && z[4]==-1 && z[7]==-1) // column 1 - 4 - 7
	{
		return win = 1;
	}

	if(z[2]==-1 && z[5]==-1 && z[8]==-1) // column 2 - 5 - 8
	{
		return win = 1;
	}
*/

//win =2;
	if(count==8 ) // Match Drawn
	{
		return 3;
	}

return 4;

}

void DisplayBoard(){
	printf("\n\t\t   |   |  \n\t\t %d | %d | %d \n\t\t___|___|___  \n\t\t %d | %d | %d \n\t\t___|___|___  \n\t\t %d | %d | %d \n\t\t   |   |  \n\n", \
		z[0],z[1],z[2],z[3],z[4],z[5],z[6],z[7],z[8]);
}


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#define ANSI_COLOR_RED "\x1b[31m"


char key_pressed()
{

	struct termios oldterm, newterm;
	int oldfd; char c, result = 0;
	tcgetattr (STDIN_FILENO, &oldterm);
	newterm = oldterm; newterm.c_lflag &= ~(ICANON | ECHO);
	tcsetattr (STDIN_FILENO, TCSANOW, &newterm);
	oldfd = fcntl(STDIN_FILENO, F_SETFL, oldfd | O_NONBLOCK);
	c = getchar();
	tcsetattr (STDIN_FILENO, TCSANOW, &oldterm);
	fcntl (STDIN_FILENO, F_SETFL, oldfd); 
	
	
	

	
	if (c != EOF) {ungetc (c, stdin); result= getchar() ; }
	
	printf("\ncourgette");
	printf("\n");
	return result;


}

///////////////////////////////////////////////////////////////////////////////////////////

int show_labyrinthe()
{	
printf("\n");
int nbligne;
int nbcolonne;
int Xdebut;
int Ydebut;
int Xfin;
int Yfin;
	FILE *fichier;
	fichier=fopen("lab.txt","r");
	fscanf(fichier,"%d%d%d%d%d%d",&nbcolonne,&nbligne,&Xdebut,&Ydebut, &Xfin,&Yfin);

	char array[nbcolonne][nbligne][5];
	

	int i;
	int j;
	int k;


for (i=0; i<nbcolonne; i++)
	{
		for(j=0; j<nbligne; j++)
		{
			fscanf(fichier, "%s", array[i][j]);
			if (array[i][j][k]==' '||array[i][j][k]=='\n')
			{
			k--;
			}
			
			
			
		
		
		
		}
	
	
	}
	

		
		
		for(int r=0; r<nbligne; r++)
		{
			printf(" ");
			printf("\033[4m \033[0m");			
			
			
		}
		printf("\n");

		



		for (int i=0; i<nbcolonne; i++)
		{
			
			for(int a=0; a<nbligne; a++)
			{
				if (array[i][a][3]=='M')
				{
					printf("|");
				}
				else
				{
					printf(" ");
				}
				if ( array[i][a][2]=='M')
				{
					printf("\033[4m \033[0m");
				}
				else
				{
					printf(" ");
				}




			}
		printf("|\n");
		}
	
		
}
///////////////////////////////////////////////////////////////////////////////////////////

int direction()
{
int nbligne;
int nbcolonne;
int Xdebut;
int Ydebut;
int Xfin;
int Yfin;
FILE *fichier2;
	fichier2=fopen("lab.txt","r");
	fscanf(fichier2,"%d%d%d%d%d%d",&nbcolonne,&nbligne,&Xdebut,&Ydebut, &Xfin,&Yfin);
	char *position;
	char array2[nbcolonne][nbligne][5];
	

	int i=0;
	int j=0;
	int k=0;


for (i=0; i<nbcolonne; i++)
	{
		for(j=0; j<nbligne; j++)
		{
			fscanf(fichier2, "%s", array2[i][j]);
			if (array2[i][j][k]==' '||array2[i][j][k]=='\n')
			{
			k--;
			}
			
			
			
		
		
		
		}
	
	
	}
	

array2[i][j][5]= *position;




	while(i<9 && j<9)
	{
		
				if ( key_pressed()=='d' &&array2[i+1][j][1]!='M')
				{
					
					if(array2[i+1][j][2]=='M')
					{
					
					
						printf("\033[4m*\033[0m");
					}
					else
					{
						printf("*");
					}
						

				}
				
				if ( key_pressed()=='q' &&array2[i-1][j][3]!='M')
				{
					
					if(array2[i-1][j][2]=='M')
					{
					
					
						printf("\033[4m*\033[0m");
					}
					else
					{
						printf("*");
					}
						
				}
	
				if ( key_pressed()=='s' &&array2[i][j+1][2]!='M')
				{
					
					if(array2[i][j+1][2]=='M')
					{
					
					
						printf("\033[4m*\033[0m");
					}
					else
					{
						printf("*");
					}
						
				}
	
				if ( key_pressed()=='z' &&array2[i][j-1][1]!='M')
				{
					
					if(array2[i][j-1][2]=='M')
					{
					
						printf("*");
					}
						
				}


















		
	}


}



///////////////////////////////////////////////////////////////////////////////////////////



int menu()
{
char choice;
	system("clear");
	system("PS1");

	printf("\n\t\t");
	printf(ANSI_COLOR_RED "\033[4mBienvenue dans notre jeu de labyrinthe.\033[0m"  );
	
	printf("\n\nVoulez vous jouer en mode manuel ? y/n\t");
	scanf("%c", &choice);
	if (choice == 'y')
	{	
		printf("\nLes deplacements sont :\n'z' pour le haut\n'd'pour la droite\n'q' pour la gauche \n's' pour le bas");
	
		show_labyrinthe();
		direction();
	
	}
	
	else
	{
		printf("ptetre une autre fois (ToT)");
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
int main() 
{ 	
	menu();
	key_pressed();	
}

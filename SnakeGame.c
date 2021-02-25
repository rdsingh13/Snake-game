#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
char board[30][30];
struct Node* neww=NULL;
int x=15;
int y=15;
int aa=15,bb=20;
FILE *fptr;
int count=0;
int Score=0;
int data[1000];


struct Node { 
    int xx,yy,direction;
    struct Node* next; 
}; 

void Delay()
{
    long double i;
    for(i=0; i<=(80000000); i++);
}
void GameOver(struct Node*head)
{
	int k=0,i=0;
	if(head->xx>28||head->yy>28||head->xx<1||head->yy<1)
	{
	exit(0);
	}
	struct Node* n=head->next;

	while(n->next!=NULL)
	{
		if(n->xx==head->xx&&n->yy==head->yy)
		{
			
			
			exit(0);
		}
		n=n->next;
	}

//					fputs(data, fPtr);

}
void Up(struct Node* head)
{
	int aa=head->xx;
	int bb=head->yy;
	int b=head->xx-1;
	struct Node*n=head;
	board[b][bb]='X';
	int temp=n->xx,temp2=n->xx;
	int te=n->yy,te2=n->yy;

	int i=2;
	while(n->next!=NULL)	{
		temp=n->next->xx;
		te=n->next->yy;
		n->next->xx=temp2;
		n->next->yy=te2;
		board[n->next->xx][n->next->yy]='o';

        temp2=temp;
        te2=te;
		n=n->next;
		}	
		
	 	head->xx--;                      
}
void Down(struct Node* head)
{
	int aa=head->xx;
	int bb=head->yy;
	int b=head->xx+1;
	struct Node*n=head;
	board[b][bb]='X';
	int temp=n->xx,temp2=n->xx;
	int te=n->yy,te2=n->yy;
	data[0]=b;
	data[1]=bb;
	int i=2;
	while(n->next!=NULL)
	{
		temp=n->next->xx;
		te=n->next->yy;
		n->next->xx=temp2;
		n->next->yy=te2;
		board[n->next->xx][n->next->yy]='o';

		temp2=temp;
		te2=te;
		n=n->next;
		}	
		
		
		head->xx++;
}
void Right(struct Node* head)
{
	int aa=head->xx;
	int bb=head->yy;
	int b=head->yy+1;
	struct Node*n=head;
	board[aa][b]='X';
	int temp=n->yy,temp2=n->yy;
	int te=n->xx,te2=n->xx;

	while(n->next!=NULL)
	{
		temp=n->next->yy;
		te=n->next->xx;
		n->next->xx=te2;
		n->next->yy=temp2;
		board[n->next->xx][n->next->yy]='o';

		temp2=temp;
		te2=te;
		n=n->next;
		
		}	
		
		head->yy++;
}
void Left(struct Node* head)
{
	int aa=head->xx;
	int bb=head->yy;
	int b=head->yy-1;
	struct Node*n=head;
	board[aa][b]='X';
	int temp=n->yy,temp2=n->yy;
	int te=n->xx,te2=n->xx;

 	while(n->next!=NULL)
	{
		temp=n->next->yy;
		te=n->next->xx;
		n->next->xx=te2;
		n->next->yy=temp2;
		board[n->next->xx][n->next->yy]='o';

		temp2=temp;
		te2=te;
		n=n->next;
		}
		
		head->yy--;	
}
void printboard(char board[30][30])
{
	int i=0;
	int j=0;
	for(i=0;i<30;i++)
		{
			for(j=0;j<30;j++)
			{
				if((i==0)||(i==29)||(i>0&&i<29&&j==0||j==29))
				{
					board[i][j]='I';
				}
				else
				{
					board[i][j]=' ';
				}
				
			}
		}
}
void print(char board[30][30],struct Node* head)
{
	int i=0,k=0;
	int j=0;
	for(i=0;i<30;i++)
		{
			for( j=0;j<30;j++)
			{
				printf("%c",board[i][j]);
			}
			printf("\n");
		}
		printf("\n\n\n\t\t\t\t\t\t\t\tSCORE=%d",Score);
		struct Node* n= head;
		while(n!=NULL)
		{
			data[k]=n->xx;
			data[k+1]=n->yy;

			k+=2;
			printf("\n%d\t%d",n->xx,n->yy);
			n=n->next;
			
		}
			//fputs(data,fptr);
			fwrite(data, sizeof(data), 1, fptr);
			fclose(fptr);
		

	
}
void play(char board[30][30],struct Node* head,struct Node* last)
{
	move(board,head,last);
}

void food(struct Node* head)
{
	int fx=head->xx,fy=head->yy;

	
	struct Node* last=head;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	if(fx==aa&&fy==bb)
	{
			
	 neww = (struct Node*)malloc(sizeof(struct Node));
	 neww->xx=last->xx;
	 neww->yy=last->yy;
	 neww->direction=last->direction;
	 neww->next=NULL;
	 last->next=neww;
	 last=neww;
	  aa=rand()%28+1;
	  bb=rand()%28+1;
	  Score++;
	}
		board[aa][bb]='f';
}
void move(char board[30][30],struct Node* head,struct Node* last)
{
while(1)
{
	Delay();
	system("cls");
	printboard(board);
	food(head);
	GameOver(head);
	if(head->direction==RIGHT)
	{
		Right(head);
		GameOver(head);
	}
	else if(head->direction==LEFT)
	{
		Left(head);
		GameOver(head);
	}
	else if(head->direction==UP)
	{
		Up(head);
		GameOver(head);
	}
	else if(head->direction==DOWN)
	{
		Down(head);
		GameOver(head);
	}
	print(board,head);
	
	while(kbhit())
	{
	 char a=getch();
	 if(a==RIGHT&&head->direction!=LEFT||a==LEFT&&head->direction!=RIGHT||a==UP&&head->direction!=DOWN||a==DOWN&&head->direction!=UP)
	 {
	 head->direction=a;
	 
	}
    }
}
}
int main()
{
struct Node* head = NULL; 
struct Node* temp = NULL; 

fptr = fopen("data.txt", "w+");

head = (struct Node*)malloc(sizeof(struct Node)); 
temp = (struct Node*)malloc(sizeof(struct Node)); 
head -> xx = x;
head->yy=y;
head->direction=RIGHT;
head->next=temp;
temp->xx=x;
temp->yy=y;
temp->next=NULL;
temp->direction=head->direction;

	
	int n;
	scanf("%d",&n);
	if(n==1)
	{
	play(board,head,temp);	
	}
	else
	{
		
	}
	return 0;
}

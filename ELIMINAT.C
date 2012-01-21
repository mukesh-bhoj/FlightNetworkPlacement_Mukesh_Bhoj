#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>

struct node
{
char name[50];
struct node *next;
};

struct node *first=NULL;
struct node *new1;
struct node *temp;

void add(char na[],int start) //This function will add node into the circular next list
{
  new1=(struct node*)malloc(sizeof(struct node));//create memory for new node
  strcpy(new1->name,na);
  new1->next=new1;             //   create node

  if(start==0)
  {     first=new1;  }
  else
  {
     temp=first->next;
     while(temp->next!=first)
     { 	temp=temp->next;     }

     new1->next=temp->next;
     temp->next=new1;
  }
}
void disp()  // This function is used to travers the circuler list
{
   int i=2;
   if(first==NULL)
   {
      printf("\nEmpty List");
      return;
   }
   else
   {
      printf("\n %s",first->name);
      temp=first->next;
      while(temp!=first)
      {
	printf("   %s ",temp->name);
	temp=temp->next;
	i++;
      }
   }
}

void eliminate(int d)  //FOR ELIMINATE KIDS AT A PARTICULAR POSITION
{
  int i;
  struct node *prev;
  while(first->next!=first)
  {
      if(d==1)
      {
	printf("    => %s  IS ELIMINATED\n",first->name);
	temp=first->next;
	while(temp!=first)
	{
	   prev=temp;
	   temp=temp->next;
	}
	prev->next=temp->next;
	first=prev->next;
	disp();
      }
      else
      {
	temp=first;
	for(i=1;i<d;i++)
	{
	  prev=temp;
	  temp=temp->next;
	}
	prev->next=temp->next;
	printf("    => %s  IS ELIMINATED\n",temp->name);
	first=prev->next;
	disp();
      }
      delay(500);
   }
}

void main()
{
  int i,choice,M,N; //M:number of kids,N:random number,choice:for switch case.
  char na[50];
  clrscr();

  while(choice!=4)
  {
    printf("\n1)START GAME");
    printf("\n2)EXIT");
    printf("\nENTER YOUR CHOICE:");
    scanf("%d",&choice);

   switch(choice)
   {
    case 1:printf("\nHOWMANY KIDS DO YOU WANT IN THE GAME:");
	   scanf("%d",&M);
	   for(i=1;i<=M;i++)
	   {
		   printf("\nENTER NAME:");
		   flushall();
		   gets(na);
		   add(na,i-1);  //This function add the node into link list
	   }

	    printf("\nENTER ANY NUMBER BETWEEN (1 TO %d) :",M-1);
	    scanf("%d",&N);
	    printf("\nPlayers Are");
	    disp();
	    eliminate(N); //This function start the game of elimination
	    printf("\n\n  %s  WIN THE GAME",first->name);

	    break;
    case 2: exit(0);
	    break;
    default:printf("\NWRONG CHOICE");
   }
  }
  getch();
}

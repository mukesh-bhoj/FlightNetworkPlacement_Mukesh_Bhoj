#include<stdio.h>
#include<conio.h>

void push(int [],int*,int*);
void show(int [],int);

void main()
{

	int stack[10],pattern[10],i=0,ch,j=0,last_no=0;

	do
	{
	 printf("\n1. Push\n2. Pop\n3. Finish\n\n Enter Choice :");
	 scanf("%d",&ch);
	 switch(ch)
	 {
	  case 1:

		push(stack,&i,&last_no);
		printf("\n\nStack ==> ");
		show(stack,i);
		break;

	  case 2:
		if(i==0)
		{printf("Stack is underflow");break;}

		j++;
		pattern[j]=pop(stack,i);
		printf("\n\nPattern ==> ");
		show(pattern,j);
		i--;
		break;
	  case 3:
		break;

	 }
	}while(ch!=3);

}


void push(int stack[],int *i,int *last_no)
{
	 int n,j;
	 printf("\n\n Push Number(0-9) in Sequence :");
	 scanf("%d",&n);

	 while(n<0 || n>9)                    // check for number between 0 to 9
	 {
	 printf("\n	Wrong Push\n Please enter number between 0 to 9..");
	 return;
	 }

	 while(*last_no+1!=n && last_no!=0)       //  check for the sequence of number
	 {
	 printf("\n	Wrong Push\n	Push Number In Sequence \n");
	 return;
	 }

	 stack[++*i]=n;
	 *last_no=n;                           //  push into the stack

}

int pop(int stack[],int i)
{
	return stack[i];
}

void show(int st[],int i)
{
	 int j;

	 if(i==0)
	 printf("	EMPTY\n.");					//

	 for(j=1;j<=i;j++)                     //  display the stack
	 printf("  %d  ",st[j]);    	       //
}
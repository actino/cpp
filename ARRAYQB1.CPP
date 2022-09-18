#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int EMP[20]={12,23,44,0,0,0,40,30,88,7,0,0,87,41,0,8,66,0,98,0};
int i,c=0;
	for(i=0;i<20;i++)
	{ if(EMP[i]==0)
	  c++;
	}
cout<<"Number of years when no employees joined are: "<<c;
getch();
}


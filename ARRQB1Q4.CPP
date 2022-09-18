#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int M[30]={24,76,77,90,53,70,66,50,88,100,12,23,44,0,0,0,40,30,88,7,0,0,87,41,0,8,66,0,98,0};
int i,sum=0;
float avg;

	for(i=0;i<30;i++)
	{
	  sum+=M[i];
	}
avg=sum/30;

cout<<"Average marks in computer science = "<<avg;
getch();
}

#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int DATA[6] = {23,45,67,87,34,12},RDATA[6];
int i,j;
for(i=0,j=5;i<6;i++)
{
RDATA[i]=DATA[j];
j--;
}
for(i=0;i<6;i++)
cout<<RDATA[i]<<" \t";
getch();
}
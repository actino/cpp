#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int A[]={56,90,77,80,20}, B[]={54,60,25,34,12},C[5];
int i;

for(i=0;i<5;i++)
C[i] = 2* A[i] +3* B[i];

for(i=0;i<5;i++)
cout<<C[i]<<",";

getch();
}


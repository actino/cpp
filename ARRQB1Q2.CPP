#includue<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a[10]={2,22,34,-1,-67,44,3,0,678,333};
int max=0,maxpos,min=0,minpos,i=0;

max=a[i];
min=a[i];
maxpos=1;minpos=1;
i++;
do
{ if(a[i]>max)
  {
	max=a[i];
	maxpos=i+1;
  }
  if(a[i]<min)
   {
	min=a[i];
	minpos=i+1;
  }
i++;
} while(i<10);

cout<<"\n"<<"Maximum number is: "<<max<<"\n"<<"Position of maximum number: "<<maxpos;
cout<<"\n"<<"Miniimum number is: "<<min<<"\n"<<"Position of minimum number: "<<minpos;

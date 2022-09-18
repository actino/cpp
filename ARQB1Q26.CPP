#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a[50]={4,6,8,90,77,89,45,89,80,55};
int b[50];
int i,j,n,p;
for(i=0;i<50;i++)
cout<<a[i]<<"\t";

cout<<"Enter a number you wish to insert and the position at which you want to insert: ";
cin>>n>>p;

for(i=0,j=0;i<10;i++,j++)
{       if(i==(p-1))
       {	b[j]=n;
	b[j+1]=a[i];
       j++;	}
	else
	b[j]=a[i];
}

for(i=0;i<j;i++)
cout<<b[i]<<",";

getch();
}
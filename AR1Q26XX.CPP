#include<iostream.h>
#include<conio.h>

void main()
{
clrscr();
int a[50];
int i,n,p;

cout<<"Enter no of elements: ";
cin>>n;
cout<<"In which position do you want to enter an element: ";
cin>>p;

cout<<"Enter no: ";
for(i=0;i<n;i++) {
cin>>a[p-1];     }

for(i=0;i<n;i++)
{
	if(i!=p-1)
	a[i]=0;
	cout<<a[i]<<"\t";
}

getch();
}






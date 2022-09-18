#include<iostream.h>
#include<conio.h>
#include<process.h>

void main()
{
clrscr();
int i,j,r,c,s1=0,s2=0;//p=0,q=0,s=0,t=0*/;
int a[10][10];

cout<<"Enter number of rows of matrix: ";
cin>>r;
cout<<"\n"<<"Enter number of columnns of matrix: ";
cin>>c;

/* 1st matrix inputs */
	if(r==c) {
	cout<<"Please enter the elements of matrix: ";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<a[i][j]<<"\t";
		} cout<<endl;
	}

	cout<<endl;
	cout<<endl;

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{       if(i==j)
			s1+=a[i][j];
		}
	}

	for(i=0;i<r;i++)
	{
		for(j=c-1;j>=0;j--)
		{       if(i+j==r-1)
			s2+=a[i][j];
		}
	}
	cout<<"\n"<<s1<<"\n"<<s2;  }

	else    {
	cout<<"You need to enter equal number of rows and columns." ;
	getch();
	exit(0); }

getch();
}
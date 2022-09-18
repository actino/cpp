#include<iostream.h>
#include<conio.h>

void main()
{
clrscr();
int i,j,r,c1,p=0,q=0,s=0,t=0;
int a[10][10], b[10][10], c[10][10];

cout<<"Enter number of rows i=of both matrices: ";
cin>>r;
cout<<"\n"<<"Enter number of columnns of both matrices: ";
cin>>c1;

/* 1st matrix inputs */
	cout<<"Please enter the elements of matrix 1 : ";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c1;j++)
		{
			cin>>a[i][j];
		}
	}

/* 2nd matrix inputs */
	cout<<"Please enter the elements of matrix 1 : ";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c1;j++)
		{
			cin>>b[i][j];
		}
	}

/* Addition of matrices */
	for(i=0;i<r;i++)
	{
		for(j=0;j<c1;j++)
		{
		c[i][j] = a[i][j] + b[i][j];
		}
	}

/* Printing answer */
	for(i=0;i<r;i++)
	{
		for(j=0;j<c1;j++)
		{
			cout<<c[i][j]<<"\t";
		}
		cout<<endl;

	}

/* Addition of middle column*/
	q=j/2;
	for(i=0;i<r;i++)
	{
		p+=c[i][q];
	}
	cout<<"\n"<<"Sum of middle column is: "<<p;

/* Addition of middle row */
	s=r/2;
	for(j=0;j<c1;j++)
	{
		t+=c[s][j];

	}
	cout<<"\n"<<"Sum of middle row is: "<<t;
getch();
}

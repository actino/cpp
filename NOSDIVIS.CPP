#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int m,n,sum=0,c=0,a;
cout<<"How many numbers do you eant to enter? ";
cin>>m;
cout<<"Enter "<<m<<" values";
	for(int i = 0; i<m; i++)
	{
		cin>>n;
		if(n%3==0)
		{
			sum+=n;
			c++;
		}
	}

a=sum/c;
cout<<"Average of numbers divisible by 3 = "<<a;
getch();
}
#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int check(int n);
	int l,y=0;

	cout<<"Enter number: ";
	cin>>l;

	y=check(l);     cout<<y;
	getch();
}

int check(int n)
{
	int flag=0,c=0,i;

	for(i=2;i<=n/2;i++)
	if(n%i==0) c++;

	if(c==0) flag=0;
	else flag= -1;

	return flag;
}

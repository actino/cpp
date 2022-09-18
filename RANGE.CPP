#include<iostream.h>
#include<conio.h>
void main()
{
int n,sum,r,c;
	clrscr();
	cout<<"Enter range of even numbers: ";
	cin>>r>>n;
	sum=0;
	c=0;
	if(r%2==0)
	{
		for (int i=r; i<=n; i+=2)
		{
			sum+=i;
			c++;
			cout<<" "<<i;
		}
	}
	else
	{

		for (int i=r+1; i<=n; i+=2)
		{
			sum+=i;
			c++;
			cout<<" "<<i;
		}
	}

cout<<"\n"<<"Sum =  "<<sum<<"\n";
cout<<"Average =  "<<sum/c<<"\n";
getch();
}

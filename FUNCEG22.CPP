#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<process.h>

void main()
{
	clrscr();

	double power(double n,int p=2);
	int y;
	double x,m;

	cout<<"Enter a no: ";
	cin>>x;
	cout<<"Enter power: ";
	cin>>y;
	//m=power(x,y) ;

	cout<<endl;
	cout<<power(x,y);

	cout<<endl;
	cout<<power(6);

	getch();
}

double power(double n, int p)
{
	double ans=1.0;
	ans=pow(n,p);
	return ans;
}




#include<iostream.h>
#include<conio.h>

void multiply(int n,int c)
{
	int product=0;
	for(int a=1; a<=n; ++a)
		{
		product=c*a;
		cout<<"\n"<<product;
		}
}

 void main()
 {
	int n;
	int c;
	clrscr();
	cout<<"Please enter a number ";
	cin >> c;

	cout<<"How many multiples do you need? ";
	cin >> n;

		if (n<1)
		{
		cout<<"Invalid Calculation";
		}
		else {
			cout<<"\nThe multiples are:";
			multiply(n,c);
		}
	getch();
 }
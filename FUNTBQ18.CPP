#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	void Double(int n);
	int l;


	cout<<"Enter number: ";
	cin>>l;

	Double(l);
	getch();
}

void Double(int n)
{
	int j=n*2; cout<<j;
}

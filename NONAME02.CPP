#include<iostream.h>
#include<conio.h>
void main()
{	clrscr();
	int a =32,*x=&a;
	char ch=65, &eco=ch;
	eco+=a;
	*x+=ch;
	cout<<a<<","<<ch<<endl;cout<<x<<endl<<eco;
	getch();
}
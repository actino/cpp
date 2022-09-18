#include<iostream.h>
#include<conio.h>
void main()
{	clrscr();

	int payment(int h,int pr);
	int hours, pay_rate;
	float wages;

	cout<<"Hours: ";   cout<<endl;
	cin>>hours;
	cout<<"Pay  Rate: ";
	cin>>pay_rate;
	cout<<endl;

	wages=payment(hours,pay_rate);
	cout<<"Wages are: "<<wages;

	getch();

}

int payment(int h,int pr)
{	float w;
	if(h>60) w=h*pr*1.5;
	else  w=h*pr;
	return w;
}
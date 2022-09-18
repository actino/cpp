#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

class housing
{	int reg_no;
	char name[50];
	char type;
	float cost;

public:
	void read_data()
	{
	cout<<"REG NO: ";
	cin>>reg_no; cout<<endl;
	cout<<"Name: "<<endl;
	gets(name);
	cout<<"Type; "<<endl;
	cin>>type;
	cout<<"Price: "<<endl;
	cin>>cost;}

	void display()
	{ cout<<"REG NO: "<<reg_no;
	  cout<<endl;
	  cout<<"Name: "<<name<<endl;
	  cout<<"Type; "<<type<<endl;
	  cout<<"Price: "<<cost<<endl;}

       void draw_nos(housing *);
};

void housing::draw_nos(housing a[])
{ 	int rand;
	randomize();
	rand=random(991+10);
	a[rand].display();
}

void main()
{	clrscr();
	housing ob[10];
	housing house;
	for(int i=0;i<3;i++)
	ob[i].read_data();

	house.draw_nos(ob);
	getch();
}



#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>

class bank
{	int accno;
	char name[30];
	float balance;
	public:
	bank()
	{	 accno=101;
		 cout<<"Enter Name: ";
		 gets(name);
		 cout<<"Enter Balance: ";
		 cin>>balance; cout<<endl;
	}

	bank(bank&b)
	{ 	accno=b.accno+1;
		cout<<"Enter Name: ";
		gets(name);
		cout<<"Enter Balance: ";
		cin>>balance; cout<<endl;
	}

	void display()
	{
		cout<<"Acc No: "<<accno<<"\t"<<"Name: "<<name<<"\t"<<"Balance: ";
		cout.setf(ios::fixed);
		cout<<setprecision(2)<<balance<<endl;
	}
};

void main()
{       clrscr();
	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 3 - Copy constructor"<<endl<<endl;
	cout<<"\t\tBANK OF WONDERLAND"<<endl;

	bank ob1;
	bank ob2=ob1;
	ob1.display();
	ob2.display();
	getch();
}
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<fstream.h>

class bank
{	int accno;
	char name[30];
	float balance;
	fstream f2;
	public:
	bank()
	{	 accno=101;
		 f2.open("C:\\Jdata\\CSJOURQ3.txt", ios::app);
		 cout<<"Enter Name: ";
		 gets(name);
		 f2<<"Enter Name: "<<name<<endl;
		 cout<<"Enter Balance: ";
		 cin>>balance; cout<<endl;
		 f2<<"Enter Balance: "<<balance<<endl<<endl;
		 f2.close();
	}

	bank(bank&b)
	{ 	accno=b.accno+1;
		f2.open("C:\\Jdata\\CSJOURQ3.txt", ios::app);
		cout<<"Enter Name: ";
		gets(name);
		f2<<"Enter Name: "<<name<<endl;
		cout<<"Enter Balance: ";
		cin>>balance; cout<<endl;
		f2<<"Enter Balance: "<<balance<<endl<<endl;
		f2.close();
	}

	void display()
	{
		f2.open("C:\\Jdata\\CSJOURQ3.txt", ios::app);
		cout<<"Acc No: "<<accno<<"\t"<<"Name: "<<name<<"\t"<<"Balance: ";
		cout.setf(ios::fixed);
		cout<<setprecision(2)<<balance<<endl;

		f2<<"Acc No: "<<accno<<"\t"<<"Name: "<<name<<"\t"<<"Balance: "<<balance<<endl;
		f2.close();
	}
};

void main()
{       clrscr();
	fstream f1;

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 3 - Copy constructor"<<endl<<endl;
	cout<<"\t\tBANK OF WONDERLAND"<<endl;

	f1.open("C:\\Jdata\\CSJOURQ3.txt", ios::out);
	f1<<"XII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 3 - Copy constructor"<<endl<<endl;
	f1<<"\t\tBANK OF WONDERLAND"<<endl;
	f1.close();

	bank ob1;
	bank ob2=ob1;
	ob1.display();
	ob2.display();
	getch();
}
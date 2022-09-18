#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

struct date
{	int day,month,year;
};

class person
{ 	char name[20];
	char qualification[10];
	date dob;

	public:

	void  read1()
	{	cout<<"Enter Name: "; gets(name);
		cout<<"Date of birth: "; cout<<endl;
		cout<<"Enter Day: ";cin>>dob.day;
		cout<<"Enter Month: ";cin>>dob.month;
		cout<<"Enter Year: "; cin>>dob.year;
		cout<<"Enter Qualifications: ";  gets(qualification);
	}
	void display1()
	{	cout<<"Name: "<<name<<endl;
		cout<<"Date of birth: "<<dob.day<<"/"<<dob.month<<"/"<<dob.year<<endl;
		cout<<"Qualifications: "<<qualification<<endl;
	}
};

class employee:public person
{    	int empcode;
	float salary;
	date doj;
	public:

	void  read2()
	{       read1();
		cout<<"Enter Employee Code: "; cin>>empcode;
		cout<<"Date of joining: "; cout<<endl;
		cout<<"Enter Day: ";cin>>doj.day;
		cout<<"Enter Month: ";cin>>doj.month;
		cout<<"Enter Year: "; cin>>doj.year;
		cout<<"Enter Salary: ";  cin>>salary;
	}
	void display2()
	{       display1();
		cout<<"Employee Code: "<<empcode<<endl;
		cout<<"Date of joining: "<<doj.day<<"/"<<doj.month<<"/"<<doj.year<<endl;
		cout<<"Salary: "<<salary<<endl;
	}
};

class manager:protected employee
{ 	char dept[20];
	int no_empl;

	public:

	void  read3()
	{       read2();
		cout<<"Enter Department: "; gets(dept);
		cout<<"Enter No of team members: ";  cin>>no_empl;;
	}
	void display3()
	{       cout<<"------------- Output ------------------------"<<endl;
		display2();
		cout<<"Department: "<<dept<<endl;
		cout<<"No of team members: "<<no_empl<<endl;
	}
};
void main()
{	clrscr();
	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 6 - Inheritance : Person-Employee-Manager"<<endl<<endl;

	manager obj;
	obj.read3();
	cout<<endl;
	obj.display3();
	getch();
}
#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class person
{	char name[10];
	char dob[15];
	char qualification[77];

	public:
	void enter1()
	{	cout<<"Enter name: ";
		gets(name);
		cout<<"Date of birth: ";
		gets(dob);
		cout<<"Qualification: ";
		gets(qualification);
	}
	void display1()
	{       cout<<"Name: "<<name<<endl;
		cout<<"Date of birth: "<<dob<<endl;
		cout<<"Qualification: "<<qualification<<endl;
	}
};


class employee : public person
{	int empcode;
	long int salary;
	char doj[15];

	public:
	void enter2()
	{	cout<<"Enter empcode: ";
		cin>>empcode;
		cout<<"Date of joining: ";
		gets(doj);
		cout<<"Salary: ";
		cin>>salary;
	}
	void display2()
	{       cout<<"Empcode: "<<empcode<<endl;
		cout<<"Date of joining: "<<doj<<endl;
		cout<<"Salary: "<<salary<<endl;
	}
};


class manager: public employee
{	char dept[77];
	int ppl;
	public:
	void enter3()
	{	cout<<"Enter dept: ";
		gets(dept);
		cout<<"No of ppl: ";
		cin>>ppl;
	}
	void display3()
	{       cout<<"Department: "<<dept<<endl;
		cout<<"No of ppl: "<<ppl<<endl;
	}
};

void main()
{	clrscr();
	manager ob;
	ob.enter1();
	ob.enter2();
	ob.enter3();
	ob.display1();
	ob.display2();
	ob.display3();
	getch();
}

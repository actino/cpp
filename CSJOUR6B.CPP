#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>

struct date
{	int day,month,year;
};

class person
{ 	char name[20];
	char qualification[10];
	date dob;

	public:

	void  read1()
	{	
		fstream fp;

		cout<<"Enter Name: "; gets(name);
		cout<<"Date of birth: "; cout<<endl;
		cout<<"Enter Day: ";cin>>dob.day;
		cout<<"Enter Month: ";cin>>dob.month;
		cout<<"Enter Year: "; cin>>dob.year;
		cout<<"Enter Qualifications: ";  gets(qualification);

		fp.open("C:\\Jdata\\CSJOURQ6.txt", ios::app);
		fp<<"Enter Name: "<<name<<endl;
		fp<<"Date of birth: "<<endl;
		fp<<"Enter Day: "<<dob.day<<endl;
		fp<<"Enter Month: "<<dob.month<<endl;
		fp<<"Enter Year: "<<dob.year<<endl;
		fp<<"Enter Qualifications: "<<qualification<<endl;
		fp.close();

	}
	void display1()
	{	
		fstream fpo;

		cout<<"Name: "<<name<<endl;
		cout<<"Date of birth: "<<dob.day<<"/"<<dob.month<<"/"<<dob.year<<endl;
		cout<<"Qualifications: "<<qualification<<endl;

		fpo.open("C:\\Jdata\\CSJOURQ6.txt", ios::app);
		fpo<<"Name: "<<name<<endl;
		fpo<<"Date of birth: "<<dob.day<<"/"<<dob.month<<"/"<<dob.year<<endl;
		fpo<<"Qualifications: "<<qualification<<endl;
		fpo.close();

	}
};

class employee:public person
{    	int empcode;
	float salary;
	date doj;
	public:

	void  read2()
	{       
		fstream fe;

		read1();
		cout<<"Enter Employee Code: "; cin>>empcode;
		cout<<"Date of joining: "; cout<<endl;
		cout<<"Enter Day: ";cin>>doj.day;
		cout<<"Enter Month: ";cin>>doj.month;
		cout<<"Enter Year: "; cin>>doj.year;
		cout<<"Enter Salary: ";  cin>>salary;

		fe.open("C:\\Jdata\\CSJOURQ6.txt", ios::app);
		fe<<"Enter Employee Code: "<<empcode<<endl;
		fe<<"Date of joining: "<<endl;
		fe<<"Enter Day: "<<doj.day<<endl;
		fe<<"Enter Month: "<<doj.month<<endl;
		fe<<"Enter Year: "<<doj.year<<endl;
		fe<<"Enter Salary: "<<salary<<endl;
		fe.close();

	}
	void display2()
	{       
		fstream feo;

		display1();
		cout<<"Employee Code: "<<empcode<<endl;
		cout<<"Date of joining: "<<doj.day<<"/"<<doj.month<<"/"<<doj.year<<endl;
		cout<<"Salary: "<<salary<<endl;

		feo.open("C:\\Jdata\\CSJOURQ6.txt", ios::app);
		feo<<"Employee Code: "<<empcode<<endl;
		feo<<"Date of joining: "<<doj.day<<"/"<<doj.month<<"/"<<doj.year<<endl;
		feo<<"Salary: "<<salary<<endl;
		feo.close();

	}
};

class manager:protected employee
{ 	char dept[20];
	int no_empl;

	public:

	void  read3()
	{       
		fstream fm;

		read2();
		cout<<"Enter Department: "; gets(dept);
		cout<<"Enter No of team members: ";  cin>>no_empl;;

		fm.open("C:\\Jdata\\CSJOURQ6.txt", ios::app);
		fm<<"Enter Department: "<<dept<<endl;
		fm<<"Enter No of team members: "<<no_empl<<endl;
		fm.close();

	}
	void display3()
	{       
		fstream fmo;

		cout<<"------------- Output ------------------------"<<endl;
		fmo.open("C:\\Jdata\\CSJOURQ6.txt", ios::app);
		fmo<<"------------- Output ------------------------"<<endl;
		fmo.close();
		
		display2();
		cout<<"Department: "<<dept<<endl;
		cout<<"No of team members: "<<no_empl<<endl;

		fmo.open("C:\\Jdata\\CSJOURQ6.txt", ios::app);
		fmo<<"Department: "<<dept<<endl;
		fmo<<"No of team members: "<<no_empl<<endl;
		fmo.close();

	}
};
void main()
{	clrscr();
	fstream f1;

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 6 - Inheritance : Person-Employee-Manager"<<endl<<endl;

	f1.open("C:\\Jdata\\CSJOURQ6.txt", ios::out);
	f1<<"XII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 6 - Inheritance : Person-Employee-Manager"<<endl<<endl;
	f1.close();

	manager obj;
	obj.read3();
	cout<<endl;
	obj.display3();
	getch();
}
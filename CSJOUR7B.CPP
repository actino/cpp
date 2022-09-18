#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>

class student
{	int rollno;
	public:
	void putnumber()
	{	
		fstream f2;

		cout<<"Enter Roll No: ";
		cin>>rollno;

		f2.open("C:\\Jdata\\CSJOURQ7.txt", ios::app);
		f2<<"Enter Roll No: "<<rollno<<endl;
		f2.close();
	}

	int getnumber()
	{	return rollno;
	}
};
class test: virtual public student
{	int part1marks,part2marks,marks;
	public:
	void putmarks()
	{	
		fstream f3;
		
		cout<<"Enter marks(part1): ";
		cin>>part1marks;
		cout<<"Enter marks(part2): ";
		cin>>part2marks;

		f3.open("C:\\Jdata\\CSJOURQ7.txt", ios::app);
		f3<<"Enter marks(part1): "<<part1marks<<endl;
		f3<<"Enter marks(part1): "<<part2marks<<endl;
		f3.close();

	}
	int getmarks()
	{       marks=part1marks+part2marks;
		return  marks;
	}
};
class sport:virtual public student
{	int score;
	public:
	void putscore()
	{	
		fstream f4;
	
		cout<<"Enter score: ";
		cin>>score;

		f4.open("C:\\Jdata\\CSJOURQ7.txt", ios::app);
		f4<<"Enter score: "<<score<<endl;
		f4.close();

	}
	int getscore()
	{	return score;
	}
};
class derived : public test,public sport
{       int total;
	public:
	void display()
	{       
		fstream fo;
		
		total=getmarks()+getscore();
		cout<<"--------- Output ------------"<<endl;
		cout<<"Roll No: "<<getnumber()<<" Total: "<<total;

		fo.open("C:\\Jdata\\CSJOURQ7.txt", ios::app);
		fo<<"--------- Output ------------"<<endl;
		fo<<"Roll No: "<<getnumber()<<" Total: "<<total<<endl;
		fo.close();

	}
};

void main()
{	clrscr();

	fstream f1;

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 7 - Student Result using Virtual Class"<<endl<<endl;

	f1.open("C:\\Jdata\\CSJOURQ7.txt", ios::out);
	f1<<"XII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 7 - Student Result using Virtual Class"<<endl<<endl;
	f1.close();

	derived obj;
	obj.putnumber();
	obj.putmarks();
	obj.putscore();
	cout<<endl;
	obj.display();
	getch();
}

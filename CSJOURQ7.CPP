#include<iostream.h>
#include<conio.h>

class student
{	int rollno;
	public:
	void putnumber()
	{	cout<<"Enter Roll No: ";
		cin>>rollno;
	}
	int getnumber()
	{	return rollno;
	}
};
class test: virtual public student
{	int part1marks,part2marks,marks;
	public:
	void putmarks()
	{	cout<<"Enter marks(part1): ";
		cin>>part1marks;
		cout<<"Enter marks(part2): ";
		cin>>part2marks;
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
	{	cout<<"Enter score: ";
		cin>>score;
	}
	int getscore()
	{	return score;
	}
};
class derived : public test,public sport
{       int total;
	public:
	void display()
	{       total=getmarks()+getscore();
		cout<<"--------- Output ------------"<<endl;
		cout<<"Roll No: "<<getnumber()<<" Total: "<<total;
	}
};

void main()
{	clrscr();
	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 7 - Student Result using Virtual Class"<<endl<<endl;

	derived obj;
	obj.putnumber();
	obj.putmarks();
	obj.putscore();
	cout<<endl;
	obj.display();
	getch();
}

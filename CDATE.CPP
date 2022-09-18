#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class date
{        int d;
	// int sum;
	 //    sum=olddate.d+no_of_days;
	 int month,year;
public:
	date()
	{       d=0;
		month=0;
		year=0;
	}

	void read_data1()
	{	cout<<"Enter original date: ";
		cin>>d;   }
	void read_data2()
	 {	cout<<"Enter month: ";
		cin>>month;  }
	void read_data3()
	{	cout<<"Year: ";
		cin>>year;
	}

	date newdate(date olddate,int no_of_days)
	{    int sum;
	     sum=olddate.d+no_of_days;
	     date n;
	     if(sum>30)
	     { n.d=olddate.d+(no_of_days%30);
	       int cm=(no_of_days/30);
	       n.month=olddate.month+cm;
	       if(n.month>12)
	       { n.month=olddate.month+(cm%12);
	       }
	       int ym=(no_of_days/365);
	       n.year=olddate.year+ym;
	       return n;
	      // return m1;
	      // return y1;
	     }
	     else
	    { n.d=olddate.d+no_of_days;
	      n.month=olddate.month;
	      n.year=olddate.year;
	      return n;
	    }

	}
       void disp()
       {cout<<d<<"/"<<month<<"/"<<year;
       //	cout<<month
       }

};


void main()
{	date ob1,ob2,ob3;//ob4,ob5;
	int nd;
	clrscr();
	ob1.read_data1();
	ob1.read_data2();
	ob1.read_data3();
	cout<<"Enter no of days: ";
	cin>>nd;
	ob3=ob2.newdate(ob1,nd);
	cout<<"New date: " ;    ob3.disp();
	getch();
}
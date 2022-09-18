#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class candidate
{     //  clrscr();
	private:

	long int Rno;
	char Cname[25];
	float aggmks;
	char grade;

	char setgrade(float m)
	{ char g;

		if(m>=80)
			g='A';
		if(m<80&&m>=65)
			g='B';
		if(m<65&&m>=50)
			g='C';
		if(m<50)
			g='D';
	   return g;
	}
       public:
       //	candidate()
	//{
       //	}

       candidate()
	{	Rno=0;
		char Cname[25]="N/A";
		aggmks=0.0;	}

	void getdata()
	{	cout<<"Enter Roll No: ";
		cin>>Rno;
		cout<<endl;

		cout<<"Enter names: ";
		gets(Cname);
		cout<<endl;

		cout<<"Enter Agg marks: ";
		cin>>aggmks;
		cout<<endl;
	}


	void dispresult()
	{       char G;
		cout<<Rno;     cout<<endl;
		puts(Cname);
		cout<<endl;
		G=setgrade(aggmks);
		cout<<G;
	}

};

void main()
{       clrscr();
	candidate ob1;
       //	candidate ob2;
	ob1.getdata();
	ob1.dispresult();
	getch();
}
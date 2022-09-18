#include<iostream.h>
#include<conio.h>

class investment
{	float principal,rate,SI;
	int period;
	public:
	investment()
	{	principal=1000.00;
		rate=0.08;
		period=5;
		SI=principal*rate*period;
		cout<<SI<<endl;
	}
	investment(float p,float r,int t)
	{       principal=p;
		rate=r;
		period=t;
		SI=principal*rate*period;
		cout<<SI<<endl;
	}

	investment(float p,float r)
	{       principal=p;
		rate=r;
		period=5;
		SI=principal*rate*period;
		cout<<SI<<endl;
	}

	investment(int t)
	{       principal=1000.00;
		rate=0.08;
		period=t;
		SI=principal*rate*period;
		cout<<SI<<endl;
	}
};

void main()
{ 	clrscr();
	investment ob;
	investment ob1(5000.00F,0.05F,6);
	investment ob2(3000.00F,0.04F);
	investment ob3(3);
	getch();
}

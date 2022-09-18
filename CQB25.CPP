#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

class houses
{	private:
		int AD_NO;
		char name[100];
		char type[100];
		float cost;

	public:
		void read_data()
		{	cout<<"AD no: "<<endl;
			cin>>AD_NO;
			cout<<"Name: "<<endl;
			gets(name);
			cout<<"Type: "<<endl;
			gets(type);
			cout<<"Cost: "<<endl;
			cin>>cost;
		}

		void disp_data()
		{	cout<<"AD no: "<<AD_NO<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Type: "<<type<endl;
			cout<<"Cost: "<<cost<<endl;
		}

	       int draw_nos()
	       {	randomize();
			random(4-1+1)+1;
	       }
};

void main()
{ 	clrscr();
	int i,r;
	randomize();
	houses ob1[4];

	for(i=0;i<4;i++)
		ob1[i].read_data();

	for(i=0;i<2;i++)
	{	r=random(3-0+1)+0;
		//ob2.draw_nos();
		ob1[r].disp_data();
	}

	getch();
}

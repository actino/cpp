#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

class admission
{	private:
		int AD_NO;
		char name[100];
		char Class;
		float fees;

	public:
		void read_data()
		{	cout<<"AD no: "<<endl;
			cin>>AD_NO;
			cout<<"Name: "<<endl;
			gets(name);
			cout<<"Class: "<<endl;
			cin>>Class;
			cout<<"Fees: "<<endl;
			cin>>fees;
		}

		void disp_data()
		{	cout<<"AD no: "<<AD_NO<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Class: "<<Class<<endl;
			cout<<"Fees: "<<fees<<endl;
		}
	       /*
	       int draw_nos()
	       {	randomize();
			random(4-1+1)+1;
	       } */
};

void main()
{ 	clrscr();
	int i,r;
	randomize();
	admission ob1[4];

	for(i=0;i<4;i++)
		ob1[i].read_data();

	for(i=0;i<2;i++)
	{	r=random(3-0+1)+0;
		//ob2.draw_nos();
		ob1[r].disp_data();
	}

	getch();
}
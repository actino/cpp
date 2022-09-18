#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

class Admission
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

	       void draw_nos(Admission *);
	     /*  {	int j,r;
			randomize();
			for(j=0;j<2;j++)
			{	r=random(3-0+1)+0;
				//ob2.draw_nos();
				a[r].disp_data();
			}
	       } */
	};

void Admission::draw_nos(Admission a[]) {
	int j,r;
	randomize();
	for(j=0;j<2;j++)
	{	r=random(3-0+1)+0;
		//ob2.draw_nos();
		a[r].disp_data();
	}

}

void main()
{ 	clrscr();
	int i;
	Admission adm1, ob1[4];

	for(i=0;i<4;i++)
		ob1[i].read_data();

	adm1.draw_nos(ob1);

	getch();
}
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class flight
{
	long int fno;
	char company[20];
	char From[20];
	char To[20];

	public:

	flight()
	{ fno==0;
	  strcpy(From,"Out of order ");
	  strcpy(To,"Out of order ");
	}
	void enter()
	{       cout<<"Flight No:  ";
		cin>>fno; //cout<<endl;
		cout<<"Company: ";
		gets(company);
		cout<<"Take off point: ";
		gets(From); // cout<<endl;
		cout<<"Destination: ";
		gets(To);  //cout<<endl;
	}
 };
void main()
{	clrscr();
	flight plane[10];

	fstream filin;
	filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::out);

	for(int i=0;i<10;i++)
	{       cout<<i+1<<"."<<endl;
		plane[i].enter();
		filin.write((char*)&plane[i],sizeof(plane[i]));
		cout<<endl;
	}
	filin.seekg(0);
	filin.close();
      //	filin.close();
	getch();
}



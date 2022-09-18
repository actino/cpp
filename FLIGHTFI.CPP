#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class flight
{
	long int fno;
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
		cout<<"Take off point: ";
		gets(From); // cout<<endl;
		cout<<"Destination ";
		gets(To);  //cout<<endl;
	}

	void display()
	{       cout<<"Flight No:  "<<fno;
	       //	cin>>fno;
		cout<<endl;
		cout<<"Take off point: "<<From;
	       //	gets(From); //
		cout<<endl;
		cout<<"Destination "<<To;
	      //	gets(To);  //
		cout<<endl;
	}
};

void main()
{	clrscr();
	flight plane[10];

	fstream filin;
	filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::out);

	for(int i=0;i<3;i++)
	{	plane[i].enter();
		filin.write((char*)&plane[i],sizeof(plane[i]));
		cout<<endl;
	}
	filin.seekg(0);
	filin.close();

       //	filin.seekg(0);
       filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
	for(int j=0;j<3;j++)
	{	filin.read((char*)&plane[i],sizeof(plane[i]));
		plane[i].display();
		cout<<endl;
	 }
       //	filin.seekg();
	filin.close();
	getch();
}
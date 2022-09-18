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

	/*	void inform()
	{       char avail='n';
		if((strcmpi(To,entry))==0)
		{	display();
			avail='y';
			cout<<endl;
		}

		if(avail=='n')
		cout<<"Sorry. No flights";
	} */

       //	filin.seekg();

	void getto()
	{ 	char proxy[20];
		strcpy(proxy,To);
		//return proxy;
	}
};

void main()
{	clrscr();
	flight plane;
	char entry[20];
	char avail='n';
       //	char subst[20];


	cout<<"Where would you like to go:";
	gets(entry);

	fstream filin;

       filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
       filin.seekg(0);
     //	for(int j=0;j<3;j++)
	while(!filin.eof())
	{	filin.read((char*)&plane,sizeof(plane));
	       //	strcpy(subst,plane.getto());
		if((strcmpi(proxy,entry))==0)
		{	plane.display();
			avail='y';
			cout<<endl;
		}
	 }
	 if(avail=='n')
	 {	cout<<"Sorry. No flights"; 	}
       //	filin.seekg();
	filin.close();
	getch();
}
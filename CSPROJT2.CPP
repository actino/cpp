#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

class subject
{
	long int code;
	char name[20];
	public:
	void enter()
	{       cout<<"Name: ";
		gets(name);
		cout<<"Code:  ";
		cin>>code;
       }


	void display()
	{       cout<<name<<"\t";
	}

	int getcode()
	{
		return code;
	}


 };

 void main()
 {	int r,i;
	clrscr();
	ifstream  filin;
	filin.open("C:\\Jdata\\subject.dat", ios::binary|ios::in);
	randomize();
	subject s;
	for(i=0;i<5;i++)
	{	r=random(10)+1;
		filin.seeekg(0);
		while(1)
		{	filin.read((char*)&s,sizeof(s));
			if(filin.eof()) break;
			if(r==s.getcode())
			s.display();
		}  cout<<"\t";
	}  filin.close();
	getch();
 }









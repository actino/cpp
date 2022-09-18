#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>

struct student
{	int rollno;
	char name[15];
	int marks;
	long int telephoneno;
};

void add()
{       student std;
	cout<<"Name: ";
	gets(std.name);
	cout<<"rollno: ";
	cin>>std.rollno;
	cout<<"Marks: ";
	cin>>std.marks;
	cout<<"Telephone no";
	cin>>std.telephoneno;

	ofstream filin;
	filin.open("C:\\Jdata\\Stud.dat", ios::binary|ios::app);
	filin.write((char*)&std,sizeof(std));
	filin.close();
}

void details()
{       int proxy;
	char found='n';
	 cout<<"ROLL";
	 cin>>proxy;
	 student std;
	ifstream filin;
	filin.open("C:\\Jdata\\Stud.dat", ios::binary|ios::in);
	while(1)
	{ filin.read((char*)&std,sizeof(std));
	  if(filin.eof())	break;
	  else
	  if(std.rollno==proxy)
	 { cout<<std.rollno<<"\t"<<std.name<<"\t"<<std.marks<<"\t"<<std.telephoneno<<endl;
	   found='y';
	 }
	}   if(found=='n') cout<<"Not in database"<<endl;
	filin.close();
}

void update()
{       student std;
	char found ='n';
	int proxymarks,proxyroll;
	long int proxyno;
	cout<<"Roll no to be changed: "<<endl;
	cin>>proxyroll;
	cout<<"Enter new details;"<<endl;
	cout<<"Marks: ";
	cin>>proxymarks;
	cout<<"Telephone no";
	cin>>proxyno;

	ifstream filin;
	filin.open("C:\\Jdata\\Stud.dat", ios::binary|ios::in);
	while(1)
	{ filin.read((char*)&std,sizeof(std));
	  if(filin.eof())	break;
	  else
	  if(std.rollno==proxyroll)
	 { cout<<"Old details: "<<std.rollno<<"\t"<<std.name<<"\t"<<std.marks<<"\t"<<std.telephoneno<<endl;
	   std.marks=proxymarks;
	   std.telephoneno=proxyno;
	   cout<<"New details: "<<std.rollno<<"\t"<<std.name<<"\t"<<std.marks<<"\t"<<std.telephoneno<<endl;
	   found='y';
	 }
	}   if(found=='n') cout<<"Not in database"<<endl;
	filin.close();
}

void main()
{       clrscr();
	int choice;
	char ans='y';

	do{
	cout<<"MENU"<<endl<<"1.ADD"<<"\t"<<"2.DISPLAY"<<"\t"<<"3.Update"<<endl;
	cin>>choice;

	switch(choice){

		case 1: add();
			cout<<"Continue(y/n)?";
			cin>>ans;
			break;

		case 2: details();
			cout<<"Continue(y/n)?";
			cin>>ans;
			break;

		case 3: update();
			cout<<"Continue(y/n)?";
			cin>>ans;
			break;

	}}while(ans=='y');
}


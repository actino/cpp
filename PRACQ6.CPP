#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>

class details
{	int id;
	char name[10];
	char blood_group[7];

	public:
	void enter()
	{	cout<<"Enter id: ";
		cin>>id;
		cout<<"Enter name: ";
		gets(name);
		cout<<"Enter blood group: ";
		gets(blood_group);
	}


	void display()
	{	cout<<"Id: "<<id<<"\t";
		cout<<"Name: "<<name<<"\t";
		cout<<"Blood Group: "<<blood_group;
	}

	int retbgroup()
	{	if(strcmp(blood_group,"A+")==0)
		return 1;
		else
		return 0;
	}
};


void add()
{   ofstream filin;
    filin.open("C:\\Jdata\\Bloodgp.dat", ios::binary|ios::app);
    details bldgp;
    bldgp.enter();
    filin.write((char*)&bldgp,sizeof(bldgp));
    filin.close();
}

void select()
{   ifstream filin;
    filin.open("C:\\Jdata\\Bloodgp.dat", ios::binary|ios::in);
    details bldgp;
    while(1)
    {   filin.read((char*)&bldgp,sizeof(bldgp));
	if(filin.eof())		break;
	else
	if(bldgp.retbgroup()==1)
	{	bldgp.display();
		cout<<endl;
	}

    }
    filin.close();
}

void main()
{       clrscr();
	int choice;
	char ans;
	do{
	cout<<"MENU"<<endl;
	cout<<"1.ADD"<<"\n"<<"2.A+"<<endl;
	cin>>choice;

	switch(choice)
	{	case 1:	add();
			cout<<"Continue?(y/n)";
			cin>>ans;
			break;
		case 2: select();
			cout<<"Continue?(y/n)";
			cin>>ans;
			break;
	} }while(ans=='y');

	getch();
}



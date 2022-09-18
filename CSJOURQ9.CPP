#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct employee
{
	char name[20];
	char address[50];
	long phno;
};


void main()
{	clrscr();
	employee e;

	int choice;
	void add();
	void view();
	void modify();
	void remove();
	void list();

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 9 - Binary File Operations"<<endl;

	do{
		choice=0;
		cout<<endl;
		cout<<"\nMAIN MENU"<<endl;
		cout<<"1.Add Record"<<"\t"<<"2.View Record"<<endl<<"3.Modify"<<"\t"<<"4.Delete Record"<<"\t\t"<<"5.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;

		switch (choice)
		{	case 1: add();
				break;

			case 2: view();
				break;

			case 3: modify();
				break;

			case 4: remove();
				break;

			default:
				exit(0);
				break;
		}
	} while(1);
}

void view()
{	employee e;
	long proxyno;
	char avail='n';

	cout<<"Enter number whoose records you want to view: ";
	cin>>proxyno;
	fstream filin;
	filin.open("C:\\Jdata\\emp.dat", ios::binary|ios::in);
	filin.seekg(0);

	while(1)
	{	filin.read((char*)&e,sizeof(e));
		if (filin.eof()) break;
		if(proxyno==e.phno)
		{       cout<<"Name: "<<e.name;
			cout<<"\nAddress: "<<e.address;
			cout<<"\nPhone No: "<<e.phno<<endl;
			avail='y';
		}
	}
	if(avail=='n')
		cout<<"\nRecord not found"<<endl;

	filin.close();
}

void add()
{	employee e;
	fstream filout;
	void list();

	cout<<"Enter Details -"<<"\n";
	cout<<"Name: ";
	gets(e.name);
	cout<<"Address: ";
	gets(e.address);
	cout<<"Phone No: ";
	cin>>e.phno;

	filout.open("C:\\Jdata\\emp.dat", ios::binary|ios::app);
	filout.write((char*)&e,sizeof(e));
	filout.close();
	cout<<"\nRecord added"<<endl;
	list();
}



void remove()
{	employee e;
	fstream filin;
	ofstream filout;
	void list();
	long phnoproxy;
	char found='n';

	filin.open("C:\\Jdata\\emp.dat", ios::binary|ios::in);
	filin.seekg(0);
	filout.open("C:\\Jdata\\temp.dat", ios::binary|ios::out);

	cout<<"Enter phone no to delete: ";
	cin>>phnoproxy;

	while(1)
	{	filin.read((char*)&e,sizeof(e));
		if (filin.eof()) break;
		if(phnoproxy==e.phno)
		{	cout<<"\nRecord deleted"<<endl;
			found='y';
		}
		else
		filout.write((char*)&e,sizeof(e));
	}

	if(found=='n')
		cout<<"\nRecord not found"<<endl;

	filin.close();
	filout.close();

	remove("C:\\Jdata\\emp.dat");
	rename("C:\\Jdata\\temp.dat","C:\\Jdata\\emp.dat");

	list();
}


void modify()
{       employee e;
	char found ='n';
	char addr[50];
	long proxyno;
	void list();
	long pos;
	cout<<"Enter phone number to be modified: ";
	cin>>proxyno;
	fstream filin;
	filin.open("C:\\Jdata\\emp.dat", ios::binary|ios::in|ios::out);
	filin.seekg(0);

	while(1)
	{       pos=filin.tellg();
		filin.read((char*)&e,sizeof(e));
		if (filin.eof()) break;
		if(proxyno==e.phno)
		{	cout<<"Enter new address: ";
			gets(addr);
			strcpy(e.address,addr);
			filin.seekg(pos);
			filin.write((char*)&e,sizeof(e));
			found='y';
			cout<<"\nRecord updated"<<endl;
			break;
		}

	}
	filin.close();

	if(found=='n')
		cout<<"\nRecord not found";  cout<<endl;

	list();
}

void list()
{
	employee e;
	fstream filin;

	cout<<"\nDirectory :"<<endl;

	filin.open("C:\\Jdata\\emp.dat", ios::binary|ios::in);
	while(1)
	{   	 filin.read((char*)&e,sizeof(e));
		 if(filin.eof()) break;
		 cout<<e.name<<"\t"<<e.phno<<"\t"<<e.address<<endl;
	}
	filin.close();
	cout<<endl;

}
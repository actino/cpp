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

	fstream f2;

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 9 - Binary File Operations"<<endl;

	f2.open("C:\\Jdata\\CSJOURQ9.txt", ios::out);
	f2<<"XII Computer Science Journal(2019-2020)"<<endl;
	f2<<"Jasmin Chaughule Roll No. 2"<<endl;
	f2<<"Assignment 9 - Binary File Operations"<<endl;
	f2.close();

	do{
		choice=0;
		cout<<endl;
		cout<<"\nMAIN MENU"<<endl;
		cout<<"1.Add Record"<<"\t"<<"2.View Record"<<endl<<"3.Modify"<<"\t"<<"4.Delete Record"<<"\t\t"<<"5.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;

		f2.open("C:\\Jdata\\CSJOURQ9.txt", ios::app);
		f2<<endl<<"\nMAIN MENU"<<endl;
		f2<<"1.Add Record"<<"\t"<<"2.View Record"<<endl<<"3.Modify"<<"\t"<<"4.Delete Record"<<"\t\t"<<"5.Exit"<<endl;
		f2<<"Enter choice: "<<choice<<endl;
		f2.close();
		

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
	fstream f3;

	cout<<"Enter number whoose records you want to view: ";
	cin>>proxyno;

	f3.open("C:\\Jdata\\CSJOURQ9.txt", ios::app);
	f3<<"Enter number whoose records you want to view: "<<proxyno<<endl;

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
			f3<<"Name: "<<e.name;
			f3<<"\nAddress: "<<e.address;
			f3<<"\nPhone No: "<<e.phno<<endl;
		}
	}
	if(avail=='n') {
		cout<<"\nRecord not found"<<endl;
		f3<<"\nRecord not found"<<endl;
	}

	filin.close();
	f3.close();
}

void add()
{	employee e;
	fstream filout;
	void list();
	fstream f4;

	cout<<"Enter Details -"<<"\n";
	cout<<"Name: ";
	gets(e.name);
	cout<<"Address: ";
	gets(e.address);
	cout<<"Phone No: ";
	cin>>e.phno;

	f4.open("C:\\Jdata\\CSJOURQ9.txt", ios::app);
	f4<<"Enter Details -"<<"\n";
	f4<<"Name: "<<e.name<<endl;
	f4<<"Address: "<<e.address<<endl;
	f4<<"Phone No: "<<e.phno<<endl;

	filout.open("C:\\Jdata\\emp.dat", ios::binary|ios::app);
	filout.write((char*)&e,sizeof(e));
	filout.close();
	cout<<"\nRecord added"<<endl;
	f4<<"\nRecord added"<<endl;
	f4.close();
	list();
}



void remove()
{	employee e;
	fstream filin, f6;
	ofstream filout;
	void list();
	long phnoproxy;
	char found='n';

	filin.open("C:\\Jdata\\emp.dat", ios::binary|ios::in);
	filin.seekg(0);
	filout.open("C:\\Jdata\\temp.dat", ios::binary|ios::out);

	f6.open("C:\\Jdata\\CSJOURQ9.txt", ios::app);
	
	cout<<"Enter phone no to delete: ";
	cin>>phnoproxy;

	f6<<"Enter phone no to delete: "<<phnoproxy<<endl;

	while(1)
	{	filin.read((char*)&e,sizeof(e));
		if (filin.eof()) break;
		if(phnoproxy==e.phno)
		{	cout<<"\nRecord deleted"<<endl;
			f6<<"\nRecord deleted"<<endl;
			found='y';
		}
		else
		filout.write((char*)&e,sizeof(e));
	}

	if(found=='n') {
		cout<<"\nRecord not found"<<endl;
		f6<<"\nRecord not found"<<endl;
	}

	filin.close();
	filout.close();

	remove("C:\\Jdata\\emp.dat");
	rename("C:\\Jdata\\temp.dat","C:\\Jdata\\emp.dat");
	f6.close();
	list();
}


void modify()
{       employee e;
	char found ='n';
	char addr[50];
	long proxyno;
	fstream filin, f7;
	void list();
	long pos;

	f7.open("C:\\Jdata\\CSJOURQ9.txt", ios::app);

	cout<<"Enter phone number to be modified: ";
	cin>>proxyno;
	f7<<"Enter phone number to be modified: "<<proxyno<<endl;

	filin.open("C:\\Jdata\\emp.dat", ios::binary|ios::in|ios::out);
	filin.seekg(0);


	while(1)
	{       pos=filin.tellg();
		filin.read((char*)&e,sizeof(e));
		if (filin.eof()) break;
		if(proxyno==e.phno)
		{	cout<<"Enter new address: ";
			gets(addr);
			f7<<"Enter new address: "<<addr<<endl;
			strcpy(e.address,addr);
			filin.seekg(pos);
			filin.write((char*)&e,sizeof(e));
			found='y';
			cout<<"\nRecord updated"<<endl;
			f7<<"\nRecord updated"<<endl;
			break;
		}

	}
	filin.close();

	if(found=='n') {
		cout<<"\nRecord not found";  cout<<endl;
		f7<<"\nRecord not found";  cout<<endl;
	}
	f7.close();
	list();
}

void list()
{
	employee e;
	fstream filin, f5;

	cout<<"\nDirectory :"<<endl;
	f5.open("C:\\Jdata\\CSJOURQ9.txt", ios::app);
	f5<<"\nDirectory :"<<endl;


	filin.open("C:\\Jdata\\emp.dat", ios::binary|ios::in);
	while(1)
	{   	 filin.read((char*)&e,sizeof(e));
		 if(filin.eof()) break;
		 cout<<e.name<<"\t"<<e.phno<<"\t"<<e.address<<endl;
		 f5<<e.name<<"\t"<<e.phno<<"\t"<<e.address<<endl;
	}
	filin.close();
	cout<<endl;
	f5<<endl;
	f5.close();

}
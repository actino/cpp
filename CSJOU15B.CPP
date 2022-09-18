#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>

class Linear_queue
{
	char *names[100];  //An array of 100 pointers
	int front,rear,n;
	char *name;	   //Pointer to character array
	fstream f1;

	public:
	Linear_queue()
	{	front=-1;
		rear=-1;
		n=100;
	}

	void insert()
	{
		name = new char[30];  //Dynamic allocation of memory for a new name
		
		if(rear==n-1) {
			cout<<"Queue overflow. Unable to insert."<<endl;
		} else {
			if(rear==-1) 	{
				front=0;
				rear=0;
			} else {
				rear++;
			}
			f1.open("C:\\Jdata\\CSJOUQ15.txt", ios::app);
			cout<<"Enter a Name: ";
			gets(name);
			f1<<"Enter a Name: "<<name<<endl;
			f1.close();
			names[rear] = name;
			display();
		}
		
		
	}

	void Delete()
	{
		if(front==-1) {
			cout<<"Queue empty."<<endl;
			f1.open("C:\\Jdata\\CSJOUQ15.txt", ios::app);
			f1<<"Queue empty."<<endl;
			f1.close();
			
		}
		else {
			cout<<"Deleting..."<<names[front]<<endl;
			f1.open("C:\\Jdata\\CSJOUQ15.txt", ios::app);
			f1<<"Deleting..."<<names[front]<<endl;
			f1.close();

			if(front==rear)	{
				front=-1;
				rear=-1;
			} else 	{
				front++;
			}
			display();
		}
	}

	void display()
	{
		f1.open("C:\\Jdata\\CSJOUQ15.txt", ios::app);
		
		if(rear!=-1)
			for(int i=front; i<=rear; i++) {
				cout<<names[i]<<endl;
				f1<<names[i]<<endl;
			}
		else {
			cout<<"Queue empty."<<endl;
			f1<<"Queue empty."<<endl;
		}
		
		f1.close();
	}
};

void main()
{
	clrscr();
	Linear_queue obj;
	int choice;
	fstream f1;

	cout<<"\nXII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 15 - Operation on Linear Queue"<<endl;

	f1.open("C:\\Jdata\\CSJOUQ15.txt", ios::app);
	f1<<"\n\nXII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 15 - Operation on Linear Queue"<<endl<<endl;
	f1.close();

	do{
		choice=0;
		cout<<endl;
		cout<<"\nMAIN MENU"<<endl;
		cout<<"1.Insert"<<"\t"<<"2.Delete"<<"\t"<<"3.Display status"<<"\t"<<"4.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		
		f1.open("C:\\Jdata\\CSJOUQ15.txt", ios::app);
		f1<<endl;
		f1<<"\nMAIN MENU"<<endl;
		f1<<"1.Insert"<<"\t"<<"2.Delete"<<"\t"<<"3.Display status"<<"\t"<<"4.Exit"<<endl;
		f1<<"Enter choice: "<<choice<<endl;
		f1.close();

		switch (choice)
		{	case 1: obj.insert();
				break;

			case 2: obj.Delete();
				break;

			case 3: obj.display();
				break;

			case 4: exit(0);
				break;

			default:cout<<"Invalid option!"<<endl;
				break;
		}
	} while(1);
}
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>

struct qelement
{	char name[10];
	int empno;
	float salary;
	qelement *next;
};

class LinkQ
{  	qelement *front,*rear,*newptr, *ptr;
	fstream f1;

	public:

	LinkQ()
	{	front=NULL;
		rear=NULL;
		newptr=NULL;
	}

	int insert()
	{
		ptr = createNode();
		if (ptr == NULL) {
			cout<<"Memory overflow!"<<endl;
			return -1;
		} else {
			if(rear==NULL){
				front=ptr;
				rear=ptr;
			} else {
				rear->next=ptr;
				rear=ptr;
			}
			return 0;
		}
	}

	qelement* createNode()
	{
		newptr=new qelement;

		f1.open("C:\\Jdata\\CSJOUQ18.txt", ios::app);
		cout<<"Employee No: ";
		cin>>newptr->empno;
		f1<<"Employee No: "<<newptr->empno<<endl;
		cout<<"Employee name: ";
		gets(newptr->name);
		f1<<"Employee name: "<<newptr->name<<endl;
		cout<<"Salary: ";
		cin>>newptr->salary;
		f1<<"Salary: "<<newptr->salary<<endl;
		f1.close();
		
		newptr->next=NULL;

		return newptr;
	}

	int Delete()
	{	qelement *tmp;
		int r=0;

		f1.open("C:\\Jdata\\CSJOUQ18.txt", ios::app);
		if (front==NULL) {
			cout<<"Queue empty";
			f1<<"Queue empty";
			r = -1;
		} else {
			tmp=front;
			cout<<"Deleting...."<<endl;
			cout<<tmp->empno<<"\t"<<tmp->name<<"\t"<<tmp->salary<<endl;
			f1<<"Deleting...."<<endl;
			f1<<tmp->empno<<"\t"<<tmp->name<<"\t"<<tmp->salary<<endl;
			
			if(front==rear) {	
				front=NULL;
				rear=NULL;
			} else {	
				front=front->next;
			}
			delete tmp;
			r = 0;
		}
		f1.close();
		return r;
	}

	void display()
	{	
		qelement *temp=front;
		f1.open("C:\\Jdata\\CSJOUQ18.txt", ios::app);
		cout<<endl;
		f1<<endl;
		while(temp!=NULL)
		{	cout<<temp->empno<<"\t"<<temp->name<<"\t"<<temp->salary<<endl;
			f1<<temp->empno<<"\t"<<temp->name<<"\t"<<temp->salary<<endl;
			temp=temp->next;
		}
		f1.close();
	}
};


void main()
{	
	clrscr();
	int choice, ret;
	LinkQ ob;
	fstream f1;

	cout<<"\nXII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 18 - Operation on Linked Queue"<<endl<<endl;

	f1.open("C:\\Jdata\\CSJOUQ18.txt", ios::app);
	f1<<"\n\nXII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 18 - Operation on Linked Queue"<<endl<<endl;
	f1.close();
	
	do{
		choice=0;
		cout<<"\n\nMAIN MENU"<<endl;
		cout<<"1.Insert"<<"\t"<<"2.Delete"<<"\t"<<"3.Display Status"<<"\t"<<"4.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;

		f1.open("C:\\Jdata\\CSJOUQ18.txt", ios::app);
		f1<<"\n\nMAIN MENU"<<endl;
		f1<<"1.Insert"<<"\t"<<"2.Delete"<<"\t"<<"3.Display Status"<<"\t"<<"4.Exit"<<endl;
		f1<<"Enter choice: "<<choice<<endl;
		f1.close();
		
		switch (choice)
		{	case 1: ret = ob.insert();
				if (ret == 0) {
				    f1.open("C:\\Jdata\\CSJOUQ18.txt", ios::app);
					cout<<"Updated Linked Queue...";
					f1<<"Updated Linked Queue...";
					f1.close();
				    ob.display();
				}
				break;

			case 2: ret = ob.Delete();
				if (ret == 0) {
					f1.open("C:\\Jdata\\CSJOUQ18.txt", ios::app);
					cout<<"Updated Linked Queue...";
					f1<<"Updated Linked Queue...";
					f1.close();
					ob.display();
				}
				break;

			case 3: ob.display();
				break;

			case 4: exit(0);
				break;

			default: cout<<"Invalid option!"<<endl;
				break;
		}
	} while(1);
}


#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct queue
{	char name[10];
	int empno;
	float salary;
	queue *next;
};

class LinkQ
{  	queue *front,*rear,*newptr;

	public:

	LinkQ()
	{	front=NULL;
		rear=NULL;
		newptr=NULL;
	}

	void insert()
	{	newptr=new queue;

		cout<<"Employee No: ";
		cin>>newptr->empno;
		cout<<"Employee name: ";
		gets(newptr->name);
		cout<<"Salary: ";
		cin>>newptr->salary;
		newptr->next=NULL;


		if(rear==NULL)
		{
			front=newptr;
			 rear=newptr;
		}
		else
		{	rear->next=newptr;
			rear=newptr;
		}
	}

	void Delete()
	{	queue *tmp;
		//tmp=front;

		if (front==NULL)
			cout<<"Queue empty";
		else {
			tmp=front;
			cout<<"DELETING...."<<endl;
			cout<<tmp->empno<<"\t"<<tmp->name<<"\t"<<tmp->salary<<endl;

			if(front==rear)
			{	front=NULL;
				rear=NULL;
				//delete tmp;
			}
			else
			{	front=front->next;
				//delete tmp;
				//tmp=front;
			}
			delete tmp;
		}
	}

	void display()
	{	queue *temp=front;
		cout<<endl;
		while(temp!=NULL)
		{	cout<<temp->empno<<"\t"<<temp->name<<"\t"<<temp->salary<<endl;
			temp=temp->next;
		}
	}
};


void main()
{	clrscr();
	int choice;
	LinkQ ob;


	do{
		choice=0;
		cout<<endl;
		cout<<"MAIN MENU"<<endl;
		cout<<"1.Insert"<<"\t"<<"2.Delete"<<"\t"<<"3.Display Status"<<"\t"<<"4.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;


		switch (choice)
		{	case 1: ob.insert();
				cout<<"Updated records...";
				ob.display();
				break;

			case 2: ob.Delete();
				cout<<"Updated records...";
				ob.display();
				break;

			case 3: ob.display();
				break;

			default: exit(0);
				 break;
		}
	} while(1);
}


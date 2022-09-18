#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdio.h>

class Linear_queue
{	int queue[100];
	int front,rear,n;

	public:
	Linear_queue()
	{	front=-1;
		rear=-1;
		n=100;
	}

	void insert()
	{	if(rear==n-1)
			cout<<"Queue full unable to insert."<<endl;
		else if(rear==-1)
		{	front=0;
			rear=0;
			cout<<"Enter name A:";  cin>>queue[rear];
			//cin.getline(queue[rear],30);
		}
		else
		{	rear++;
			cout<<"Enter name B:";   cin>>queue[rear];
			//cin.getline(queue[rear],30);
		}

	}

	void Delete()
	{	if(front==-1)
			cout<<"Queue empty: ";
		else if(front==rear)
		{	cout<<"Deleting.. "<<queue[front]<<endl;
			front=-1;
			rear=-1;
		}
		else
		{    cout<<"Deleting.. "<<queue[front]<<endl;
		     front++;
		}
	}
	void display()
	{	for(int i=front;i<=rear;i++)
			cout<<queue[i]<<endl;
	}
};

void main()
{	clrscr();
	Linear_queue obj;
	char choice;

	do{
		choice=0;
		cout<<endl;
		cout<<"MAIN MENU"<<endl;
		cout<<"1.Insert"<<" "<<"2.Delete"<<" "<<"3.Display"<<" "<<"4.Exit"<<endl;
		cout<<"Enter choice: ";
		//choice=getchar();
		cin>>choice;
		//cin.clear();
		switch (choice)
		{	case 1:
				obj.insert();
				obj.display();
				//getch();
				break;

			case 2: obj.Delete();
				  obj.display();
				  break;

			case 3: obj.display();
				break;

			default:
				exit(0);
				break;
		}
	} while(1);
}
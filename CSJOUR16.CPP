#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>

class cir_queue
{	int value[10];
	int front,rear,n;

	public:
	cir_queue()
	{	front=-1;
		rear=-1;
		n=10;
	}

	void insert()
	{
		if((rear==n-1&&front==0)||(front==rear+1))
			cout<<"Queue overflow. Unable to insert."<<endl;
		else {
			if(rear==-1){
				front=0;
				rear=0;
			} else if(rear==n-1) {
				rear=0;
			} else {
				rear++;
			}
			cout<<"Enter no: ";
			cin>>value[rear];
			"Insert successful.";
			display();
		}
	}

	void Delete()
	{
		if(front==-1) {
			cout<<"Queue empty.";
		} else {
			cout<<"Deleting.. "<<value[front]<<endl;
			if(front==rear) {
				front=-1;
				rear=-1;
			} else if(front==n-1) {
				front=0;
			} else {
				front++;
			}
			display();
		}
	}

	void display()
	{
		int i;
		cout<<"\nCircular Queue is => \n"
			<<"(Front shown as >>>, Rear as <<< AND free space as -)\n";

		if (front==-1)
			cout<<"Queue empty.";
		else {
			if(rear >= front)
			{
				for (i=0; i<front; i++) cout<<"-";   //Empty spaces before front
				cout<<">>>";	//Point to Front

				for(i=front;i<rear;i++)
					cout<<value[i]<<" <- ";		//Print elements
				cout<<value[rear]<<"<<<"<<endl;	//Point to Rear
			} else {

				for (i=0; i<rear; i++)
					cout<<value[i]<<" <-";
				cout<<value[rear]<<"<<<";
				for (; i<front; i++)
					cout<<"-";
				cout<<">>>";
				for (i=front; i<n; i++)
					cout<<value[i]<<" <-";
				cout<<"\t...wrap around...";
					
			}				
		}
	}
};

void main()
{	
	clrscr();
	cir_queue obj;
	int choice;
	
	cout<<"\nXII Computer Science Journal(2019-2020)"<<endl;	
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 16 - Implementation of Linear Circular Queue"<<endl<<endl;
	
	do{
		choice=0;
		cout<<endl;
		cout<<"\nMAIN MENU"<<endl;
		cout<<"1.Insert"<<"  "<<"2.Delete"<<"  "<<"3.Display status"<<"  "<<"4.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;

		switch (choice)
		{	case 1: obj.insert();
				break;

			case 2: obj.Delete();				
				break;

			case 3: obj.display();
				break;

			case 4:
				exit(0);
				break;
			
			default:
				cout<<"Invalid choice!";
				break;
		}
	} while(1);
}
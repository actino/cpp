#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<fstream.h>

class cir_queue
{	int value[10];
	int front,rear,n;
	fstream f1;

	public:
	cir_queue()
	{	front=-1;
		rear=-1;
		n=10;
	}

	void insert()
	{
		f1.open("C:\\Jdata\\CSJOUQ16.txt", ios::app);

		if((rear==n-1&&front==0)||(front==rear+1)) {
			cout<<"Queue overflow. Unable to insert."<<endl;
			f1<<"Queue overflow. Unable to insert."<<endl;
			f1.close();
		} else {
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
			cout<<"Insert successful.";
			f1<<"Enter no: "<<value[rear]<<endl;
			f1<<"Insert successful.";
			f1.close();
			display();
		}
	}

	void Delete()
	{
		f1.open("C:\\Jdata\\CSJOUQ16.txt", ios::app);

		if(front==-1) {
			cout<<"Queue empty.";
			f1<<"Queue empty.";
			f1.close();
		} else {
			cout<<"Deleting.. "<<value[front]<<endl;
			f1<<"Deleting.. "<<value[front]<<endl;
			f1.close();
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

		f1.open("C:\\Jdata\\CSJOUQ16.txt", ios::app);

		cout<<"\nCircular Queue is => \n"
			<<"(Front shown as >>>, Rear as <<< AND free space as -)\n";

		f1<<"\nCircular Queue is => \n"
			<<"(Front shown as >>>, Rear as <<< AND free space as -)\n";


		if (front==-1) {
			cout<<"Queue empty.";
			f1<<"Queue empty.";
		} else {
			if(rear >= front)
			{
				for (i=0; i<front; i++) {cout<<"-"; f1<<"-";}  //Empty spaces before front
				cout<<">>>";	//Point to Front
				f1<<">>>";

				for(i=front;i<rear;i++) {
					cout<<value[i]<<" <- ";		//Print elements
					f1<<value[i]<<" <- ";
				}
				cout<<value[rear]<<"<<<"<<endl;	//Point to Rear
				f1<<value[rear]<<"<<<"<<endl;
			} else {

				for (i=0; i<rear; i++) {
					cout<<value[i]<<" <-";
					f1<<value[i]<<" <-";
				}
				cout<<value[rear]<<"<<<";
				f1<<value[rear]<<"<<<";
				for (; i<front; i++) {
					cout<<"-"; f1<<"-";
				}
				cout<<">>>";
				f1<<">>>";
				for (i=front; i<n; i++) {
					cout<<value[i]<<" <-";
					f1<<value[i]<<" <-";
				}
				cout<<"\t...wrap around...";
				f1<<"\t...wrap around...\n";

			}
		}
		f1.close();
	}
};

void main()
{	
	clrscr();
	cir_queue obj;
	int choice;
	fstream f1;
	
	cout<<"\nXII Computer Science Journal(2019-2020)"<<endl;	
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 16 - Implementation of Linear Circular Queue"<<endl<<endl;
	
	f1.open("C:\\Jdata\\CSJOUQ16.txt", ios::app);
	f1<<"\n\nXII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 16 - Implementation of Linear Circular Queue"<<endl<<endl;
	f1.close();
	
	do{
		choice=0;
		cout<<"\nMAIN MENU"<<endl;
		cout<<"1.Insert"<<"  "<<"2.Delete"<<"  "<<"3.Display status"<<"  "<<"4.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		
		f1.open("C:\\Jdata\\CSJOUQ16.txt", ios::app);
		f1<<"\nMAIN MENU"<<endl;
		f1<<"1.Insert"<<"  "<<"2.Delete"<<"  "<<"3.Display status"<<"  "<<"4.Exit"<<endl;
		f1<<"Enter choice: "<<choice<<endl;
		f1.close();

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
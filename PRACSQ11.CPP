#include<iostream.h>
#include<conio.h>

int front=-1,rear=-1;
void insert(int arr[],int size)
{       if(rear==-1)
	{ rear=front=0;
	  cout<<"Enter element to be added: ";
	  cin>>arr[rear];
	}
	else if(rear==size-1)
	{	cout<<"Queue full: ";
	}
	else
	{       rear++;
		cout<<"Enter element to be added: ";
		cin>>arr[rear];
	}
}

void remove(int arr[],int size)
{	if(front==-1)
	cout<<"Empty.";
	else if(front==rear)
	{	cout<<"Deleting..."<<arr[front];
		front==-1;
		rear==-1;
	}
	else
	{       cout<<"Deleting..."<<arr[front]<<endl;
		front++;
	}
}

void display(int arr[],int front,int rear)
{       int i;
	for(i=front;i<=rear;i++)
	cout<<arr[i]<<"\t";
	cout<<endl;
}


void main()
{       clrscr();
	int choice;
	//int top=-1;
	char ans='y';
	int A[50];
	do{
	cout<<"MENU"<<endl<<"1.Insert"<<"\t"<<"2.Remove"<<"\t"<<"3.Display"<<endl;
	cin>>choice;

	switch(choice){

		case 1: insert(A,50);
			display(A,front,rear);
			cout<<"Continue(y/n)?";
			cin>>ans;
			break;

		case 2: remove(A,50);
			display(A,front,rear);
			cout<<"Continue(y/n)?";
			cin>>ans;
			break;

		case 3: display(A,front,rear);
			cout<<"Continue(y/n)?";
			cin>>ans;
			break;

	}}while(ans=='y');
}
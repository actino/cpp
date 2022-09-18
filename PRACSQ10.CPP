#include<iostream.h>
#include<conio.h>


void push(int arr[],int size,int&top)
{       int n;
	//int top=-1;
	if(top==size-1)
	cout<<"Stack full";
	else
	{  top++;
	   cout<<"Enter number to be pushed: ";
	   cin>>n;
	   arr[top]=n;
	}
}

void pop(int arr[],int n,int&top)
{	//int top=n-1;
	if(top==-1)
	cout<<"Stack empty.";
	else
	{	cout<<"Deleting...."<<arr[top]<<endl;
		top--;
	}
}

void display(int arr[],int n,int top)
{      for(int i=top;i>=0;i--)
	cout<<arr[i]<<"\t";
	cout<<endl;
}

void main()
{       clrscr();
	int choice;
	int top=-1;
	char ans='y';
	int A[50];
	do{
	cout<<"MENU"<<endl<<"1.PUSH"<<"\t"<<"2.POP"<<"\t"<<"3.DISPLAY"<<endl;
	cin>>choice;

	switch(choice){

		case 1: push(A,50,top);
			display(A,50,top);
			cout<<"Continue(y/n)?";
			cin>>ans;
			break;

		case 2: pop(A,50,top);
			display(A,50,top);
			cout<<"Continue(y/n)?";
			cin>>ans;
			break;

		case 3: display(A,50,top);
			cout<<"Continue(y/n)?";
			cin>>ans;
			break;

	}}while(ans=='y');
}
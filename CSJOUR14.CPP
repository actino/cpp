#include<iostream.h>
#include<conio.h>
#include<process.h>

class Linear_stack
{	float stack[100];
	int top,n;

	public:
	Linear_stack()
	{	top=-1;
		n=100;
	}

	void push()
	{	if(top==n-1)
			cout<<"Stack overflow. Unable to insert."<<endl;
		else
		{	top++;
			cout<<"Enter element to be inserted: ";
			cin>>stack[top];
		      //	stack[top]=e ;
		}
	}
	
	void pop()
	{	if(top==-1)
			cout<<"Stack empty."<<endl;
		else
		{	cout<<"Element being popped: ";
			cout<<stack[top]<<endl;
			top--;
		}
	}
	
	void dele()
	{   	float element;
		int proxytop=-1;
		int i;
		float proxystack[100];
		cout<<"Enter element to delete: ";
		cin>>element;
		for(i=top;i>=0;i--)
		{	if(stack[i]!=element)
			{
				proxytop++;
				proxystack[proxytop]=stack[i];

			}
		}

		top=-1;

		for(i=proxytop;i>=0;i--)
		{	top++;
			stack[top]=proxystack[i];
		}
		cout<<"New stack: \n";
		display();

	}
	
	void display()
	{	for(int i=top;i>=0;i--)
			cout<<stack[i]<<"\n";
	}
};

void main()
{	clrscr();
	Linear_stack obj;
	int choice;

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 14 - Operations on Linear Stack"<<endl<<endl;

	do{
		choice=0;
		cout<<endl;
		cout<<"MAIN MENU"<<endl;
		cout<<"1.Push\t"<<"2.Pop\t"<<"3.Delete Element\t"<<"4.Display\t"<<"5.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;

		switch (choice)
		{	case 1: obj.push();
				obj.display();
				break;

			case 2: obj.pop();
				obj.display();
				break;

			case 3: obj.dele();
				break;

			case 4: obj.display();
				break;

			case 5: exit(0);
				break;

			default:cout<<"Invalid option!"<<endl;
				break;
		}
	} while(1);
}
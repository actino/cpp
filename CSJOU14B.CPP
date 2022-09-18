#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>

class Linear_stack
{	float stack[100];
	int top,n;
	fstream f1;

	public:
	Linear_stack()
	{	top=-1;
		n=100;
	}

	void push()
	{	
		f1.open("C:\\Jdata\\CSJOUQ14.txt", ios::app);
		if(top==n-1) {
			cout<<"Stack overflow. Unable to insert."<<endl;
			f1<<"Stack overflow. Unable to insert."<<endl;
		} else
		{	top++;
			cout<<"Enter element to be inserted: ";
			cin>>stack[top];
		    f1<<"Enter element to be inserted: "<<stack[top]<<endl;
		}
		f1.close();
	}
	
	void pop()
	{	
		f1.open("C:\\Jdata\\CSJOUQ14.txt", ios::app);
		if(top==-1) {
			cout<<"Stack empty."<<endl;
			f1<<"Stack empty."<<endl;
		} else
		{	cout<<"Element being popped: ";
			cout<<stack[top]<<endl;
			f1<<"Element being popped: "<<stack[top]<<endl;
			top--;
		}
		f1.close();
	}
	
	void dele()
	{   
		float element;
		int proxytop=-1;
		int i;
		float proxystack[100];
		
		f1.open("C:\\Jdata\\CSJOUQ14.txt", ios::app);
		cout<<"Enter element to delete: ";
		cin>>element;
		f1<<"Enter element to delete: "<<element<<endl;
		
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
		f1<<"New stack: \n";
		f1.close();
		display();

	}
	
	void display()
	{	
		f1.open("C:\\Jdata\\CSJOUQ14.txt", ios::app);
		for(int i=top;i>=0;i--) {
			cout<<stack[i]<<"\n";
			f1<<stack[i]<<"\n";
		}
		f1.close();
	}
};

void main()
{	clrscr();
	Linear_stack obj;
	int choice;
	fstream f1;

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 14 - Operations on Linear Stack"<<endl<<endl;
	f1.open("C:\\Jdata\\CSJOUQ14.txt", ios::app);
	f1<<"\n\nXII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 14 - Operations on Linear Stack"<<endl<<endl;
	f1.close();
	
		do{
		choice=0;
		cout<<endl;
		cout<<"MAIN MENU"<<endl;
		cout<<"1.Push\t"<<"2.Pop\t"<<"3.Delete Element\t"<<"4.Display\t"<<"5.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		f1.open("C:\\Jdata\\CSJOUQ14.txt", ios::app);
		f1<<"\nMAIN MENU"<<endl;
		f1<<"1.Push\t"<<"2.Pop\t"<<"3.Delete Element\t"<<"4.Display\t"<<"5.Exit"<<endl;
		f1<<"Enter choice: "<<choice<<endl;
		f1.close();

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
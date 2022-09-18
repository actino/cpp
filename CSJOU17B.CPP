#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>

struct stack
{	char c;
	stack *next;
};

class string
{  	stack *top,*newptr;
	fstream f1;

	public:

	string()
	{	top=NULL;
		newptr=NULL;
	}

	void push(char ch)
	{	newptr=new stack;
		newptr->c=ch;

		if(top==NULL) 	{
			top=newptr;
		}
		else {
			newptr->next=top;
			top=newptr;
		}
	}

	void pop()
	{	stack *tmp;
		f1.open("C:\\Jdata\\CSJOUQ17.txt", ios::app);
		while(1)
		{
			if(top==NULL)
				break;
			tmp=top;
			cout<<tmp->c;
			f1<<tmp->c;
			top=top->next;
			delete tmp;
		
		}
		f1.close();
	}
};

void main()
{	clrscr();
	int l,i;
	char str[100];
	string ob;
	fstream f1;

	cout<<"\nXII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 17 - Reversing a string using a Linked Stack"<<endl<<endl;

	f1.open("C:\\Jdata\\CSJOUQ17.txt", ios::app);
	f1<<"\n\nXII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 17 - Reversing a string using a Linked Stack"<<endl<<endl;
	
	cout<<"Enter string: ";
	gets(str);
	f1<<"Enter string: "<<str<<endl;
	
	l=strlen(str);

	for(i=0;i<l;i++)
	{	ob.push(str[i]);

	}

	cout<<"Reversed string: ";
	f1<<"Reversed string: ";
	f1.close();
	ob.pop();
	getch();
}
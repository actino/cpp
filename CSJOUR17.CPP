#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

struct stack
{	char c;
	stack *next;
};

class string
{  	stack *top,*newptr;

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
		while(1)
		{
			if(top==NULL)
				break;
			tmp=top;
			cout<<tmp->c;
			top=top->next;
			delete tmp;
		}
	}
};

void main()
{	clrscr();
	int l,i;
	char str[100];
	string ob;

	cout<<"\nXII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 17 - Reversing a string using a Linked Stack"<<endl<<endl;

	cout<<"Enter string: ";
	gets(str);
	l=strlen(str);

	for(i=0;i<l;i++)
	{	ob.push(str[i]);

	}

	cout<<"Reversed string: ";
	ob.pop();
	getch();
}
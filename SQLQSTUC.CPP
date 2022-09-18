#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

struct book
{	int bookno;
	int price;
	char bookname[40];
};

int front=-1;
int rear=-1;
const int size=3;
book A[size];

void insert()
{	if (rear==size-1)
	{	cout<<"Overflow";
	}
	else if(rear==-1)
	{	front=0;rear=0;
		cin>>A[rear].bookno>>A[rear].price;
		gets(A[rear].bookname);
		cout<<A[rear].bookno<<"\t"<<A[rear].price<<endl<<A[rear].bookname;
	}
	else
	{	rear++;
		cin>>A[rear].bookno>>A[rear].price;
		gets(A[rear].bookname);
		cout<<A[rear].bookno<<"\t"<<A[rear].price<<endl<<A[rear].bookname;
	}
}

void main()
{       clrscr();
	int i;
	for(i=0;i<3;i++)
	{	cout<<"Book no: ";
		cin>>A[i].bookno;
		cout<<"Book price: ";
		cin>>A[i].price;
		cout<<"Book name: ";
		cin.getline(A[i].bookname,40);
	}

	for(i=0;i<3;i++)
		insert();

       //	cout<<endl;

      //	for(i=0;i<=rear;i++)
      //		cout<<A[i].bookno<<"\t"<<A[i].price<<"\t"<<A[i].bookname<<endl;
	getch();
}
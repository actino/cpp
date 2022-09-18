#include<iostream.h>
#include<conio.h>

int front=-1,rear=-1;
void insert(int arr,int size)
{	if((front==0&&rear==size-1))||(front==rear+1))
	{	cout<<"Full";
	}
	else if(rear=size-1)
	{	rear=0;
	}
	else if(rear==-1)
	{	front=rear=0;
	}
	else	rear++;
	cout<<"Entaer:";
	cin>>arr[rear];
}

void remove(int arr,int size)
{	if(front==-1)
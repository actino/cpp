#include<iostream.h>
#include<conio.h>
class stack
{	int data[10];
	int top;
	public:
	stack()	{top=-1};
	void push();
	void pop();
}

void stack::push()
{	if(top==9)
	cout<<"Stack full";
	else
	{    	top++;
		cin>>data[top];
		for(int i=top;i>=0;i--)
		cout<<A[i]<<"\t";
		cout<<endl;
	}
}

/*void deleteS(int A[], int &top)
{	if(top==-1)
	cout<<"Stack empty";
	else
	{	int temp;
		cout<<A[top]<<endl;
		top--;
	}
	for(int i=top;i>=0;i--)
	cout<<A[i]<<"\t";
	cout<<endl;
}*/

void main()
{	clrscr();
   /*	int stack[size];
	int topele=-1,element,choice;
	char ch='y';

	while(ch=='y'||ch=='Y')
	{	cout<<"1.Insert\n"<<"2.Delete\n"<<"Enter choice\n";
		cin>>choice;

		switch(choice)
		 {	case 1: cout<<"Enter element to add: ";
				cin>>element;
				insert(stack,topele,element);
				cout<<"Do you want to continue?(y/n)  ";
				cin>>ch;
				break;
			case 2:// cout<<"Enter element to delete: ";
				//cin>>element;
				deleteS(stack,topele);
				cout<<"Do you want to continue?(y/n)  ";
				cin>>ch;
				break;
		}
	} */
      //	getch();
      stack obj;
      obj.push();
}
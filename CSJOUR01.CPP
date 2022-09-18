#include<iostream.h>
#include<conio.h>
#include<stdio.h>

struct address
{
	int doorno;
	char street[10], city[10], state[10];
	long pin;
};

class bill
{
	int custno, units, rent;
	char name[30];
	address addr;
	float amount;

	public:
		int read()
		{
			cout<<"Enter customer no: ";
			cin>>custno;
			cout<<"Enter name: ";
			gets(name);
			cout<<"Enter units: ";
			cin>>units;
			cout<<"Enter door No: ";
			cin>>addr.doorno;
			cout<<"Enter street: ";
			gets(addr.street);
			cout<<"Enter city: ";
			gets(addr.city);
			cout<<"Enter state: ";
			gets(addr.state);
			cout<<"Enter pin: ";
			cin>>addr.pin;
			cout<<endl;

			rent=200;
			return 0;
		}

		int calculate()
		{
			if (units<=50)
				amount=units*2.0;
			else if (units<=150)
				amount=50*2.0+(units-50.0)*2.25;
			else if (units<=250)
				amount=50*2.0+100*2.25+(units-150.0)*2.50;
			else
				amount=50*2.0+100*2.25+100*2.50+(units-250.0)*3.50;

			amount+=rent;
			return amount;
		}

		int display()
		{
			cout<<"*--------------------------------------------------------------------"<<endl;
			cout<<"|\tMAHARASHTRA ELECTRICITY BOARD"<<endl;
			cout<<"|\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"|      Consumer number: "<<custno; cout<<endl;
			cout<<"|        Consumer name: "<<name; cout<<endl;
			cout<<"|              Address: "<<addr.doorno<<", "<<addr.street<<endl;
			cout<<"|                       "<<addr.city<<", "<<addr.state<<" "<<addr.pin<<endl;
			cout<<"|No. of units consumed: "<<units; cout<<endl;
			cout<<"|          Bill amount: Rs. "<<amount; cout<<endl;
			cout<<"*--------------------------------------------------------------------"<<endl;
			return 0;
		}
};

void main()
{
	clrscr();
	bill customer[10];
	int i,n;
	cout<<"Enter number of customers : ";
	cin>>n;

	for (i=0; i<n; i++)
	{ customer[i].read();
	  customer[i].calculate();
	  customer[i].display();
	  getch();
	  clrscr();
	}

}
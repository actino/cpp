#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>

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
	fstream f2;

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

			f2.open("C:\\Jdata\\CSJOURQ1OUT.txt", ios::app);
			f2<<"Enter customer no: "<<custno<<endl;
			f2<<"Enter name: "<<name<<endl;
			f2<<"Enter units: "<<units<<endl;
			f2<<"Enter door No: "<<addr.doorno<<endl;
			f2<<"Enter street: "<<addr.street<<endl;
			f2<<"Enter city: "<<addr.city<<endl;
			f2<<"Enter state: "<<addr.state<<endl;
			f2<<"Enter pin: "<<addr.pin<<endl<<endl;
			f2.close();

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

			cout<<"*-------------------------------------------------------------------	-"<<endl;
			cout<<"|\tMAHARASHTRA ELECTRICITY BOARD"<<endl;
			cout<<"|\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"|      Consumer number: "<<custno;cout<<endl;
			cout<<"|        Consumer name: "<<name;cout<<endl;
			cout<<"|              Address: "<<addr.doorno<<", "<<addr.street<<endl;
			cout<<"|                       "<<addr.city<<", "<<addr.state<<" "<<addr.pin<<endl;
			cout<<"|No. of units consumed: "<<units;cout<<endl;
			//cout<<"Door No: "<<addr.doorno; cout<<endl;
			//cout<<"Street: "<<addr.street; cout<<endl;
			//cout<<"City: "<<addr.city; cout<<endl;
			//cout<<"State: "<<addr.state; cout<<endl;
			//cout<<"Pin: "<<addr.pin; cout<<endl;
			//cout<<"Rent: "<<rent; cout<<endl;
			cout<<"|          Bill amount: Rs. "<<amount; cout<<endl;
			cout<<"*--------------------------------------------------------------------"<<endl;

			f2.open("C:\\Jdata\\CSJOURQ1OUT.txt", ios::app);
			f2<<"*--------------------------------------------------------------------"<<endl;
			f2<<"|\tMAHARASHTRA ELECTRICITY BOARD"<<endl;
			f2<<"|\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			f2<<"|      Consumer number: "<<custno<<endl;
			f2<<"|        Consumer name: "<<name<<endl;
			f2<<"|              Address: "<<addr.doorno<<", "<<addr.street<<endl;
			f2<<"|                       "<<addr.city<<", "<<addr.state<<" "<<addr.pin<<endl;
			f2<<"|No. of units consumed: "<<units<<endl;
			f2<<"|          Bill amount: Rs. "<<amount<<endl;
			f2<<"*--------------------------------------------------------------------"<<endl<<endl;
			f2.close();

			return 0;
		}
};

void main()
{
	clrscr();
	fstream f1;
	bill customer[10];
	int i,n;
	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 1 - Electricity Bill"<<endl<<endl;
	cout<<"Enter number of customers : ";
	cin>>n;
	cout<<endl;

	f1.open("C:\\Jdata\\CSJOURQ1OUT.txt", ios::out);
	f1<<"XII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 1 - Electricity Bill"<<endl<<endl;
	f1<<"Enter number of customers : "<<n<<endl;
	f1.close();

	for (i=0; i<n; i++)
	{ customer[i].read();
	  customer[i].calculate();
	  customer[i].display();
	  getch();
	  clrscr();
	}

}
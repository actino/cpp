#include<iostream.h>
#include<conio.h>
#include<process.h>

class interest
{       float principal,rate,SI;
	int period;

	public:
	interest()
	{       principal=5000.00;
		rate=0.07;
		period=3;
		SI=principal*rate*period;
		cout<<"Arguments:: NIL-Default Constructor"<<endl;
		cout<<"Initial Values:: P="<<principal<<" | R="<<rate<<" | t="<<period<<" years"<<endl; 		
		cout<<"Simple Interest: "<<SI;
	}

	interest(float p,float r,int t)
	{       principal=p;
		rate=r;
		period=t;
		SI=principal*rate*period;
		cout<<"Arguments:: P="<<principal<<" | R="<<rate<<" | t="<<period<<" years"<<endl; 
		cout<<"Simple Interest: "<<SI;
	}

	interest(float p,float r)
	{       principal=p;
		rate=r;
		period=3;
		SI=principal*rate*period;
		cout<<"Arguments:: P="<<principal<<" | R="<<rate<<endl; 
		cout<<"Initial Values:: t="<<period<<" years"<<endl; 		
		cout<<"Simple Interest: "<<SI;
	}

	interest(int t)
	{       principal=5000.00;
		rate=0.07;
		period=t;
		SI=principal*rate*period;
		cout<<"Arguments:: t="<<period<<" years"<<endl; 
		cout<<"Initial Values:: P="<<principal<<" | R="<<rate<<endl; 		
		cout<<"Simple Interest: "<<SI;
	}

	interest(float p,int t)
	{       principal=p;
		period=t;
		rate=0.07;
		SI=principal*rate*period;
		cout<<"Arguments:: P="<<principal<<" | t="<<period<<" years"<<endl; 
		cout<<"Initial Values:: R="<<rate<<endl; 		
		cout<<"Simple Interest: "<<SI;
	}

	interest(float p)
	{       principal=p;
		rate=0.07;
		period=3;
		SI=principal*rate*period;
		cout<<"Arguments:: P="<<principal<<endl; 
		cout<<"Initial Values:: R="<<rate<<" | t="<<period<<" years"<<endl; 		
		cout<<"Simple Interest: "<<SI;
	}
};

void main()
{       
	clrscr();
	int  choice;
	char ans='y';

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 5 - Constructor Overloading"<<endl<<endl;

	while(ans=='y'||ans=='Y') {
		cout<<endl;
		cout<<"MAIN MENU"<<endl;
		cout<<"1.Values for none"<<"\t\t"<<"2.Values for all"<<endl<<"3.Values for principal & rate"<<"\t"<<"4.Values for period"<<endl<<"5.Values for principal & period"<<"\t"<<"6.Value for principal"<<endl<<"7.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;

		switch(choice)
		{	case 1: interest ob1;
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				break;
			case 2: interest ob2(6000.00F,0.09F,5);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				break;
			case 3: interest ob3(8000.00F,0.10F);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				break;
			case 4: interest ob4(9);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				break;
			case 5: interest ob5(4000.00F,8);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				break;
			case 6: interest ob6(7000.00F);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				break;
			case 7: exit(0);
				break;
			default: exit(0);
				 break;
		}
	}

	//getch();
}

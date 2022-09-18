#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<fstream.h>

class interest
{       float principal,rate,SI;
	int period;

	public:
	interest()
	{       
		fstream f2;
		principal=5000.00;
		rate=0.07;
		period=3;
		SI=principal*rate*period;
		cout<<"Arguments:: NIL-Default Constructor"<<endl;
		cout<<"Initial Values:: P="<<principal<<" | R="<<rate<<" | t="<<period<<" years"<<endl; 		
		cout<<"Simple Interest: "<<SI;
		f2.open("C:\\Jdata\\CSJOURQ5.txt", ios::app);
		f2<<"Arguments:: NIL-Default Constructor"<<endl;
		f2<<"Initial Values:: P="<<principal<<" | R="<<rate<<" | t="<<period<<" years"<<endl; 		
		f2<<"Simple Interest: "<<SI;
		f2.close();
	}

	interest(float p,float r,int t)
	{       
		fstream f3;
		principal=p;
		rate=r;
		period=t;
		SI=principal*rate*period;
		cout<<"Arguments:: P="<<principal<<" | R="<<rate<<" | t="<<period<<" years"<<endl; 
		cout<<"Simple Interest: "<<SI;
		f3.open("C:\\Jdata\\CSJOURQ5.txt", ios::app);
		f3<<"Arguments:: P="<<principal<<" | R="<<rate<<" | t="<<period<<" years"<<endl; 
		f3<<"Simple Interest: "<<SI;
		f3.close();
	}

	interest(float p,float r)
	{       
		fstream f4;
		principal=p;
		rate=r;
		period=3;
		SI=principal*rate*period;
		cout<<"Arguments:: P="<<principal<<" | R="<<rate<<endl; 
		cout<<"Initial Values:: t="<<period<<" years"<<endl; 		
		cout<<"Simple Interest: "<<SI;
		f4.open("C:\\Jdata\\CSJOURQ5.txt", ios::app);
		f4<<"Arguments:: P="<<principal<<" | R="<<rate<<endl; 
		f4<<"Initial Values:: t="<<period<<" years"<<endl; 		
		f4<<"Simple Interest: "<<SI;
		f4.close();
	}

	interest(int t)
	{       
		fstream f5;
		principal=5000.00;
		rate=0.07;
		period=t;
		SI=principal*rate*period;
		cout<<"Arguments:: t="<<period<<" years"<<endl; 
		cout<<"Initial Values:: P="<<principal<<" | R="<<rate<<endl; 		
		cout<<"Simple Interest: "<<SI;
		f5.open("C:\\Jdata\\CSJOURQ5.txt", ios::app);
		f5<<"Arguments:: t="<<period<<" years"<<endl; 
		f5<<"Initial Values:: P="<<principal<<" | R="<<rate<<endl; 		
		f5<<"Simple Interest: "<<SI;
		f5.close();
	}

	interest(float p,int t)
	{       
		fstream f6;
		principal=p;
		period=t;
		rate=0.07;
		SI=principal*rate*period;
		cout<<"Arguments:: P="<<principal<<" | t="<<period<<" years"<<endl; 
		cout<<"Initial Values:: R="<<rate<<endl; 		
		cout<<"Simple Interest: "<<SI;
		f6.open("C:\\Jdata\\CSJOURQ5.txt", ios::app);
		f6<<"Arguments:: P="<<principal<<" | t="<<period<<" years"<<endl; 
		f6<<"Initial Values:: R="<<rate<<endl; 		
		f6<<"Simple Interest: "<<SI;
		f6.close();
	}

	interest(float p)
	{       
		fstream f7;
		principal=p;
		rate=0.07;
		period=3;
		SI=principal*rate*period;
		cout<<"Arguments:: P="<<principal<<endl; 
		cout<<"Initial Values:: R="<<rate<<" | t="<<period<<" years"<<endl; 		
		cout<<"Simple Interest: "<<SI;
		f7.open("C:\\Jdata\\CSJOURQ5.txt", ios::app);
		f7<<"Arguments:: P="<<principal<<endl; 
		f7<<"Initial Values:: R="<<rate<<" | t="<<period<<" years"<<endl; 		
		f7<<"Simple Interest: "<<SI;
		f7.close();
	}
};

void main()
{       
	clrscr();
	int  choice;
	fstream f1;
	char ans='y';

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 5 - Constructor Overloading"<<endl<<endl;

	f1.open("C:\\Jdata\\CSJOURQ5.txt", ios::out);
	f1<<"XII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 5 - Constructor Overloading"<<endl<<endl;
	f1.close();

	while(ans=='y'||ans=='Y') {
		cout<<endl;
		cout<<"MAIN MENU"<<endl;
		cout<<"1.Values for none"<<"\t\t"<<"2.Values for all"<<endl<<"3.Values for principal & rate"<<"\t"<<"4.Values for period"<<endl<<"5.Values for principal & period"<<"\t"<<"6.Value for principal"<<endl<<"7.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;

		f1.open("C:\\Jdata\\CSJOURQ5.txt", ios::app);
		f1<<endl<<"MAIN MENU"<<endl;
		f1<<"1.Values for none"<<"\t\t"<<"2.Values for all"<<endl<<"3.Values for principal & rate"<<"\t"<<"4.Values for period"<<endl<<"5.Values for principal & period"<<"\t"<<"6.Value for principal"<<endl<<"7.Exit"<<endl;
		f1<<"Enter choice: "<<choice<<endl;
		f1.close();

		switch(choice)
		{	case 1: interest ob1;
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				f1.open("C:\\Jdata\\CSJOURQ5.txt", ios::app);
				f1<<"\n"<<"Would you like to continue?(y/n)"<<ans<<endl;
				f1.close();
				break;
			case 2: interest ob2(6000.00F,0.09F,5);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				f1.open("C:\\Jdata\\CSJOURQ5.txt", ios::app);
				f1<<"\n"<<"Would you like to continue?(y/n)"<<ans<<endl;
				f1.close();
				break;
			case 3: interest ob3(8000.00F,0.10F);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				f1.open("C:\\Jdata\\CSJOURQ5.txt", ios::app);
				f1<<"\n"<<"Would you like to continue?(y/n)"<<ans<<endl;
				f1.close();
				break;
			case 4: interest ob4(9);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				f1.open("C:\\Jdata\\CSJOURQ5.txt", ios::app);
				f1<<"\n"<<"Would you like to continue?(y/n)"<<ans<<endl;
				f1.close();
				break;
			case 5: interest ob5(4000.00F,8);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				f1.open("C:\\Jdata\\CSJOURQ5.txt", ios::app);
				f1<<"\n"<<"Would you like to continue?(y/n)"<<ans<<endl;
				f1.close();
				break;
			case 6: interest ob6(7000.00F);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				f1.open("C:\\Jdata\\CSJOURQ5.txt", ios::app);
				f1<<"\n"<<"Would you like to continue?(y/n)"<<ans<<endl;
				f1.close();
				break;
			case 7: exit(0);
				break;
			default: exit(0);
				 break;
		}
	}

	//getch();
}

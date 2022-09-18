#include<iostream.h>
#include<conio.h>
#include<stdio.h>

int i=0;

class cabs
{ private:
	int Cno;
	char type;
	int PKM;
	int dist;

  public:
	cabs()
	{	//type='A';
		//Cno=1111;
	}

	int charges(char t)
	{	if(t=='A'||t=='a')
			PKM=25;
		else if(t=='B'||t=='b')
			PKM=20;
		else if(t=='C'||t=='c')
			PKM=15;
		return PKM; //cout<<PKM;
	}

	void Register()
	{	cout<<"Enter cab number: "<<endl;
		cin>>Cno;

		cout<<"Enter city type: "<<endl;
		cin>>type;

		//int charge=
		//cout<<"Charges: "<<
		charges(type);
	       //	return charge;
	}
	void printall(int d) {
		cout<<Cno<<" "<<type<<" "<<PKM<<" "<<d*PKM<<endl;
	}

	void showcab(cabs *);
/*	{	int dist;
		cout<<"Enter distance: "<<endl;
		cin>>dist;

		//cout<<"Enter city(A/B/C): "<<endl;
		//cin>>type;
		for (int j=0; j<=i; j++) {
			a[j].printall(dist);
		}
		/*
		cout<<"Type(A/B/C): "<<type<<endl;
		int charge=charges(type);
		cout<<"Per kilometer charges: "<<charge<<endl;

		cout<<"Your total fare comes to: "<<dist*charge<<endl;
		*/
  //	}
};

void cabs::showcab(cabs a[])
	{	int dist;
		cout<<"Enter distance: "<<endl;
		cin>>dist;

		//cout<<"Enter city(A/B/C): "<<endl;
		//cin>>type;
		for (int j=0; j<i; j++) {
			a[j].printall(dist);
		}
		/*
		cout<<"Type(A/B/C): "<<type<<endl;
		int charge=charges(type);
		cout<<"Per kilometer charges: "<<charge<<endl;

		cout<<"Your total fare comes to: "<<dist*charge<<endl;
		*/
	}

void main()
{	clrscr();
	cabs ob1[150],ob2;

	int choice=0;
	char c;
	do{
		cout<<"MAIN MENU"<<endl;
		cout<<"1.REGISTER"<<endl;
		cout<<"2.BOOK"<<endl;
		cout<<"3.EXIT"<<endl;
		cout<<"ENTER CHOICE: "<<endl;
		cin>>choice;
		       //	if(choice=='3') break;
		switch(choice)
		{	case 1:  ob1[i].Register();
				 i++;
				 cout<<"THANK YOU FOR USING US!HAVE A SAFE JOURNEY!"<<endl;
			//	 cout<<"Would you like to try again(Y/N)"; cout<<endl;
			//	 cin>>c;
				 getch();
				 break;

			case 2: // ob1[i].Register();
				 if (i>0)
					ob2.showcab(ob1);
				 else
					cout<<"No cabs"<<endl;
				 cout<<"THANK YOU FOR USING US!HAVE A SAFE JOURNEY!"<<endl;
		      //		 cout<<"Would you like to try again(Y/N)"<<endl;
				 //cin>>c;
				 getch();
				 break;

		       case 3:  //cout<<"THANK YOU FOR USING US!HAVE A SAFE JOURNEY!"<<endl;
				break;

		     default:/* cout<<"INVALID CHOICE";cout<<endl;
				 cout<<"Would you like to try again(1/2/3)"; cout<<endl;
				 cin>>choice; */ break;
		};

	}while(choice!=3);

       //	ob1.Register();
      //	ob1.showcab();
	//getch();
}

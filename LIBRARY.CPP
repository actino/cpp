#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class library
{       int  bk_no[3];
	char bk_name[3][25];
	char author[3][25];
	char publisher[3][15];
	int  copies[3];
	int  copies_issued;
	char bk_issued[25];

	public:
	library()
	{
	       bk_no[0]=1001;
	       bk_no[1]=1002;
	       bk_no[2]=1003;
	       strcpy(bk_name[0],"Wonder");
	       strcpy(bk_name[1],"Flawed");
	       strcpy(bk_name[2],"Perfect");
	       strcpy(author[0],"R.J.Palacio");
	       strcpy(author[1],"Cecilia Ahren");
	       strcpy(author[2],"Cecilia Ahren");
	       strcpy(publisher[0],"Penguin") ;
	       strcpy(publisher[1],"Penguin");
	       strcpy(publisher[2],"Penguin");
	       copies[0]=5;
	       copies[1]=6;
	       copies[2]=7;
}
	   /*    for (int x = 0; x < 6; ++x)
	       {
			pbk_no[x]=bk_no[x];
			pbk_name[x][]=bk_name[x][];
			pauthor[x][]=author[x][];
			ppublisher[x][]=publisher[x][];
			pcopies[x]=copies[x];

	       }

	}    */

	void issue() ;
};

void library::issue()
	{ 	cout<<"Enter book name: "<<endl;
		gets(bk_issued);
		cout<<"How many copies do you wish to issue: "<<endl;
		cin>>copies_issued;

		int c=0;
		int p;

		for(int i=0;i<3;i++)

	       {  if(strcmpi(bk_name[i],bk_issued)==0)
			{c++; p=i;}
	       }

	       if(c>0)
	       { //if(strcmpi(bk_name[i],bk_issued)==0)
			if(copies[p]>=copies_issued)
				{ cout<<bk_no[p]<<endl<<bk_name[p]<<endl<<author[p]<<endl<<publisher[p];
				  copies[p]-=copies_issued;
				  cout<<endl<<"ISSUED!Please print the reciept and collect your book at the reception.";
				  cout<<endl<<"Please bring the recipt while returning the book";
				  cout<<endl<<"HAPPY READING!!!"; }

				else
					cout<<endl<<"Insufficient copies.";
	       }


	       else
			cout<<"NOT IN STOCK";



  }


void main()
{ 	library ob1;
	clrscr();
	ob1.issue();
	getch();
}
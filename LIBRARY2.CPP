#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

void main()

{		clrscr();
		int bk_no[6]={1001,1002,1003,1004,1005,1006};
		char bk_name[6][25]={"Wonder","Flawed","Perfect","Village By The Sea","Lethal White","Girl on the Train"};
		char author[6][25]={"R.J.Palacio","Cecilia Ahren","Cecilia Ahren","Anita Desai","Robert Grailbraith","Paula Hawkins"};
		char publisher[6][15]={"Penguin","Penguin","Penguin","Penguin","Penguin","Penguin"};
		int copies[5]={5,6,7,8,9};
		char bk_issued[25];
		int copies_issued;

		cout<<"Enter book name: "<<endl;
		gets(bk_issued);
		cout<<"How many copies do you wish to issue: "<<endl;
		cin>>copies_issued;
		int c=0;
		int p;

		for(int i=0;i<6;i++)
	       {         if(strcmpi(bk_name[i],bk_issued)==0)

			{c++; p=i;}
	       }

	       if(c>0)
	       { //if(strcmpi(bk_name[i],bk_issued)==0)
			if(copies[i]>=copies_issued)
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


getch();
}



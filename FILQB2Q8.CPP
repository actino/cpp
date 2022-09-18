#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>

class drinks
{	int Dcode;
	char Dname[90];
	int Dquantity;
	float Dprice;

	public:
	void getdrinks()
	{       cout<<"Drink code: ";
		cin>>Dcode;   //cout<<"\t";
		cout<<"Name: ";
		gets(Dname);  //cout<<"\n";
	      /*	cout<<"Quantity: ";
		cin>>Dquantity;   //cout<<"\t";
		cout<<"Price: ";
		cin>>Dprice;  cout<<endl; */
	}
	void showdrinks()
	{       cout<<"Drink code"<<Dcode<<"\t";
		cout<<"Name: "<<Dname<<"\n";
//		cout<<"quantity: "<<Dquantity<<"\t";
 //		cout<<"Price: "<<Dprice<<"\n";
	}

	char*getname()
	{	return Dname;
	}
};

void main()
{ 	clrscr();
	void write();
	void rnd();
	write();
	rnd();
	getch();
}


void write()
{       int i;
	ofstream filin;
	filin.open("C:\\Jdata\\DRINNKS.dat",ios::binary|ios::out);

	 drinks glass[10];
	 for(i=0;i<5;i++)
	 {      cout<<i+1<<".";
		glass[i].getdrinks();
		filin.write((char*)&glass[i],sizeof(glass[i]));
		cout<<endl;
	 }
}

void rnd()
{       drinks glass;
	ifstream filin;
	filin.open("C:\\Jdata\\DRINNKS.dat",ios::binary|ios::in);
	while(1)
	{       filin.read((char*)&glass,sizeof(glass));
		if(filin.eof()) break;
		if((strcmpi(glass.getname(),"INDYCOLA")==0))
		   {	glass.showdrinks();
		   }
	}
}


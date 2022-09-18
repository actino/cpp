#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

class Class
{
	long int ID;
	char stream[20];
	int grade;
	char divname;

	public:

	void getdata()
	{   cout<<"Enter ID:  ";
		cin>>ID;
		cout<<"Enter grade: ";
		cin>>grade;
		cout<<"Enter stream: ";
		gets(stream);
		cout<<"Division stream: ";
		cin>>divname;

	}

	void putdata()
	{   cout<<"Class ID: "<<ID<<"\t";
		cout<<"Class stream: "<<stream<<"\t";
		cout<<"Division: "<<divname;
	}

	int getID()
	{
		return ID;
	}
	 void modify()
	{   	cout<<"Old data"<<endl;
		cout<<"Class ID: "<<ID<<"\t";
		cout<<"Stream: "<<stream<<"\t";
		cout<<"Division: "<<divname<<endl;
		char cstream[20];
		char dname ;
		int nID;

		cout<<"Class ID: ";
		cin>>nID;
		cout<<"Enter stream: ";
		gets(cstream);
		cout<<"Division: ";
		cin>>dname;

		ID=nID;
		divname=dname;
		strcpy(stream,cstream);
	}

		void viewrecord();
		void addrecords();
		void deleterec();
		void viewallrecords();
		void modifyrec();


};       int idno ;

void Class::viewrecord()

	    {   Class c ;
			char found='n';

			cout<<"Enter Class ID to view details: "<<endl ;
			cin>>idno ;
			fstream filin;
			filin.open("C:\\tt\\Class.dat", ios::binary|ios::in);
			filin.seekg(0);


			while(1)
			{	filin.read((char*)&c,sizeof(c));
				if (filin.eof()) break;
				if(c.getID()==idno)
				{	c.putdata();
					found='y';
				}
			}
			if(found=='n')
			{	cout<<"Wrong ID!"; 	}
			filin.close();
	    }


void Class::addrecords()
{
	Class c;
	fstream filout;
	void viewallrecords();

	c.getdata();

	filout.open("C:\\tt\\Class.dat", ios::app|ios::binary);
	filout.write((char*)&c,sizeof(c));
	filout.close();

	cout<<"\nClass added"<<endl;
	c.viewallrecords();
}

void Class::deleterec()
{         Class c;
		  fstream filin;
		  ofstream filout;

		  char found='f',confirm='n';
		  void viewallrecords();

		  filin.open("C:\\tt\\Class.dat", ios::binary|ios::in);
		  filin.seekg(0);
		  filout.open("C:\\tt\\temp.dat", ios::binary|ios::out);

		  cout<<"Enter class ID whose record you wish to delete: ";
		  cin>>idno;

		  while(1)
		  {	filin.read((char*)&c,sizeof(c));
			if (filin.eof()) break;
			if(idno==c.getID())
			{   cout<<"Record to be deleted: "<<endl ;
				c.putdata() ; found='t' ;
				cout<<"Are you sure you want to delete(y/n)?"<<endl ;
				cin>>confirm ;
				if(confirm=='y')
			     {	cout<<"Record deleted"<<endl;
				 }
				else
			       filout.write((char*)&c,sizeof(c));

			}
			else
			filout.write((char*)&c,sizeof(c));
		  }

		  if(found=='f')
		  cout<<"Record not found";

		  filin.close();
		  filout.close();

		  remove("C:\\tt\\Class.dat");
		  rename("C:\\tt\\temp.dat","C:\\tt\\Class.dat");


		  cout<<"Updated file:"<<endl;
		  c.viewallrecords();
}

void Class::viewallrecords() {

		Class c;
		int count = 0;

		fstream filin;
		filin.open("C:\\tt\\Class.dat", ios::binary|ios::in);
		filin.seekg(0);

		while(1) {
			filin.read((char*)&c,sizeof(c));
			if (filin.eof()) break;
			c.putdata();
			cout<<endl;
		}

		filin.close();

	}

void Class::modifyrec()
	{         Class c ;
		  char found ='n';

		 // seeAll();

		  fstream filin;
		  ofstream filout;
		  filin.open("C:\\tt\\Class.dat", ios::binary|ios::in);
		  filout.open("C:\\tt\\temp.dat", ios::binary|ios::out);
		  //filin.seekg(0);

		  cout<<"Enter class ID whose record you wish to modify ";
		  cin>>idno;
		  while(1) {
		  filin.read((char*)&c,sizeof(c));
		   if(filin.eof()) break;
			if(c.getID()==idno)
			{   c.modify();
				filout.write((char*)&c,sizeof(c));
				cout<<"Data modified: "<<endl;
				found='y';
				break;
			}
			else
				filout.write((char*)&c,sizeof(c));

		   }    filin.close(); filout.close();

		   if(found=='n')
		   cout<<"Record not found";  cout<<endl;

		  remove("C:\\tt\\Class.dat");
		  rename("C:\\tt\\temp.dat","C:\\tt\\Class.dat");


		   filin.open("C:\\tt\\Class.dat", ios::binary|ios::in);
		   filin.seekg(0);
		   cout<<"Updated file: "<<endl;
		   while(1)
		   {   	 filin.read((char*)&c,sizeof(c));
			 if(filin.eof()) break;
			 c.putdata();
			 cout<<endl;
		   }
		   filin.close();
		   cout<<endl;
	}




//};


void chclass()
{	clrscr();
//	flight plane;
//	char entry[20];
	int choice;

//	char intent='y';
//	fstream filin;
//      ofstream filout;
//	int count=0;
	 Class c ;

		do{
		choice=0;
		cout<<endl;
		cout<<"MAIN MENU"<<endl;
		cout<<"1.View Record"<<"\t"<<"2.Add Records"<<endl<<"3.Delete Record"<<"\t"<<"4.View All"<<"\t"<<"5.Modify Records"<<"\t"<<"6.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		switch (choice)
		{	case 1: c.viewrecord();
				break;

			case 2: c.addrecords();
				break;

			case 3: c.deleterec();
				break;

			case 4: c.viewallrecords();
				break;

			case 5: c.modifyrec();
				break;

			case 6:
				exit(0) ;
				break ;
			default:
				 cout<<"Invalid Choice!!!"<<endl ;
				 break ;
		};
	} while(1);
    }

void main()
{
  chclass() ;
}


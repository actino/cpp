#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

class Class
{
	long int ID;
	char name[20];
	char divname[20] ;

	public:

	void getdata()
	{   cout<<"Class ID:  "<<endl;
		cin>>ID;
		cout<<"Class Name: "<<endl;
		gets(name);
		cout<<"Division Name: "<<endl;
		gets(divname);

	}

	void putdata()
	{   cout<<"Class ID: "<<ID<<endl;
		cout<<"Class Name: ";
		puts(name) ;
		cout<<"Division Name: ";
		puts(divname) ;


	}

	int getID()
	{
		return ID;
	}
	 void modify()
	{   cout<<"Old data"<<endl;
		cout<<"Class ID: "<<ID<<"\t";
		cout<<"Class Name: "<<name<<endl;
		cout<<"Division Name: "<<divname<<endl;
		char cname[20];
		char dname[20] ;
		int nID;

		cout<<"Class ID: ";
		cin>>nID;
		cout<<"Class Name: ";
		gets(cname);
		cout<<"Division Name: ";
		gets(divname);

		ID=nID;
		strcpy(cname,name);
		strcpy(dname,divname);
	}
 
        void viewrecord();
		void addrecords();
		void deleterec();
		void viewallrecords();
		void modifyrec();


};       int idno ;
		  void Class::viewrecord()

	    {   Class c ;
			int count=0 ;
			char found='n';

			cout<<"Enter Class ID to view details: "<<endl ;
			cin>>idno ;
			fstream filin;
			filin.open("C:\\Jdata\\Class.dat", ios::binary|ios::in);
			filin.seekg(0);


			while(1)
			{	filin.read((char*)&c,sizeof(c));
				if (filin.eof()) break;
				if(c.getID()==idno)
				{	c.putdata();
					count++;
					found='y';
				       //	cout<<endl;
				}
			}
			if(found=='n')
			{	cout<<"Sorry no class found!"; 	}
			cout<<endl<<count<<" classes found"<<endl;
			filin.close();
	    }

    void Class::addrecords()

       {    Class c;
			fstream filin;
			ofstream filout;
			Class c1 ;
			char last='y';
			int count = 0;

			cout<<"Enter details of class: ";
			c1.getdata();

			filin.open("C:\\Jdata\\Class.dat", ios::binary|ios::in);
		       //filin.seekg(0);
			filout.open("C:\\Jdata\\temp.dat", ios::binary|ios::out);

			//while(!filin.eof())
			while(1)
			{	filin.read((char*)&c,sizeof(c));
				if (filin.eof()) break;
				if(c1.getID()<=c.getID())
				{       if (last=='y') {
						filout.write((char*)&c1,sizeof(c1));
						last='n';
					}
				}
				//else
				filout.write((char*)&c1,sizeof(c1));
			}

			if(last=='y')
				filout.write((char*)&c1,sizeof(c1));

			cout<<"Data Saved."<<endl;

			filin.close();
			filout.close();
			remove("C:\\Jdata\\Class.dat");
			rename("C:\\Jdata\\temp.dat","C:\\Jdata\\Class.dat");

			filin.open("C:\\Jdata\\Class.dat", ios::binary|ios::in);
			cout<<"Updated file: "<<endl;
			while(!filin.eof())
			{
				filin.read((char*)&c,sizeof(c));
				if(filin.eof())break;
				c.putdata();
				count++;
			}
			cout<<endl<<count<<" records displayed"<<endl;
			filin.close();
       }

void Class::deleterec()
       {          Class c;
		  fstream filin;
		  ofstream filout;

		  char found='f',confirm='n';
		  int count=0;

		  filin.open("C:\\Jdata\\Class.dat", ios::binary|ios::in);
		  filin.seekg(0);
		  filout.open("C:\\Jdata\\temp.dat", ios::binary|ios::out);

		  cout<<"Enter class ID whose record you wish to delete: ";
		  cin>>idno;

		  while(1)
		  {	filin.read((char*)&c,sizeof(c));
			if (filin.eof()) break;
			if(idno==c.getID())
			{       cout<<"Record to be deleted: "<<endl ;
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

		  remove("C:\\Jdata\\Class.dat");
		  rename("C:\\Jdata\\temp.dat","C:\\Jdata\\Class.dat");

		  filin.open("C:\\Jdata\\Class.dat", ios::binary|ios::in);
		  cout<<"Updated file:"<<endl;
		  while(1)
		  {
			filin.read((char*)&c,sizeof(c));
			if(filin.eof())break;
			c.putdata();
			count++;
		  }
			cout<<endl<<count<<" records displayed"<<endl;
			filin.close();

		  filin.close();
		  filout.close();
	}

void Class::viewallrecords() {

		Class c;
		int count = 0;

		fstream filin;
		filin.open("C:\\Jdata\\Class.dat", ios::binary|ios::in);
		filin.seekg(0);

		while(1) {
			filin.read((char*)&c,sizeof(c));
			if (filin.eof()) break;
			c.putdata();
			count++;
		}

		cout<<endl<<count<<" Class found"<<endl;
		filin.close();

	}

void Class::modifyrec()
	{         Class c ;
		  char found ='n';

		 // seeAll();

		  fstream filin;
		  ofstream filout;
		  filin.open("C:\\Jdata\\Class.dat", ios::binary|ios::in);
		  filout.open("C:\\Jdata\\temp.dat", ios::binary|ios::out);
		  //filin.seekg(0);

		  cout<<"Enter class id whose record you wish to modify ";
		  cin>>idno;
		  while(1) {
		  filin.read((char*)&c,sizeof(c));
		   if(filin.eof()) break;
			if(c.getID()==idno)
			{      c.modify();
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

		  remove("C:\\Jdata\\Class.dat");
		  rename("C:\\Jdata\\temp.dat","C:\\Jdata\\Class.dat");


		   filin.open("C:\\Jdata\\Class.dat", ios::binary|ios::in);
		   filin.seekg(0);
		   cout<<"Updated file: "<<endl;
		   while(1)
		   {   	 filin.read((char*)&c,sizeof(c));
			 if(filin.eof()) break;
			 c.putdata();
		   }
		   filin.close();
		   cout<<endl;
	}




//};


void chclass()
{//	clrscr();
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

		/*void viewrecord();
		void addrecords();
		void deleterec();
		void viewallrecords();
		void modifyrec();*/
	/* if(choice==1)
	 viewrecord() ;
	 else if(choice==2)
	 addrecords()
	 else if(choice==3)
	 deleterec() ;
	 else if(choice==4)
	 viewallrecords();
	 else if(choice==5)
	 modifyrec() ;
	 else
	 break ;*/

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

     /*	void search()

	    {		flight plane;
			char entry[20];
			char avail='n';
			int count = 0;

			cout<<"Where would you like to go:";
			gets(entry);
			fstream filin;
			filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
			filin.seekg(0);


			while(1)
			{	filin.read((char*)&plane,sizeof(plane));
				if (filin.eof()) break;
				if((strcmpi(plane.getto(),entry)==0))
				{	plane.display();
					count++;
					avail='y';
				       //	cout<<endl;
				}
			}
			if(avail=='n')
			{	cout<<"Sorry. No flights"; 	}
			cout<<endl<<count<<" flights found"<<endl;
			filin.close();
	    }


	void addrecords()
       {		flight plane;
			fstream filin;
			ofstream filout;
			flight f;
			char last='y';
			int count = 0;

			cout<<"Enter details of the plane you wish to register: ";
			f.enter();

			filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
		       //filin.seekg(0);
			filout.open("C:\\Jdata\\temp.dat", ios::binary|ios::out);

			//while(!filin.eof())
			while(1)
			{	filin.read((char*)&plane,sizeof(plane));
				if (filin.eof()) break;
				if(f.getfno()<=plane.getfno())
				{       if (last=='y') {
						filout.write((char*)&f,sizeof(f));
						last='n';
					}
				}
				//else
				filout.write((char*)&plane,sizeof(plane));
			}

			if(last=='y')
				filout.write((char*)&f,sizeof(f));

			cout<<"Data Saved."<<endl;

			filin.close();
			filout.close();
			remove("C:\\Jdata\\Flights.dat");
			rename("C:\\Jdata\\temp.dat","C:\\Jdata\\Flights.dat");

			filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
			cout<<"Updated file:'"<<endl;
			while(!filin.eof())
			{
				filin.read((char*)&plane,sizeof(plane));
				if(filin.eof())break;
				plane.display();
				count++;
			}
			cout<<endl<<count<<" records displayed"<<endl;
			filin.close();
       }

       void remove()
       {          flight plane;
		  fstream filin;
		  ofstream filout;
		  int fnod;
		  char found='n';
		  int count=0;

		  filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
		  filin.seekg(0);
		  filout.open("C:\\Jdata\\temp.dat", ios::binary|ios::out);

		  cout<<"Enter flight no whoose recrd you wish to delete: ";
		  cin>>fnod;

		  while(1)
		  {	filin.read((char*)&plane,sizeof(plane));
			if (filin.eof()) break;
			if(fnod==plane.getfno())
			{	cout<<"Record deleted"<<endl;
				found='y';
			}
			else
			filout.write((char*)&plane,sizeof(plane));
		  }

		  if(found=='n')
		  cout<<"Record not found";

		  filin.close();
		  filout.close();

		  remove("C:\\Jdata\\Flights.dat");
		  rename("C:\\Jdata\\temp.dat","C:\\Jdata\\Flights.dat");

		  filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
		  cout<<"Updated file:"<<endl;
		  while(1)
		  {
			filin.read((char*)&plane,sizeof(plane));
			if(filin.eof())break;
			plane.display();
			count++;
		  }
			cout<<endl<<count<<" records displayed"<<endl;
			filin.close();

		  filin.close();
		  filout.close();
	}

	void seeAll() {

		flight plane;
		int count = 0;

		fstream filin;
		filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
		filin.seekg(0);

		while(1) {
			filin.read((char*)&plane,sizeof(plane));
			if (filin.eof()) break;
			plane.display();
			count++;
		}

		cout<<endl<<count<<" flights found"<<endl;
		filin.close();

	}

	void alter()
	{         flight plane;
		  char found ='n';

		  seeAll();

		  fstream filin;
		  ofstream filout;
		  filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
		  filout.open("C:\\Jdata\\temp.dat", ios::binary|ios::out);
		  //filin.seekg(0);
		  int fnom;
		  cout<<"Enter flight no whoose recrd you wish to modify ";
		  cin>>fnom;
		  while(1) {
		  filin.read((char*)&plane,sizeof(plane));
		   if(filin.eof()) break;
			if(plane.getfno()==fnom)
			{	plane.modify();
				filout.write((char*)&plane,sizeof(plane));
				cout<<"Data modified: "<<endl;
				found='y';
				break;
			}
			else
				filout.write((char*)&plane,sizeof(plane));

		   }    filin.close(); filout.close();

		   if(found=='n')
		   cout<<"Record not found";  cout<<endl;

		  remove("C:\\Jdata\\Flights.dat");
		  rename("C:\\Jdata\\temp.dat","C:\\Jdata\\Flights.dat");


		   filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
		   filin.seekg(0);
		   cout<<"Updated file: "<<endl;
		   while(1)
		   {   	 filin.read((char*)&plane,sizeof(plane));
			 if(filin.eof()) break;
			 plane.display();
		   }
		   filin.close();
		   cout<<endl;
	}
       */





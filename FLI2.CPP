#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

class flight
{
	long int fno;
	char company[20];
	char From[20];
	char To[20];

	public:

	flight()
	{ fno=0;
	  strcpy(From,"Out of order ");
	  strcpy(To,"Out of order ");
	}

	void enter()
	{       cout<<endl<<"Flight No:  ";
		cin>>fno;
		cout<<"Airlines: ";
		gets(company);
		cout<<"Take off point: ";
		gets(From);
		cout<<"Destination: ";
		gets(To);
	}

	void display()
	{       cout<<"Flight No: "<<fno<<"\t";
		cout<<company<<"\t";
		cout<<From<<"\t";
		cout<<To<<endl;
		/*cout<<"Airlines: "<<company<<endl;
		cout<<"Take off point: "<<From<<"\t";
		cout<<"Destination "<<To<<endl;*/
	}

	int getfno()
	{
		return fno;
	}

	const char* getto()
	{
		return To;
	}

	const char* getfrom()
	{
		return From;
	}

	const char* getairlines()
	{
		return company;
	}

	void modify()
	{       cout<<"Old data"<<endl;
		cout<<"Flight No: "<<fno<<"\t";
		cout<<company<<"\t";
		cout<<From<<"\t";
		cout<<To<<endl;

		char airlines[20]=" ";
		char nfrom[20]=" ";
		char nTo[20]=" ";
		int nfno;

		cout<<endl<<"Flight No:  ";
		cin>>nfno;
		cout<<"Airlines: ";
		gets(airlines);
		cout<<"Take off point: ";
		gets(nfrom);
		cout<<"Destination: ";
		gets(nTo);

		fno=nfno;
		strcpy(company,airlines);
		strcpy(From,nfrom);
		strcpy(To,nTo);
	}

};


void main()
{	clrscr();
//	flight plane;
//	char entry[20];
	int choice;
//	char intent='y';
//	fstream filin;
//      ofstream filout;
//	int count=0;

		do{
		choice=0;
		cout<<endl;
		cout<<"MAIN MENU"<<endl;
		cout<<"1.Search flight"<<"\t"<<"2.Register flight"<<endl<<"3.Delete Record"<<"\t"<<"4.See All"<<"\t"<<"5.Alter"<<"\t"<<"6.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;

		void search();
		void insert();
		void remove();
		void seeAll();
		void alter();
		void book();

		switch (choice)
		{	case 1: search();
				char wish;
				cout<<"Book flight?(y/n)";
				cin>>wish;
				if(wish=='y'||wish=='Y')
				book();
				break;

			case 2: insert();
				break;

			case 3: remove();
				break;

			case 4: seeAll();
				char wish1;
				cout<<"Book flight?(y/n)";
				cin>>wish1;
				if(wish1=='y'||wish1=='Y')
				book();
				break;

			case 5: alter();
				break;

			default:
				exit(0);
				break;
		}
	} while(1);
}

	void search()

	    {		char filter;
			int filterchoice;
			void searcha();
			void searchf();
			void searchd();
			void seeAll();

			cout<<"Press 'f' to filter search";
			cin>>filter;

			if(filter=='f'||filter=='F')
			{	cout<<"1.Airlines"<<"\t"<<"2.Arrival"<<"\t"<<"3.Destination";
				cin>>filterchoice;

				switch(filterchoice)
				{	case 1: searcha();
						break;
					case 2: searchf();
						break;
					case 3: searchd();
						break;
					default: exit(0);
						break;
				}
			}
			else
			seeAll();
	    }


	void insert()
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

       void searcha()
       {        flight plane;
		char entrya[20];
		char avail='n';
		int count = 0;

		cout<<"Which airline would you like to travel by:";
		gets(entrya);
		fstream filin;
		filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
		filin.seekg(0);
		while(1)
			{	filin.read((char*)&plane,sizeof(plane));
				if (filin.eof()) break;
				if((strcmpi(plane.getairlines(),entrya)==0))
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

       void searchf()
       {        flight plane;
		char entryf[20];
		char avail='n';
		int count = 0;

		cout<<"Where would you like to depart from: :";
		gets(entryf);
		fstream filin;
		filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
		filin.seekg(0);
		while(1)
			{	filin.read((char*)&plane,sizeof(plane));
				if (filin.eof()) break;
				if((strcmpi(plane.getfrom(),entryf)==0))
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

       void searchd()
       {        flight plane;
		char entryd[20];
		char avail='n';
		int count = 0;

		cout<<"Where would you like to go:";
		gets(entryd);
		fstream filin;
		filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
		filin.seekg(0);
		while(1)
			{	filin.read((char*)&plane,sizeof(plane));
				if (filin.eof()) break;
				if((strcmpi(plane.getto(),entryd)==0))
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

       void book()
       { 	flight plane;
		int fnob;
		int count=0;
		char avail='n';
		char captcha[8]="";
		char comp[8]="";
		char date[7];
		char name[30];
		char accountno[10];
		char password[10];
		char alphanum[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		randomize();
		int i=0;
		while(i<7)
		{	int temp= rand()%26;
			comp[i]=alphanum[temp];
			i++;
		}
		cout<<"Please enter the given string: "<<endl;
		cout<<"This is to make sure you are a human."<<endl;
		puts(comp);
		gets(captcha);

		if(strcmp(comp,captcha)==0)
	      { cout<<"PROCEED TO BOOK.";
		cout<<endl;
		cout<<"Flight no ofthr flight you wish to travel bt: ";
		cin>>fnob;
		cout<<"Date of travel: ";
		gets(date);
		cout<<"Enter name: ";
		gets(name);
		cout<<"Account no: ";
		gets(accountno);
		cout<<"Password: ";
		gets(password);

		cout<<"Name: "<<name<<endl;
		cout<<"Date of travel"<<date;
		cout<<"account no: "<<accountno;

		char proxy[7];
			for (int i=0;i<3;i++)
			proxy[i]=password[i];
		strcat(proxy,"XXXX");
		cout<<endl<<"Password: "<<proxy;
		cout<<"FLIGHT DETAILS: "<<endl;

		fstream filin;
		filin.open("C:\\Jdata\\Flights.dat", ios::binary|ios::in);
		filin.seekg(0);


		while(1)
			{	filin.read((char*)&plane,sizeof(plane));
				if (filin.eof()) break;
				if(plane.getfno()==fnob)
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
	else
	cout<<"Incorrect entry.";
	}

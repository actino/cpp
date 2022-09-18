/*
*				CLASSDIV.h
*
*
*/
class Class
{
	int ID;
	int grade;
	char divname;
	char stream[20];
	
	public:

	int getdata(int x)
	{
		cout<<"\tPlease Enter new Data =>"<<endl;
		ID = x;
		cout<<"\t\tClass ID: "<<x<<endl;
		cout<<"\t\tEnter Grade(11-12): ";
		cin>>grade;
		cout<<"\t\tEnter Division(A-Z): ";
		cin>>divname;
		cout<<"\t\tEnter Stream: ";
		gets(stream);
		
		return validate();
	}

	void putdata()
	{
	    //cout<<"|   CLASS ID   | GRADE | DIVISION | STREAM                                   |"<<endl;
		cout<<"|     "<<ID<<"      |   "<<grade<<"  |     "<<divname<<"    |  "<<stream;
		for (int z=0; z<(40-strlen(stream)); z++)
			cout<<" ";
		cout<<"|"<<endl;
	}

	int getID()
	{
		return ID;
	}
	
	int getgrade()
	{	
		return grade;
	}
	
	char getdiv()
	{	
		return divname;
	}
	
	const char* getstream()
	{
		return stream;
	}
	
	int validate()
	{
		if ((grade==11 || grade==12) && 
			(divname >= 65 && divname <= 90))
			return 0;
		else
			return -1;
	}
	
	void putid(int x)
	{ //Used for not found case
		ID=x;
	}
	
	int notFound()
	{
		if (ID==-1)
			return 1;
		else
			return 0;
	}

    int getLast();
	void viewallrecords();
    void viewrecord();
    void addrecords();
    void deleterec();
	Class getcls(int clsid);
	int getccount();
};

int idno ;

int Class::getLast()
// To get class id of last class
{
	Class last;
	const int first=99; //To be used when no class records exist. First class ID will be 100.
	int x=first;
	fstream fi;

	fi.open("C:\\tt\\Class.dat", ios::binary|ios::in);
	if (fi.bad() || fi.fail())  {
			x=first;
			fi.clear(); //clear() cleans stream buffer
	} else {
		
		while(1)
		{	fi.read((char*)&last,sizeof(last));
			if (fi.eof()) 
				break;
			else 
				x=last.getID();
		}		
	}
	x++;
	fi.close();
	return x;
}

int Class::getccount() 
//to get total number of classes in the data. Used to put limit on number of classes.
{
	Class c;
	int count = 0;

	fstream filin;
	filin.open("C:\\tt\\Class.dat", ios::binary|ios::in);
	
	if (filin.bad() || filin.fail())  {
			count=0;
			filin.clear();
	} else {
		filin.seekg(0);
		while(1) {
				filin.read((char*)&c,sizeof(c));
				if (filin.eof()) break;
				count++;
		}
	}
	filin.close();		
	return count;
}

void Class::viewallrecords() 
{
		Class c;		
		fstream filin;
		filin.open("C:\\tt\\Class.dat", ios::binary|ios::in);
		
		if (filin.bad() || filin.fail())  {
			cout<<"\n\tERROR: Class data does not exist."<<endl;
			filin.clear();
		} else {
			filin.seekg(0);
			cout<<".----------------------------------------------------------------------------."<<endl;
			cout<<"|                        1.1 List all classes                                |"<<endl;
			cout<<"|----------------------------------------------------------------------------|"<<endl;
			cout<<"|   CLASS ID   | GRADE | DIVISION | STREAM                                   |"<<endl;
			cout<<"|----------------------------------------------------------------------------|"<<endl;

			while(1) {
				filin.read((char*)&c,sizeof(c));
				if (filin.eof()) break;
				c.putdata();
			}
			cout<<".----------------------------------------------------------------------------."<<endl;
		}
		filin.close();
}

void Class::viewrecord()
{   
	Class c;
    int found=0;
	void viewClassMapping(int cid);

    fstream filin;
	filin.open("C:\\tt\\Class.dat", ios::binary|ios::in);
    if (filin.bad() || filin.fail())  {
			cout<<"\n\tERROR: Class data does not exist."<<endl;
			filin.clear();
	} else {
		cout<<"\tEnter Class ID : ";
		cin>>idno;
	 
		filin.seekg(0);

		while(1)
		{	filin.read((char*)&c,sizeof(c));
			if (filin.eof()) break;
			if(c.getID()==idno)
			{	
				cout<<".----------------------------------------------------------------------------."<<endl;
				cout<<"|                        1.2 View class details                              |"<<endl;
				cout<<"|----------------------------------------------------------------------------|"<<endl;
				cout<<"|   CLASS ID   | GRADE | DIVISION | STREAM                                   |"<<endl;
				cout<<"|----------------------------------------------------------------------------|"<<endl;
				c.putdata();
				found=1;
				viewClassMapping(idno);
				cout<<".----------------------------------------------------------------------------.";
			}
		}
		
		if(!found)
			cout<<"\n\tERROR: The Class ID does not exist."<<endl; 	
	}
	filin.close();
}

void Class::addrecords()
{
	Class c;
	fstream filout;
	
	cout<<".----------------------------------------------------------------------------."<<endl;
	cout<<"|                        1.3 Add a class & division                          |"<<endl;
	cout<<"|----------------------------------------------------------------------------|"<<endl;
				
	if (c.getccount() < num_ClassDiv) {
		if (c.getdata(getLast())==-1) {
			cout<<"\n\tInvalid inputs!"<<endl;
		} else {
			filout.open("C:\\tt\\Class.dat", ios::app|ios::binary);
			filout.write((char*)&c,sizeof(c));
			filout.close();

			cout<<"\n\tINFO: Class created successfully!"<<endl;
			cout<<".----------------------------------------------------------------------------."<<endl;
		}
	} else {
		cout<<"\n\tWARNING: Maximum limit of "<<num_ClassDiv<<" classes reached. Cannot add."<<endl;
	}
}

void Class::deleterec()
{         
	Class c;
	fstream filin;
	ofstream filout;
	void deleteClassMapping(int cid);

	char confirm='n';
	int found=0, deleted=0;
	
	filin.open("C:\\tt\\Class.dat", ios::binary|ios::in);

	if (filin.bad() || filin.fail())  {
		cout<<"\n\tERROR: Class data does not exist."<<endl;
		filin.clear();
	} else {
		filin.seekg(0);
		filout.open("C:\\tt\\temp.dat", ios::binary|ios::out);
		cout<<"\n\tEnter class ID to be deleted: ";
		cin>>idno;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|                        1.5 Delete a class                                  |"<<endl;
		cout<<"|----------------------------------------------------------------------------|"<<endl;
		
		while(1)
		{	filin.read((char*)&c,sizeof(c));
			if (filin.eof()) break;
			if(idno==c.getID())
			{   
				cout<<"|   CLASS ID   | GRADE | DIVISION | STREAM                                   |"<<endl;
				cout<<"|----------------------------------------------------------------------------|"<<endl;
				c.putdata(); 
				cout<<"|----------------------------------------------------------------------------|"<<endl;
				found=1;
				cout<<"\n\tAre you sure you want to delete(y/n)? ";
				cin>>confirm ;
				if(confirm=='y'||confirm=='Y') {
					cout<<"\n\tINFO: Class data deleted successfully."<<endl;
					deleted=1;
				}
				else 
					break;
			}
			else
				filout.write((char*)&c,sizeof(c));
		}

		if(!found)
			cout<<"\n\tERROR: The Class record not found"<<endl;

		filout.close();
		cout<<".----------------------------------------------------------------------------."<<endl;
		
	}
	filin.close();
	
	if (deleted) {
		deleteClassMapping(idno);
		remove("C:\\tt\\Class.dat");
		rename("C:\\tt\\temp.dat","C:\\tt\\Class.dat");
	} else {
		remove("C:\\tt\\temp.dat");
	}
	
}

Class Class::getcls(int classid)
{	
	Class c;
    int found=0;

    fstream filin;
	filin.open("C:\\tt\\Class.dat", ios::binary|ios::in);
	
	if (filin.bad() || filin.fail())  {
			filin.clear();
	} else {
		
		filin.seekg(0);

		while(1)
		{	filin.read((char*)&c,sizeof(c));
			if (filin.eof()) break;
			if(c.getID()==classid)
			{	found=1;
				break;
			
			}
		}
	}
		
	filin.close();
		
	if(!found)
	{	
		c.putid(-1);
	}
		
	return c;
}

void viewClassMapping(int cid)
{
	fstream fcst;
	int notfound=1;
	classentity c;
	char prns[20];
	
	fcst.open("C:\\tt\\classsubmap.dat", ios::binary|ios::in);
	
	if (fcst.bad() || fcst.fail())  {
			fcst.clear();
	} else {
		fcst.seekg(0);
		
		while(notfound)
			{	
				fcst.read((char*)&c,sizeof(classentity));
				if (fcst.eof()) break;
				
				if (c.classid==cid) {
					notfound = 0;
					cout<<"|----------------------------------------------------------------------------|"<<endl;
					cout<<"| Code |      Subject      | Lectures | Teacher ID | Teacher                 |"<<endl;
					cout<<"|----------------------------------------------------------------------------|"<<endl;
					for (int i=0; i<c.total_subjects; i++) {
						strcpy(prns, emptyString20);
						strcpy(prns, c.subjects[i].subjname);
						cout<<"   "<<c.subjects[i].subjcode;
						
						if (getlen(c.subjects[i].subjcode) == 2)
							cout<<"    ";
						else if (getlen(c.subjects[i].subjcode) == 3)
							cout<<"   ";
						else 
							cout<<"  ";
						cout<<prns;
						
						for (int z=0; z<(24-strlen(prns)); z++)
							cout<<" ";
						
						cout<<c.subjects[i].numlectures;
						cout<<"\t"<<c.subjects[i].teacher.empid<<"\t"<<c.subjects[i].teacher.tname<<endl;					
					}
				}
			}
	}	
	fcst.close();
}

void deleteClassMapping(int cid)
{
	fstream fcst;
	ofstream fcstout;
	int notfound=1;
	classentity c;
	
	fcst.open("C:\\tt\\classsubmap.dat", ios::binary|ios::in);
	
	if (fcst.bad() || fcst.fail())  {
			fcst.clear();
	} else {
		fcst.seekg(0);
		fcstout.open("C:\\tt\\tempfcst.dat", ios::binary|ios::out);
		
		while(1)
			{	
				fcst.read((char*)&c,sizeof(classentity));
				if (fcst.eof()) break;
				
				if (c.classid==cid) {
					notfound = 0;				
				} else
					fcstout.write((char*)&c,sizeof(classentity));
			}		
		fcstout.close();
	}
	
	fcst.close();
	
	if (!notfound) {
		remove("C:\\tt\\classsubmap.dat");
		rename("C:\\tt\\tempfcst.dat","C:\\tt\\classsubmap.dat");
	} else {
		remove("C:\\tt\\tempfcst.dat");
	}
}

void classScreen() {
		clrscr();
		cout<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|                        TIME TABLE APPLICATION                              |"<<endl;
		//cout<<"|                                                                            |"<<endl;
		cout<<"|                        1.0 CLASS MAINTENANCE                               |"<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|    1. List all classes              2. View class details                  |"<<endl;
		cout<<"|    3. Add a class & division        4. Delete a class                      |"<<endl;
		cout<<"|    5. Go Back to Main Menu                                                 |"<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"                          Enter choice: ";
}

void switchclass()
{
	int choice;
	int goBack=0;
	Class c;

	do{
		choice=0;
		classScreen();
		cin>>choice;

		switch (choice)
		{	case 1: c.viewallrecords();
				break;

			case 2: c.viewrecord(); // Show complete mapping
				break;

			case 3: c.addrecords();
				break;

			case 4: c.deleterec(); //Remove the mapping too 
				break;

			case 5:
				goBack=1;
				break ;

			default:
				cout<<"\n\tERROR: Invalid Choice!"<<endl;
				break ;
		};
		
		if (!goBack) {
			cout<<endl<<"Press any key to continue...";
			getch();				
		}
			 
	} while(!goBack);
 }
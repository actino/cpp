/*
*				TEACHERS.h
*
*
*/
class teacher
{
	int id;
	char teachername[20];

	public:
	int enter()
	{	
		cout<<"Enter employee id: ";
		cin>>id;
		cout<<endl<<"Enter name:  ";
		gets(teachername);
		return validate();
	}

	void display()
	{
		cout<<"\t"<<id<<"\t"<<teachername<<endl;
	}

	int getid()
	{	return id;
	}
	
	const char* gettname()
	{
		return teachername;
	}
	
	int validate()
	{
		if (id > 0 && id <= 9999)
			return 1;
		else
			return 0;
	}
	
	void putid(int x)
	{ //Used for not found case
		id=x;
	}
	
	int notFound()
	{
		if (id==-1)
			return 1;
		else
			return 0;
	}

	void viewteacher();
	void listteacher();
	teacher gettchr(int eid);
	void addteacher();
    void removeteacher();
	int gettcount();
};

void teacher::viewteacher()
{
	teacher teach, t;
	int tid;
	void viewTeacherMapping(int eid);

	cout<<"\n\tEnter Teacher Employee ID : ";
	cin>>tid;

	t=teach.gettchr(tid);

	if (!t.notFound()) {
		cout<<"|----------------------------------------------------------------------------|"<<endl;
		cout<<"|     ID       | Name                                                        |"<<endl;
		cout<<"|----------------------------------------------------------------------------|"<<endl;
		t.display();
		viewTeacherMapping(tid);
		cout<<".----------------------------------------------------------------------------."<<endl;

	} else {
		cout<<"\n\tERROR: Teacher ID does not exist."<<endl;
	}
	
}

teacher teacher::gettchr(int eid)
{
	teacher t;
    int found=0;

    fstream filin;
	filin.open("C:\\tt\\Teachers.dat", ios::binary|ios::in);
	
	if (filin.bad() || filin.fail())  {
			filin.clear();
	} else {

		filin.seekg(0);

		while(1)
		{	filin.read((char*)&t,sizeof(t));
			if (filin.eof()) break;
			if(t.getid()==eid)
			{	found=1;
				break;

			}
		}
    }
	filin.close();

	if(!found)
		t.putid(-1);

	return t;
}

void teacher::addteacher()
{
	teacher teach, t;
	fstream filout;
	
	cout<<".----------------------------------------------------------------------------."<<endl;
	cout<<"|                        3.3 Create teacher                                  |"<<endl;
	cout<<"|----------------------------------------------------------------------------|"<<endl;

	if (teach.gettcount() < num_Tchr) {
		if (teach.enter()) {
			t = teach.gettchr(teach.getid());

			if (t.notFound()) {
				filout.open("C:\\tt\\Teachers.dat", ios::app|ios::binary);
				filout.write((char*)&teach,sizeof(teach));
				filout.close();
				cout<<"\n\tINFO: Teacher added successfully."<<endl;
			} else {
				cout<<"\n\tERROR: Employee ID already exists. Please try again."<<endl;
			}
		} else {
			cout<<"\n\tERROR: Invalid inputs! Teacher Code should be between 1 and 9999."<<endl;
		}
	} else {
		cout<<"\n\tWARNING: Maximum limit of "<<num_Tchr<<" teachers reached. Cannot add."<<endl;
	}

	cout<<"|----------------------------------------------------------------------------|"<<endl;

}

int teacher::gettcount()
{
	teacher teach;
	int count = 0;

	fstream filin;
	filin.open("C:\\tt\\Teachers.dat", ios::binary|ios::in);

	if (filin.bad() || filin.fail())  {
			count=0;
			filin.clear();
	} else {
		filin.seekg(0);
		while(1) {
				filin.read((char*)&teach,sizeof(teach));
				if (filin.eof()) break;
				count++;
		}
	}
	filin.close();
	return count;
}

void teacher::listteacher()
{
	teacher teach;
	fstream filin;
	
	filin.open("C:\\tt\\Teachers.dat", ios::binary|ios::in);

	if (filin.bad() || filin.fail())  {
			cout<<"\n\tERROR: Teacher data does not exist."<<endl;
			filin.clear();
	} else {
		filin.seekg(0);

		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|                        3.1 List all teachers                               |"<<endl;
		cout<<"|----------------------------------------------------------------------------|"<<endl;
		cout<<"|     ID      | Name                                                         |"<<endl;
		cout<<"|----------------------------------------------------------------------------|"<<endl;

		while(1) {
				filin.read((char*)&teach,sizeof(teach));
				if (filin.eof()) break;
				teach.display();
		}
		cout<<"|----------------------------------------------------------------------------|"<<endl;
	}
	filin.close();
}

void teacher::removeteacher()
{   teacher teach;
	fstream filin;
	ofstream filout;

	void deleteTeacherMapping(int eid);

	char confirm='n';
	int found=0, deleted=0;
	int tid;
	
	filin.open("C:\\tt\\Teachers.dat", ios::binary|ios::in);

	if (filin.bad() || filin.fail())  {
		cout<<"\n\tERROR: Teacher data does not exist."<<endl;
		filin.clear();
	} else {

		filin.seekg(0);
		filout.open("C:\\tt\\temp.dat", ios::binary|ios::out);

		cout<<"Enter employee id of the teacher to be deleted: ";
		cin>>tid;

		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|                        3.5 Delete a teacher                                |"<<endl;
		cout<<"|----------------------------------------------------------------------------|"<<endl;

		while(1)
		{	filin.read((char*)&teach,sizeof(teach));
			if (filin.eof()) break;
			if(teach.getid()==tid) {

				cout<<"|     ID      | Name                                                         |"<<endl;
				cout<<"|----------------------------------------------------------------------------|"<<endl;
				teach.display();
				cout<<"|----------------------------------------------------------------------------|"<<endl;
				found=1;

				cout<<"\n\tAre you sure you want to delete(y/n)? ";
				cin>>confirm ;
				if(confirm=='y'||confirm=='Y') {
					cout<<"\n\tINFO: Teacher data deleted successfully."<<endl;
					deleted=1;
				}
				else
					break;
			}
			else
				filout.write((char*)&teach,sizeof(teach));
		}

		if(!found)
			cout<<"\n\tERROR: The Teacher Data not found"<<endl;

		filout.close();
		cout<<".----------------------------------------------------------------------------."<<endl;
	}

	filin.close();

	if (deleted) {
		deleteTeacherMapping(tid);
		remove("C:\\tt\\Teachers.dat");
		rename("C:\\tt\\temp.dat","C:\\tt\\Teachers.dat");
	} else {
		remove("C:\\tt\\temp.dat");
	}
}

void viewTeacherMapping(int eid)
{
	fstream fcst;
	int notfound=1;
	classentity c;
	char prns[20];
	int l=0;

	fcst.open("C:\\tt\\classsubmap.dat", ios::binary|ios::in);

	if (fcst.bad() || fcst.fail())  {
			fcst.clear();
	} else {
		fcst.seekg(0);

		cout<<"|----------------------------------------------------------------------------|"<<endl;
		cout<<"| Class                          | Code  |       Subject          | Lectures |"<<endl;
		cout<<"|----------------------------------------------------------------------------|"<<endl;

		while(notfound)
			{
				fcst.read((char*)&c,sizeof(classentity));
				if (fcst.eof()) { notfound = 0; break; }

				for (int i=0; i<c.total_subjects; i++) {
					if (c.subjects[i].teacher.empid==eid) {
						l=0;
						l=getlen(c.classid)+getlen(c.grade)+4+strlen(c.cstream);
						
						cout<<" "<<c.classid<<"-"<<c.grade<<"-"<<c.divi<<"-"<<c.cstream;
						for (int z=0; z<(32-l); z++)
							cout<<" ";
						
						strcpy(prns, emptyString20);
						strcpy(prns, c.subjects[i].subjname);
						//cout<<" "<<c.classid<<"-"<<c.grade<<"-"<<c.divi<<"-"<<c.cstream<<"\t\t";
						cout<<c.subjects[i].subjcode<<"\t"<<prns<<"\t"<<c.subjects[i].numlectures<<endl;
					}
				}
			}
	}
	fcst.close();
}

void deleteTeacherMapping(int eid)
{
	fstream fcst;
	ofstream fcstout;
	classentity c, cc;

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

				cc.classid = c.classid;
				cc.grade = c.grade;
				cc.divi = c.divi;
				strcpy(cc.cstream,c.cstream);
				cc.total_subjects = 0;
				cc.total_lectures = 0;

				for (int i=0; i<c.total_subjects; i++) {
					if (c.subjects[i].teacher.empid!=eid) {
						cc.subjects[cc.total_subjects].subjcode = c.subjects[i].subjcode;
						strcpy(cc.subjects[cc.total_subjects].subjname,c.subjects[i].subjname);
						cc.subjects[cc.total_subjects].numlectures = c.subjects[i].numlectures;
						cc.subjects[cc.total_subjects].teacher.empid = c.subjects[i].teacher.empid;
						strcpy(cc.subjects[cc.total_subjects].teacher.tname,c.subjects[i].teacher.tname);
						cc.total_subjects++;
						cc.total_lectures += c.subjects[i].numlectures;
					}
				}
				fcstout.write((char*)&cc,sizeof(classentity));
			}
		fcstout.close();
	}
	fcst.close();

	remove("C:\\tt\\classsubmap.dat");
	rename("C:\\tt\\tempfcst.dat","C:\\tt\\classsubmap.dat");
}

void teacherScreen() {
		clrscr();
		cout<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|                        TIME TABLE APPLICATION                              |"<<endl;
		cout<<"|                        3.0 TEACHERS MAINTENANCE                            |"<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|    1. List all teachers             2. View a teacher                      |"<<endl;
		cout<<"|    3. Create teacher                4. Delete a teacher                    |"<<endl;
		cout<<"|    5. Go Back to Main Menu                                                 |"<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"                          Enter choice: ";
}

void switchteacher()
{       
	teacher t;
	int choice;
	int goBack=0;

	do{
		choice=0;
		teacherScreen();
		cin>>choice;

		switch (choice)
		{	case 1: t.listteacher();
				break;

			case 2: t.viewteacher();
				break;

			case 3: t.addteacher();
				break;

			case 4: t.removeteacher(); //remove mapping
				break;

			case 5:
				goBack=1;
				break ;

			default:
				cout<<"\n\tERROR: Invalid Choice!"<<endl;
				break ;
		}

		if (!goBack) {
			cout<<endl<<"Press any key to continue...";
			getch();				
		}
	} while(!goBack);
}
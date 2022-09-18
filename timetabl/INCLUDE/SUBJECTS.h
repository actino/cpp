/*
*				SUBJECTS.h
*
*
*/
class subject
{
	int subcode;
	char subname[20];
	
	public:
	int enter()
	{
		cout<<"Subject code: ";
		cin>>subcode;
		cout<<endl<<"Subject:  ";
		gets(subname);
		return validate();
	}

	void display()
	{		
		cout<<"\t"<<subcode<<"\t "<<subname<<endl;
	}

	const char* getsubname()
	{
		return subname;
	}
	
	int getcode()
	{	
		return subcode;
	}
	
	void putcode(int x)
	{ //Used for not found case
		subcode=x;
	}
	
	int notFound()
	{
		if (subcode==-1)
			return 1;
		else
			return 0;
	}

	int validate()
	{
		if (subcode > 0 && subcode <= 9999)
			return 1;
		else
			return 0;
	}

	void viewsubject();
	void listsubjects();
	subject getsub(int subcode);
	void addsubject();
    void removesubject();
	int getscount();
};

void subject::listsubjects()
{
	subject sub;
	
	fstream filin;
	filin.open("C:\\tt\\Subjects.dat", ios::binary|ios::in);
	if (filin.bad() || filin.fail())  {
			cout<<"\n\tERROR: Subject data does not exist."<<endl;
			filin.clear();
	} else {
		filin.seekg(0);
		
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|                        2.1 List all subjects                               |"<<endl;
		cout<<"|----------------------------------------------------------------------------|"<<endl;
		cout<<"|     Code     | Subject                                                     |"<<endl;
		cout<<"|----------------------------------------------------------------------------|"<<endl;
			
		while(1) {
				filin.read((char*)&sub,sizeof(sub));
				if (filin.eof()) break;
				sub.display();
		}
		cout<<"|----------------------------------------------------------------------------|"<<endl;
	}
	filin.close();
}

subject subject::getsub(int subcode)
{	
	subject s;
    int found=0;

    fstream filin;
	filin.open("C:\\tt\\Subjects.dat", ios::binary|ios::in);
	
	if (filin.bad() || filin.fail())  {
		filin.clear();
	} else {		
		filin.seekg(0);

		while(1)
		{	filin.read((char*)&s,sizeof(s));
			if (filin.eof()) break;
			if(s.getcode()==subcode)
			{	found=1;
				break;	
			}
		}
	}
	filin.close();
	
	if(!found)	
		s.putcode(-1);
		
	return s;
}

int subject::getscount()
{
	subject s;
	int count = 0;

	fstream filin;
	filin.open("C:\\tt\\Subjects.dat", ios::binary|ios::in);
	
	if (filin.bad() || filin.fail())  {
			count=0;
			filin.clear();
	} else {
		filin.seekg(0);
		while(1) {
				filin.read((char*)&s,sizeof(s));
				if (filin.eof()) break;
				count++;
		}
	}
	filin.close();		
	return count;
}

void subject::addsubject()
{
	subject sub, s;
	fstream filout;
	
	cout<<".----------------------------------------------------------------------------."<<endl;
	cout<<"|                        2.3 Create Subject                                  |"<<endl;
	cout<<"|----------------------------------------------------------------------------|"<<endl;
	
	if (sub.enter()) {
		s = sub.getsub(sub.getcode());
		
		if (s.notFound()) {	
			filout.open("C:\\tt\\Subjects.dat", ios::app|ios::binary);
			filout.write((char*)&sub,sizeof(sub));
			filout.close();
			cout<<"\n\tINFO: Subject added successfully."<<endl;
		} else {
			cout<<"\n\tERROR: Subject Code already exists. Please try again."<<endl;
		}
	} else {
		cout<<"\n\tERROR: Invalid inputs! Subject Code should be between 1 and 9999."<<endl;
	}
	cout<<"|----------------------------------------------------------------------------|"<<endl;
}

void subject::removesubject()
{    	
	subject sub;
	fstream filin;
	ofstream filout;
	
	void deleteSubjectMapping(int code);
	
	char confirm='n';
	int found=0, deleted=0;
	int sid;

	filin.open("C:\\tt\\Subjects.dat", ios::binary|ios::in);

	if (filin.bad() || filin.fail())  {
		cout<<"\n\tERROR: Subject data does not exist."<<endl;
		filin.clear();
	} else {
		
		filin.seekg(0);
		filout.open("C:\\tt\\temp.dat", ios::binary|ios::out);
	
		cout<<"Enter subject code to be deleted: ";
		cin>>sid;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|                        2.5 Delete a subject                                |"<<endl;
		cout<<"|----------------------------------------------------------------------------|"<<endl;

		while(1)
		{	filin.read((char*)&sub,sizeof(sub));
			if (filin.eof()) break;
			
			if (sid == sub.getcode()){	
				cout<<"|     Code     | Subject                                                     |"<<endl;
				cout<<"|----------------------------------------------------------------------------|"<<endl;
				sub.display();
				cout<<"|----------------------------------------------------------------------------|"<<endl;
				found=1;
				
				cout<<"\n\tAre you sure you want to delete(y/n)? ";
				cin>>confirm ;
				if(confirm=='y'||confirm=='Y') {
					cout<<"\n\tINFO: Subject data deleted successfully."<<endl;
					deleted=1;
				} 
				else 
					break;						
			} else
				filout.write((char*)&sub,sizeof(sub));
		}

		if(!found)
			cout<<"\n\tERROR: The Subject not found"<<endl;
		
		filout.close();
		cout<<".----------------------------------------------------------------------------."<<endl;
	}
	
	filin.close();
	
	if (deleted) {
		deleteSubjectMapping(sid);
		remove("C:\\tt\\Subjects.dat");
		rename("C:\\tt\\temp.dat","C:\\tt\\Subjects.dat");
	} else {
		remove("C:\\tt\\temp.dat");
	}
}

void subject::viewsubject()
{	
	subject sub, s;
	int sid;
	void viewSubjectMapping(int code);

	cout<<"\n\tEnter Subject Code : ";
	cin>>sid;
	
	s=sub.getsub(sid);
	
	if (!s.notFound()) {
		cout<<"|----------------------------------------------------------------------------|"<<endl;
		cout<<"|     Code     | Subject                                                     |"<<endl;
		cout<<"|----------------------------------------------------------------------------|"<<endl;
		s.display();			
		viewSubjectMapping(sid);
		cout<<".----------------------------------------------------------------------------."<<endl;
	} else {
		cout<<"\n\tERROR: Subject Code does not exist."<<endl;
	}
}

void viewSubjectMapping(int code)
{
	fstream fcst;
	int notfound=1;
	classentity c;
	int l=0;

	fcst.open("C:\\tt\\classsubmap.dat", ios::binary|ios::in);

	if (fcst.bad() || fcst.fail())  {
			fcst.clear();
	} else {
		fcst.seekg(0);

		cout<<"|----------------------------------------------------------------------------|"<<endl;
		cout<<"| Class                    | Lectures | Teacher ID | Teacher                 |"<<endl;
		cout<<"|----------------------------------------------------------------------------|"<<endl;

		while(notfound)
			{
				fcst.read((char*)&c,sizeof(classentity));
				if (fcst.eof()) { notfound = 0; break; }

				for (int i=0; i<c.total_subjects; i++) {
					if (c.subjects[i].subjcode==code) {
						
						l=0;
						l=getlen(c.classid)+getlen(c.grade)+4+strlen(c.cstream);
						
						cout<<" "<<c.classid<<"-"<<c.grade<<"-"<<c.divi<<"-"<<c.cstream;
						for (int z=0; z<(32-l); z++)
							cout<<" ";
						
						cout<<"\t"<<c.subjects[i].numlectures;
					
					//cout<<" "<<c.classid<<"-"<<c.grade<<"-"<<c.divi<<"-"<<c.cstream<<"\t\t"<<c.subjects[i].numlectures;
					cout<<"\t"<<c.subjects[i].teacher.empid<<"\t"<<c.subjects[i].teacher.tname<<endl;
					}
				}
			}
	}

	fcst.close();

}

void deleteSubjectMapping(int code)
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
					if (c.subjects[i].subjcode!=code) {
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

void subjectScreen() {
		clrscr();
		cout<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|                        TIME TABLE APPLICATION                              |"<<endl;
		cout<<"|                        2.0 SUBJECTS MAINTENANCE                            |"<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|    1. List all subjects             2. View subject details                |"<<endl;
		cout<<"|    3. Create subject                4. Delete a subject                    |"<<endl;
		cout<<"|    5. Go Back to Main Menu                                                 |"<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"                          Enter choice: ";
}

void switchsubject()
{	subject s;
	int choice;
	int goBack=0;

	do{
		choice=0;
		subjectScreen();

		cin>>choice;

		switch (choice)
		{	case 1: s.listsubjects();
				break;

			case 2: s.viewsubject();
				break;

			case 3: s.addsubject();
				break;

			case 4: s.removesubject(); //remove mapping
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
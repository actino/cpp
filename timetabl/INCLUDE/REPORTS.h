/*
*				REPORTS.h
*
*
*/
void listCl() {
	
	Class c;		
	fstream filin, filo;
	
	filin.open("C:\\tt\\Class.dat", ios::binary|ios::in);
	
	if (filin.bad() || filin.fail())  {
			cout<<"\n\tERROR: Class data does not exist."<<endl;
			filin.clear();
	} else {
			filin.seekg(0);
			filo.open("C:\\tt\\reports\\claslist.txt", ios::out);
			
			filo<<".----------------------------------------------------------------------------."<<endl;
			filo<<"|                        5.1 List of classes                                 |"<<endl;
			filo<<"|----------------------------------------------------------------------------|"<<endl;
			filo<<"|   CLASS ID   | GRADE | DIVISION | STREAM                                   |"<<endl;
			filo<<"|----------------------------------------------------------------------------|"<<endl;

			while(1) {
				filin.read((char*)&c,sizeof(c));
				if (filin.eof()) break;
				filo<<"      "<<c.getID()<<"          "<<c.getgrade()<<"        "<<c.getdiv()<<"       "<<c.getstream();
				filo<<endl;
			}

			filo<<".----------------------------------------------------------------------------."<<endl;
			filo.close();
			cout<<"\n\tINFO: Report generated successfully at C:\\tt\\reports\\claslist.txt"<<endl;
	}
	filin.close();
	
}

void listSu() {
	
	subject s;
	fstream filin, filo;
	
	filin.open("C:\\tt\\Subjects.dat", ios::binary|ios::in);
	
	if (filin.bad() || filin.fail())  {
			cout<<"\n\tERROR: Subject data does not exist."<<endl;
			filin.clear();
	} else {
			filin.seekg(0);
			filo.open("C:\\tt\\reports\\subjlist.txt", ios::out);
			
			filo<<".----------------------------------------------------------------------------."<<endl;
			filo<<"|                        5.2 List of subjects                                |"<<endl;
			filo<<"|----------------------------------------------------------------------------|"<<endl;
			filo<<"|     Code     | Subject                                                     |"<<endl;
			filo<<"|----------------------------------------------------------------------------|"<<endl;
		
			while(1) {
				filin.read((char*)&s,sizeof(s));
				if (filin.eof()) break;
				filo<<"\t"<<s.getcode()<<"\t "<<s.getsubname()<<endl;
			}

			filo<<".----------------------------------------------------------------------------."<<endl;
			filo.close();
			cout<<"\n\tINFO: Report generated successfully at C:\\tt\\reports\\subjlist.txt"<<endl;
	}
	filin.close();
}

void listTchr() {
	teacher t;
	fstream filin, filo;
	
	filin.open("C:\\tt\\Teachers.dat", ios::binary|ios::in);
	
	if (filin.bad() || filin.fail())  {
			cout<<"\n\tERROR: Teacher data does not exist."<<endl;
			filin.clear();
	} else {
			filin.seekg(0);
			filo.open("C:\\tt\\reports\\tchrlist.txt", ios::out);
			
			filo<<".----------------------------------------------------------------------------."<<endl;
			filo<<"|                        5.3 List of teachers                                |"<<endl;
			filo<<"|----------------------------------------------------------------------------|"<<endl;
			filo<<"|     ID      | Name                                                         |"<<endl;
			filo<<"|----------------------------------------------------------------------------|"<<endl;
		
			while(1) {
				filin.read((char*)&t,sizeof(t));
				if (filin.eof()) break;
				filo<<"\t"<<t.getid()<<"\t"<<t.gettname()<<endl;				
			}

			filo<<".----------------------------------------------------------------------------."<<endl;
			filo.close();
			cout<<"\n\tINFO: Report generated successfully at C:\\tt\\reports\\tchrlist.txt"<<endl;
	}
	filin.close();
}

void listMapping() {
	fstream fcst, filo;
	classentity c;
	char prns[20];
	
	fcst.open("C:\\tt\\classsubmap.dat", ios::binary|ios::in);
	
	if (fcst.bad() || fcst.fail())  {
			cout<<"\n\tERROR: Mapping data does not exist."<<endl;
			fcst.clear();
	} else {
		fcst.seekg(0);
		filo.open("C:\\tt\\reports\\mapping.txt", ios::out);
		
		filo<<".----------------------------------------------------------------------------."<<endl;
		filo<<"|             5.4 Class-Subject-Teacher Mapping Details                      |"<<endl;
		filo<<"|----------------------------------------------------------------------------|"<<endl;
			
		while(1)
			{	
				fcst.read((char*)&c,sizeof(classentity));
				if (fcst.eof()) break;
				
				
					filo<<"\n\t\tClass: "<<c.classid<<"-"<<c.grade<<" - "<<c.divi<<" - "<<c.cstream<<endl;
					filo<<"|----------------------------------------------------------------------------|"<<endl;
					filo<<"| Code |      Subject      | Lectures | Teacher ID | Teacher                 |"<<endl;
					filo<<"|----------------------------------------------------------------------------|"<<endl;
					for (int i=0; i<c.total_subjects; i++) {
						strcpy(prns, emptyString20);
						strcpy(prns, c.subjects[i].subjname);
						
						filo<<"   "<<c.subjects[i].subjcode;
						/* Subject code has variable length, hence fill in appropriate
						 * number of spaces after printing code */ 
						if (getlen(c.subjects[i].subjcode) == 2)
							filo<<"    ";
						else if (getlen(c.subjects[i].subjcode) == 3)
							filo<<"   ";
						else 
							filo<<"  ";
						filo<<prns;
						
						for (int z=0; z<(24-strlen(prns)); z++)
							filo<<" ";
						
						//<<"   \t\t"
						filo<<c.subjects[i].numlectures;
						filo<<"\t"<<c.subjects[i].teacher.empid<<"\t"<<c.subjects[i].teacher.tname<<endl;					
					}
					filo<<".----------------------------------------------------------------------------."<<endl;			
			}	
		
		filo.close();
		cout<<"\n\tINFO: Report generated successfully at C:\\tt\\reports\\mapping.txt"<<endl;		
	}
	fcst.close();
}

void listTT() {
	
	fstream ftin,filo;
	tout tt;
	int i, j, k;
		
	ftin.open("C:\\tt\\ttfinal.dat", ios::binary|ios::in);
	
	if (ftin.bad() || ftin.fail())  {
			ftin.clear();
			cout<<"\n\tERROR: Time table data not generated."<<endl;
	} else {	
	
		ftin.seekg(0);
		filo.open("C:\\tt\\reports\\tible.txt", ios::out);

		filo<<".----------------------------------------------------------------------------."<<endl;
		filo<<"|                       5.5 Class wise Time Tables                           |"<<endl;
		filo<<"|----------------------------------------------------------------------------|"<<endl;
	
		while(1)
		{	ftin.read((char*)&tt,sizeof(tout));
			if (ftin.eof()) break;
			
				
				filo<<"\n\t\t  Timetable for class - "<<tt.cl.grade;
				filo<<" - "<<tt.cl.divi<<" - "<<tt.cl.cstream<<endl;
				filo<<"|----------------------------------------------------------------------------|"<<endl;
				filo<<"   Time      Monday       Tuesday      Wednesday    Thursday     Friday       "<<endl;
				filo<<"|----------------------------------------------------------------------------|"<<endl;
				
				for (i=0; i<num_Lect; i++)
				{ 					
					filo<<"\n";
					switch(i)
					{
						case 0: filo<<" 7:15- 8:15  ";
								break;
						case 1: filo<<" 8:15- 9:15  ";
								break;
						case 2: filo<<" 9:15-10:15  ";
								break;
						case 3: filo<<"11:00-12:00  ";
								break;
						case 4: filo<<"12:00-13:00  ";
								break;
						default:filo<<"--:-----:--  ";
								break;
					}
					
					for (j=0; j<num_Days; j++)
					{	for (k=0; k<12; k++) //only print 12 characters
							filo<<tt.su.fsubj[i].fsubj[j].fsubj[k];
						filo<<" ";
					}
					
					filo<<"\n             ";
					
					for (j=0; j<num_Days; j++)
					{	for (k=0; k<10; k++) //only print 10 characters
							filo<<tt.te.ftchr[i].ftchr[j].ftchr[k];
						filo<<"   ";
					}
					
					filo<<"\n------------------------------------------------------------------------------";
					
					if (i==2) {
						filo<<"\n10:15-11:00  ";	//Print break
						for (j=0; j<num_Days; j++)
							filo<<"Break        ";
						filo<<"\n------------------------------------------------------------------------------";
					}					
				}
			filo<<"\n";			 
		}
		filo.close();
		cout<<"\n\tINFO: Report generated successfully at C:\\tt\\reports\\tible.txt"<<endl;
	}
	ftin.close();
}

void reportScreen() {
		clrscr();
		cout<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|                        TIME TABLE APPLICATION                              |"<<endl;
		cout<<"|                            5.0 REPORTS                                     |"<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|    1. List of classes               2. List of subjects                    |"<<endl;
		cout<<"|    3. List of teachers              4. Print Class-Subject-Teacher Mapping |"<<endl;
		cout<<"|    5. Download Time Tables          6. Go Back to Main Menu                |"<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"                          Enter choice: ";
}

void switchreports()
{	
	int choice;
	int goBack=0;

	do{
		choice=0;
		reportScreen();

		cin>>choice;

		switch (choice)
		{	case 1: listCl();
				break;

			case 2: listSu();
				break;

			case 3: listTchr();
				break;

			case 4: listMapping();
				break;

			case 5: listTT();
				break;

			case 6:
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
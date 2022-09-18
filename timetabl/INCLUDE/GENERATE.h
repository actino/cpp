/*
*				GENERATE.h
*
*
*/
classentity clsmap[num_ClassDiv];  //Total 20 classes

struct classdiv
	{
		int classid;
		int grade;
		char divi;
		char cstream[20];

		struct
		{
			struct
			{
				int busy;
			}
			busy[num_Days]; //5 days per week
		}
		busy[num_Lect]; //5 lectures per day
	};

	classdiv clsdiv[num_ClassDiv];

struct steacher
	{
		int empid;
		char tname[20];

		struct
		{
			struct
			{
				int busy;
			}
			busy[num_Days]; //5 days per week
		}
		busy[num_Lect]; //5 lectures per day
	};

	steacher tchr[num_Tchr]; //Total 25 teachers

struct fsubj
	{
	struct
		{
			struct
			{
				char fsubj[20]; //subject
			}
			fsubj[num_Days];  //day of the week
		}
		fsubj[num_Lect];	//lecture of the day
	};

struct ftchr
	{
		struct
		{
			struct
			{
				char ftchr[20]; //teacher name
			}
			ftchr[num_Days]; //day of the week
		}
		ftchr[num_Lect]; 	//lecture of the day
	};

struct strsub
	{
	struct
		{
			struct
			{
				char tmpsubj[20]; //subject
			}
			tmpsubj[num_Days];  //day of the week
		}
		tmpsubj[num_Lect];	//lecture of the day
	}
	tmpsubj[num_ClassDiv];  //class-div

struct strtchr
	{
		struct
		{
			struct
			{
				char tmptchr[20]; //teacher name
			}
			tmptchr[num_Days]; //day of the week
		}
		tmptchr[num_Lect]; //lecture of the day
	}
	tmptchr[num_ClassDiv]; //class-div

struct tout
	{
		classdiv cl;
		fsubj su;
		ftchr te;
	};

int clsnum, total_teachers;
int set=0,settmp=0,done=0;

void linkheader() {
	clrscr();
	cout<<endl;
	cout<<".----------------------------------------------------------------------------."<<endl;
	cout<<"|                        TIME TABLE APPLICATION                              |"<<endl;
	cout<<"|                    4.1 Link Class-Subject-Teacher                          |"<<endl;
	cout<<".----------------------------------------------------------------------------."<<endl;
}

void linkdata()
{
	//Link Class - subject - teacher

	classentity ce;
	Class c;
	subject sub;
	teacher t;
	int cl, scode, nl, tch;
	fstream fin;
	int newData=0;
	int ccount=0;
	int cfound=0, sfound=0; //tfound=0;
	int allgood=1;
	char ans='y';

	fin.open("C:\\tt\\classsubmap.dat", ios::binary|ios::in);

	if (fin.bad() || fin.fail())  {
			newData=1;
			fin.clear();
	} else {
		fin.seekg(0);
		while(1)
			{	fin.read((char*)&ce,sizeof(classentity));
				if (fin.eof()) break;
				clsmap[ccount] = ce;
				ccount++;
			}
	}
	fin.close();

	if ((c.getccount()>0)&&(sub.getscount()>0)&&(t.gettcount()>0))
	{	
		do {
			linkheader();
			c.viewallrecords();
			cout<<"\nSelect class id: ";
			cin>>cl;
			if (cl==-1) break; //A small trick to exit the feature if user wants to
			c=c.getcls(cl);
			if (c.notFound()) {
				cout<<"\n\tERROR: Please select a valid class ID."<<endl;
				break;
			}

			linkheader();
			cout<<"\tLinking subject to class: "<<c.getID()<<"-"<<c.getgrade()<<"-"<<c.getdiv()<<"-"<<c.getstream()<<" =>"<<endl;
			sub.listsubjects();
			cout<<"\nSelect subject code: ";
			cin>>scode;
			if (scode==-1) break; //A small trick to exit the feature if user wants to
			sub=sub.getsub(scode);
			if (sub.notFound()) {
				cout<<"\n\tERROR: Please select a valid subject code."<<endl;
				break;
			}
			cout<<"\nEnter No. of lectures per week for class: "<<c.getgrade()<<"-"<<c.getdiv()<<" : ";
			cin>>nl;

			linkheader();
			cout<<"\tLinking teacher to subject "<<scode<<"-"<<sub.getsubname()<<" of class: "<<c.getID()<<"-"<<c.getgrade()<<"-"<<c.getdiv()<<"-"<<c.getstream()<<" =>"<<endl;
			t.listteacher();
			cout<<"\nSelect teacher id: ";
			cin>>tch;
			if (tch==-1) break; //A small trick to exit the feature if user wants to
			t=t.gettchr(tch);
			if (t.notFound()) {
				cout<<"\n\tERROR: Please select a valid teacher ID."<<endl;
				break;
			}

			if (!newData) {
				for (int i=0; i<ccount; i++) {
					if (clsmap[i].classid == cl) {
						cfound=1;
						//class found - so update clsmap
						for (int j=0; j<clsmap[i].total_subjects; j++) {
							if (clsmap[i].subjects[j].subjcode == scode) {
								sfound=1;
								//subject found - so only teacher can be updated
								if (clsmap[i].subjects[j].teacher.empid == tch) {
									//Same Teacher - no action
									//tfound=1;
									allgood=0;
								} else {
									//Different teacher - Update Teacher
									clsmap[i].subjects[j].teacher.empid = t.getid();
									strcpy(clsmap[i].subjects[j].teacher.tname,emptyString20);
									strcpy(clsmap[i].subjects[j].teacher.tname,t.gettname());
								}
								break;
							}
						}
						if (!sfound) {
							//subject not found - so add subject to the class

							if ((clsmap[i].total_subjects<10)&&(clsmap[i].total_lectures+nl<=25)) {
								clsmap[i].subjects[clsmap[i].total_subjects].subjcode=sub.getcode();
								strcpy(clsmap[i].subjects[clsmap[i].total_subjects].subjname,emptyString20);
								strcpy(clsmap[i].subjects[clsmap[i].total_subjects].subjname,sub.getsubname());
								clsmap[i].subjects[clsmap[i].total_subjects].numlectures=nl;
								clsmap[i].subjects[clsmap[i].total_subjects].teacher.empid = t.getid();
								strcpy(clsmap[i].subjects[clsmap[i].total_subjects].teacher.tname,emptyString20);
								strcpy(clsmap[i].subjects[clsmap[i].total_subjects].teacher.tname,t.gettname());

								clsmap[i].total_subjects++;
								clsmap[i].total_lectures+=nl; //can be maximum 25
							}
							else {
								allgood=0;
								cout<<"\n\tWARNING: This class cannot accommodate additional subject and/or lectures."<<endl;
							}

						}
						break;
					}
				}
			}

			if (!cfound) {

				//class not found - so add to clsmap
				//Also when you are adding the first mapping, when newData is true
				//ccount will be 0 when first time or equals number of classes

				if (ccount<num_ClassDiv) {

					clsmap[ccount].classid=c.getID();
					clsmap[ccount].grade=c.getgrade();
					clsmap[ccount].divi=c.getdiv();
					strcpy(clsmap[ccount].cstream,emptyString20);
					strcpy(clsmap[ccount].cstream,c.getstream());

					clsmap[ccount].total_subjects=0;	//First subject
					clsmap[ccount].total_lectures=nl; 	//can be maximum 25

					clsmap[ccount].subjects[clsmap[ccount].total_subjects].subjcode=sub.getcode();
					strcpy(clsmap[ccount].subjects[clsmap[ccount].total_subjects].subjname,emptyString20);
					strcpy(clsmap[ccount].subjects[clsmap[ccount].total_subjects].subjname,sub.getsubname());
					clsmap[ccount].subjects[clsmap[ccount].total_subjects].numlectures=nl;
					clsmap[ccount].subjects[clsmap[ccount].total_subjects].teacher.empid = t.getid();
					strcpy(clsmap[ccount].subjects[clsmap[ccount].total_subjects].teacher.tname,emptyString20);
					strcpy(clsmap[ccount].subjects[clsmap[ccount].total_subjects].teacher.tname,t.gettname());

					clsmap[ccount].total_subjects++;
					ccount++;

				} else {
					allgood=0;
					cout<<"\n\tWARNING: The application is already configured for "<<num_ClassDiv<<" classes. It cannot accommodate additional classes."<<endl;
				}

			}

			if (allgood) {
				//clsmap has been updated, so write to file
				//Overwrite the file completely
				fin.open("C:\\tt\\classsubmap.dat", ios::binary|ios::out);

				for (int x=0; x<ccount; x++) {
					ce = clsmap[x];
					fin.write((char*)&ce,sizeof(classentity));
				}
				fin.close();
				newData=0; //reset for the next loop - This is needed to allow multiple linking on first attempt
				cfound=0; //reset for the next loop
				sfound=0; //reset for the next loop
				cout<<"\n\tINFO: The class - subject - teacher link saved successfully."<<endl;
			} else
				allgood = 1; //reset for the next loop

			cout<<"\n\tWant to link more? Continue(y/n)?";
			cin>>ans;

		}while(ans=='y'||ans=='Y');
		
	} else {
		cout<<"\n\tERROR: Either class or subject or teacher data not created. Please do the same before linking."<<endl;
	}
	//getch();

}

int readdata()
{
	classentity c;
	//teacher t;	//This is teacher 'class'
	fstream fin;
	int tfound=0;
	int success=1;

	cout<<"\n\tINFO:...Initializing......";

	clsnum=0; //Total number of class-divisions
	total_teachers=0; //Total teachers in the school
	//clsdone=0; //Number of class-divisions completing time table generation process
	//done=0;

	//Read Class Data
	fin.open("C:\\tt\\classsubmap.dat", ios::binary|ios::in);

	if (fin.bad() || fin.fail())  {
			cout<<"\n\tERROR: The data has not been linked yet. Please link data and try again."<<endl;
			fin.clear();
			success=0;
	} else {

		fin.seekg(0);

		cout<<"\n\tINFO:...Reading Master Data......";

		while(1)
			{	fin.read((char*)&c,sizeof(classentity));
				if (fin.eof()) break;

				if (clsnum < num_ClassDiv) {
					//Read only 20 class-div into the model
					clsmap[clsnum] = c;
					//populate clsdiv

					clsdiv[clsnum].classid = c.classid;
					clsdiv[clsnum].grade = c.grade;
					clsdiv[clsnum].divi = c.divi;
					strcpy(clsdiv[clsnum].cstream,emptyString20);
					strcpy(clsdiv[clsnum].cstream,c.cstream);

					for (int i=0; i<num_Lect; i++)
						for (int j=0; j<num_Days; j++)
							clsdiv[clsnum].busy[i].busy[j].busy=0;

					clsnum++;

					for (int k=0; k<c.total_subjects; k++) {
						tfound=0;
						for (int l=0; l<total_teachers; l++) {
							if (c.subjects[k].teacher.empid == tchr[l].empid) {
								tfound=1;
								break;
							}
						}
						if (!tfound) {
							tchr[total_teachers].empid = c.subjects[k].teacher.empid;
							strcpy(tchr[total_teachers].tname, emptyString20);
							strcpy(tchr[total_teachers].tname, c.subjects[k].teacher.tname);

							for (int p=0; p<num_Lect; p++)
								for (int q=0; q<num_Days; q++)
									tchr[total_teachers].busy[p].busy[q].busy=0;

							total_teachers++;
						}
					}
				} else {
					break;
				}
			}
			cout<<"......complete";
	}
	fin.close();
	return success;
	
}

void writetofile()
{
	int i,j,k;
	fstream fo;
	tout too;

	fo.open("C:\\tt\\ttfinal.dat", ios::out|ios::binary);
	cout<<"\n\tINFO:...Writing Timetable to file......";
	for(i=0;i<clsnum;i++)
	{
		too.cl = clsdiv[i];
		for(j=0;j<num_Lect;j++)
			for(k=0;k<num_Days;k++)
			{
			strcpy(too.te.ftchr[j].ftchr[k].ftchr,emptyString20);
			strcpy(too.su.fsubj[j].fsubj[k].fsubj,emptyString20);
			strcpy(too.te.ftchr[j].ftchr[k].ftchr,tmptchr[i].tmptchr[j].tmptchr[k].tmptchr);
			//strcpy(too.te.ftchr[j].ftchr[k].ftchr,"12345678901234567890");
			strcpy(too.su.fsubj[j].fsubj[k].fsubj,tmpsubj[i].tmpsubj[j].tmpsubj[k].tmpsubj);
			}
		//write tout to file
		fo.write((char*)&too,sizeof(tout));
	}

	fo.close();
	cout<<".........complete";

}

void generatett(int a, int b, int c)
{
	//a : class, b : Lecture in the day, c : Day of the week
	//This algorithm traverses horizontally from Monday to Friday and then for every
	//time slot from top to bottom and allot a subject and teacher to that slot

	int tref; //Teacher reference 

	//if ((a < clsnum) && (clsdone != clsnum)) {
	if ((a < clsnum)&&(set!=clsnum)) {
		// Till all classes are done


		for (int s=0; s < clsmap[a].total_subjects; s++){
			//For every subject for a class

			for (int t=0; t < total_teachers; t++) {
				//For the teacher of the subject, find the reference in tchr structure array
				if (clsmap[a].subjects[s].teacher.empid == tchr[t].empid) {
					tref = t;
					break;
				}
					
			}
		
			if ((clsmap[a].subjects[s].numlectures > 0) &&
				(!clsdiv[a].busy[b].busy[c].busy) &&
				(!tchr[tref].busy[b].busy[c].busy))	{
			
			//if there are more lectures of the subject to be planned
			//if the timeslot for the class and the teacher are empty
			//then book the slot
				
				strcpy(tmptchr[a].tmptchr[b].tmptchr[c].tmptchr,emptyString20);
				strcpy(tmpsubj[a].tmpsubj[b].tmpsubj[c].tmpsubj,emptyString20);
				strcpy(tmptchr[a].tmptchr[b].tmptchr[c].tmptchr,tchr[tref].tname);
				strcpy(tmpsubj[a].tmpsubj[b].tmpsubj[c].tmpsubj,clsmap[a].subjects[s].subjname);
				
				cout<<"\n"<<clsmap[a].classid<<"-"<<clsmap[a].grade;
				cout<<"-"<<clsmap[a].divi<<"-"<<clsmap[a].cstream;
				cout<<"-"<<clsmap[a].subjects[s].subjname;
				cout<<"-"<<clsmap[a].subjects[s].numlectures<<"-"<<tchr[tref].tname<<"...";
				
				clsmap[a].subjects[s].numlectures--;
				//clsmap[a].total_lectures--;
				
				tchr[tref].busy[b].busy[c].busy=1;
				clsdiv[a].busy[b].busy[c].busy=1;
								
				if(b==(num_Lect-1) && c==(num_Days-1))
					set++;
				
				if(settmp<set)
				{
					settmp=set;
					writetofile();
					//save(i); 
				}
			
				generatett(a+(b+(c+1)/num_Days)/num_Lect,(b+(c+1)/num_Days)%num_Lect,(c+1)%num_Days);
				
				if(!done)
				{
				if(b==(num_Lect-1) && c==(num_Days-1))				//backtrack start
					set--;	
				
				clsmap[a].subjects[s].numlectures++;
				
				tchr[tref].busy[b].busy[c].busy=0;
				clsdiv[a].busy[b].busy[c].busy=0;
				
				strcpy(tmptchr[a].tmptchr[b].tmptchr[c].tmptchr,emptyString20);
				strcpy(tmpsubj[a].tmpsubj[b].tmpsubj[c].tmpsubj,emptyString20);
				}
			}
		}

		//if all 25 slots are not required for a particular class
		//fill in the remaining slots of the week with dummy data
		
		if (clsmap[a].total_lectures <= num_Slots) {
			
			strcpy(tmptchr[a].tmptchr[b].tmptchr[c].tmptchr,emptyString20);
			strcpy(tmpsubj[a].tmpsubj[b].tmpsubj[c].tmpsubj,emptyString20);
			strcpy(tmptchr[a].tmptchr[b].tmptchr[c].tmptchr,"-");
			strcpy(tmpsubj[a].tmpsubj[b].tmpsubj[c].tmpsubj,"QB Period");
			clsmap[a].total_lectures++; //Increment upto 25 to fill-in the slots
			
			cout<<"\n"<<clsmap[a].classid<<"-"<<clsmap[a].grade;
			cout<<"-"<<clsmap[a].divi<<"-"<<clsmap[a].cstream;
			cout<<"-"<<"QB Period"<<"-"<<"..."<<"-"<<"......";
			
			if(b==(num_Lect-1) && c==(num_Days-1))
				set++;
				
			if(settmp<set)
			{
				settmp=set;
				//save(i);
				writetofile();
				
			}
			
			generatett(a+(b+(c+1)/num_Days)/num_Lect,(b+(c+1)/num_Days)%num_Lect,(c+1)%num_Days);
			
			if(!done)
			{
				if(b==(num_Lect-1) && c==(num_Days-1))				//backtrack start
					set--;
				clsmap[a].total_lectures--;
				strcpy(tmptchr[a].tmptchr[b].tmptchr[c].tmptchr,emptyString20);
				strcpy(tmpsubj[a].tmpsubj[b].tmpsubj[c].tmpsubj,emptyString20);
			
			}
		}
		
	} else {
		done=1;
		//writetofile();
		cout<<"\n\tINFO: Time Table generated successfully!!!";
	}
}

void printslot(int i)
{
	cout<<"\n";
	switch(i)
	{
		case 0: cout<<" 7:15- 8:15  ";
				break;
		case 1: cout<<" 8:15- 9:15  ";
				break;
		case 2: cout<<" 9:15-10:15  ";
				break;
		case 3: cout<<"11:00-12:00  ";
				break;
		case 4: cout<<"12:00-13:00  ";
				break;
		case 99:cout<<"10:15-11:00  ";
				break;
		default:cout<<"--:-----:--  ";
				break;
	}
	//cout<<"\t";
}

void printclasstt(int classID) {
	fstream ftin;
	tout tt;
	int i, j, k;
	
	clrscr();
	cout<<endl;
	cout<<".----------------------------------------------------------------------------."<<endl;
	cout<<"|                        TIME TABLE APPLICATION                              |"<<endl;
	cout<<"|                        4.2 Print Timetable                                 |"<<endl;
	cout<<".----------------------------------------------------------------------------."<<endl;
		
	ftin.open("C:\\tt\\ttfinal.dat", ios::binary|ios::in);
	
	if (ftin.bad() || ftin.fail())  {
			ftin.clear();
			cout<<"\n\tERROR: Time table data not generated."<<endl;
	} else {	
	
	ftin.seekg(0);
	
	while(1)
		{	ftin.read((char*)&tt,sizeof(tout));
			if (ftin.eof()) break;
			
			if (tt.cl.classid ==  classID) {
				
				cout<<"\t\t  Timetable for class - "<<tt.cl.grade;
				cout<<" - "<<tt.cl.divi<<" - "<<tt.cl.cstream<<endl;
				
				cout<<"   Time      Monday       Tuesday      Wednesday    Thursday     Friday       "<<endl;
				
				for (i=0; i<num_Lect; i++)
				{ 
					printslot(i);
					for (j=0; j<num_Days; j++)
					{	for (k=0; k<12; k++) //only print 12 characters
							cout<<tt.su.fsubj[i].fsubj[j].fsubj[k];
						cout<<" ";
						//cout<<tt.su.fsubj[i].fsubj[j].fsubj<<" ";
					}
					cout<<"\n             ";
					for (j=0; j<num_Days; j++)
					{	for (k=0; k<10; k++) //only print 10 characters
							cout<<tt.te.ftchr[i].ftchr[j].ftchr[k];
						cout<<"   ";
						//cout<<tt.te.ftchr[i].ftchr[j].ftchr<<" ";
					}
					//cout<<"Time         Monday       Tuesday      Wednesday    Thursday     Friday       "<<endl;
					cout<<"\n------------------------------------------------------------------------------";
					if (i==2) {
						printslot(99);	//Print break
						for (j=0; j<num_Days; j++)
							cout<<"Break        ";
						//cout<<endl;
						cout<<"\n------------------------------------------------------------------------------";
					}
					
				}
				break;
			} 
		}
	//cout<<".----------------------------------------------------------------------------."<<endl;
	}
	ftin.close();
}

void ttScreen() {
		clrscr();
		cout<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|                        TIME TABLE APPLICATION                              |"<<endl;
		//cout<<"|                                                                            |"<<endl;
		cout<<"|                        4.0 Generate Timetable                              |"<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|    1. Link Class-Subject-Teacher    2. Generate Timetable                  |"<<endl;
		cout<<"|    3. Print Timetable               4. Go Back to Main Menu                |"<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"                          Enter choice: ";
}

void switchtt()
{
	int choice;
	int goBack=0;
	int cid;
	char confirm='n';
	//Class c;

	do{
		choice=0;
		ttScreen();
		cin>>choice;

		switch (choice)
		{	
			case 1: linkdata();
				break;
		
			case 2: cout<<"\n\tWARNING! All previous timetables will be erased. Continue(y/n)? ";
				cin>>confirm ;
				if(confirm=='y'||confirm=='Y') {
					if(readdata()){
						cout<<"\n...Starting Recursive Genertic Algorithm......";
						generatett(0,0,0);
					}
				}
				break;

			case 3: cout<<"\n Enter class ID: ";
				cin>>cid;
				printclasstt(cid);
				break;

			case 4:	goBack=1;
				break ;

			default:cout<<"\n\tERROR: Invalid Choice!"<<endl;
				break ;
		};
		
		if (!goBack) {
			cout<<endl<<"Press any key to continue...";
			getch();				
		}
			 
	} while(!goBack);
}
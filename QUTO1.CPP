#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	clrscr();

	char oneLine[400];
	//char outLine[400];
	char t[8]; 	//TrainNo
	char s[5]; 	//start
	char e[5]; 	//end
	char d[3]; 	//direction
	char tt[200]; 	//TimeTable
	char hhmm[200];

	ofstream outfile;
	ifstream infile;

	outfile.open("C:\\Jdata\\dcsvo.txt",ios::app);
	infile.open("C:\\Jdata\\dcsv1.txt",ios::in);

	//ofstream outfile("C:\\Jdata\\ucsvo.txt",ios::app);
	//ifstream infile("C:\\Jdata\\ucsv1.txt",ios::in);

	if (!infile) {
		cerr << "Failed to open input file \n";
		getch();
		exit(1);
	}
	cout<<"The process begins...";
	//infile.seekg(0);

	strcpy(oneLine,"");

	while (!infile.eof()) {
	       infile.getline(t,8,',');
	       infile.getline(s,5,',');
	       infile.getline(e,5,',');
	       infile.getline(d,3,',');
	       infile.getline(tt,200,'\n');

	       strcat(oneLine,"{trainNo: '");
	       strcat(oneLine,t);
	       strcat(oneLine,"'*start: '");
	       strcat(oneLine,s);
	       strcat(oneLine,"'*end: '");
	       strcat(oneLine,e);
	       strcat(oneLine,"'*dir: '");
	       strcat(oneLine,d);
	       strcat(oneLine,"'*tt: ['");

	       strcat(oneLine, tt);
	       strcat(oneLine,"']}*");
	       outfile<<oneLine<<"\n";

	       strcpy(oneLine,"");
	       strcpy(tt,"");
	       strcpy(hhmm,"");

	}

	infile.close();
	outfile.close();

	outfile.open("C:\\Jdata\\dcsvo2.txt",ios::app);
	infile.open("C:\\Jdata\\dcsvo.txt",ios::in);


	if (!infile) {
		cerr << "Failed to open input file \n";
		getch();
		exit(1);
	}
	cout<<"The process step 2 begins...";
	//infile.seekg(0);
	strcpy(oneLine,"");

	while (!infile.eof()) {
	       infile.getline(oneLine,200,',');
	       strcat(oneLine,"','");
	       outfile<<oneLine;
	       strcpy(oneLine,"");
	}

	infile.close();
	outfile.close();

	outfile.open("C:\\Jdata\\dcsvo3.txt",ios::app);
	infile.open("C:\\Jdata\\dcsvo2.txt",ios::in);


	if (!infile) {
		cerr << "Failed to open input file \n";
		getch();
		exit(1);
	}
	cout<<"The process step 3 begins...";
	//infile.seekg(0);
	strcpy(oneLine,"");

	while (!infile.eof()) {
	       infile.getline(oneLine,200,'*');
	       strcat(oneLine,",");
	       outfile<<oneLine;
	       strcpy(oneLine,"");
	}

	infile.close();
	outfile.close();


	cout<<"Wrote to file";

	getch();
	return 0;
	}
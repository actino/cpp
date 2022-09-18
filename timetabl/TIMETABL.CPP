/*
*				TIMETABL.cpp
*
*
*/
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip.h>

#include<csutemap.h>
#include<classdiv.h>
#include<subjects.h>
#include<teachers.h>
#include<generate.h>
#include<reports.h>


void displayMainMenu() {
		clrscr();
		cout<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|                      R. N. PODAR SCHOOL, POWAI                             |"<<endl;
		cout<<"|                                                                            |"<<endl;
		cout<<"| ####### ###  ##     ##  ######     #######   ##    ####  #     ######      |"<<endl;
		cout<<"|    #     #   # #   # #  #             #     #  #   #   # #     #           |"<<endl;
		cout<<"|    #     #   #  # #  #  #####         #    #    #  ####  #     #####       |"<<endl;
		cout<<"|    #     #   #   #   #  #             #    ######  #   # #     #           |"<<endl;
		cout<<"|    #    ###  #       #  ######        #    #    #  ##### ##### ######      |"<<endl;
		cout<<"|                                                                            |"<<endl;
		cout<<"|                           Version 1.0 2019-20                              |"<<endl;
		cout<<"|                                                                            |"<<endl;
		cout<<"|          Developed By: JASMIN R CHAUGHULE & KAVITA SRIRAM                  |"<<endl;
		cout<<"|                 Coach: Prof. POOJA AGGARWAL                                |"<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<"|                                                                            |"<<endl;
		cout<<"|            *** Welcome to the Time Table Application ***                   |"<<endl;
		cout<<"|                                                                            |"<<endl;
		cout<<"|                              MAIN MENU                                     |"<<endl;
		cout<<"|                                                                            |"<<endl;
		//cout<<"|      1.Class   "<<"2.Subjects   "<<"3.Teachers   "<<"4.Time Table   "<<"5.Exit             |"<<endl;
		cout<<"|   1.Class   2.Subjects   3.Teachers   4.Time Table   5.Reports   6.Exit    |"<<endl;
		cout<<".----------------------------------------------------------------------------."<<endl;
		cout<<endl;
		cout<<"                          Enter choice: ";
}

void main()
{
	int choice;

	displayMainMenu();

	do{
		choice=0;

		cin>>choice;

		switch (choice)
		{	case 1: switchclass();
				displayMainMenu();
				break;
			case 2: switchsubject();
				displayMainMenu();
				break;
			case 3: switchteacher();
				displayMainMenu();
				break;
			case 4: switchtt();
				displayMainMenu();
				break;
			case 5: switchreports();
				displayMainMenu();
				break;
			case 6: exit(0);
				break ;
			default:
				cout<<"\n\tERROR: Invalid Choice! Press any key to continue..."<<endl;
				getch();
				displayMainMenu();
				break ;
		}
	} while(1);
}
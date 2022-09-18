#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
 void main()
 { 	clrscr();
	char str[100]="Time is great teacher but unfortunately it kills all its pupils.Berlioz";

	fstream filout;
	filout.open("C:\\Jdata\\OUT.txt",ios::out);
	int len=strlen(str);

	for(int i=0;i<len;i++)
	{ filout<<str[i];
	}
	filout.close();

	filout.open("C:\\Jdata\\OUT.txt",ios::in);
	//for(int j=0;j<len;j++)
	filout.getline(str,100);
      //	cout<<str;
	filout.close();

	getch();
 }
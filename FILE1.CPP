#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

int main()
{
	clrscr();

	char info[80];
	char str2[90];

	fstream filout;
	filout.open("C:\\Jdata\\first.txt", ios::out);
	cout<<"Enter file text: ";
	gets(info);
	filout<<info;
	filout.close();
	cout<<"Wrote to file";

       ofstream filin;
	filin.open("C:\\Jdata\\second.txt",ios::out);
       //	ofstream fout;

     //	ifstream filout;
	filout.open("C:\\Jdata\\first.txt", ios::in);
	filout.seekg(0);
	while(!filout.eof())
	{       filout.getline(info,80,' ');
	      //	for(int i=0;i<strlen(info);i++)
	       //	{ if(info[i]==' ')
			if(info[0]=='a'||info[0]=='e'||info[0]=='i'||info[0]=='o'||info[0]=='u')
			       //	{ //  for(int j=i+1;info[j]!=' ';j++)
				       {	strcpy(str2,info);
						filin<<str2<<"\n ";
				       }
			       //	}

	       //	}

	}
	filout.close();
	filin.close();


	getch();
	return 0;
}
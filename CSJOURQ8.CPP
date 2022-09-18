#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>

void main()
{       clrscr();
	fstream f1;

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 8 - Manipulating a text file"<<endl<<endl;

	f1.open("C:\\Jdata\\Lines.txt", ios::out);
	char content[15000];
	int lines,i;

	cout<<"Enter number of lines: ";
	cin>>lines;

	for(i=1;i<=lines;i++)
	{	//cout<<"Line "<<i<<endl;
		cout<<"Enter line "<<i<<" : ";
		gets(content);
		f1<<content<<endl;
	}
	f1.close();

	cout<<endl<<"--------------------- Reading from file -------------------"<<endl;

	f1.open("C:\\Jdata\\Lines.txt", ios::in);
	f1.seekg(0);
	for(i=1;i<=lines;i++)
	{       int cw=0,cv=0;
		f1.getline(content,200,'\n');
		cout<<"Line "<<i<<"\t";
		cout<<content<<endl;
		cout<<"      \t";
		for(int j=strlen(content)-1;j>=0;j--)
		{	cout<<content[j];
			if(content[j]==' ')
				cw++;
			if(content[j]=='a'||content[j]=='e'||content[j]=='i'||content[j]=='o'||content[j]=='u'||content[j]=='A'||content[j]=='E'||content[j]=='I'||content[j]=='O'||content[j]=='U')
				cv++;
		}  cout<<endl;
		cout<<"      \t"<<"Number of words: "<<cw+1<<"\t"<<"Number of vowels: "<<cv<<endl;
		cout<<"-----------------------------------------------------------"<<endl;
	}
	f1.close();

	getch();
}


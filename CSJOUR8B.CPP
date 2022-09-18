#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>

void main()
{       clrscr();
	fstream f1, f2;

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 8 - Manipulating a text file"<<endl<<endl;

	f2.open("C:\\Jdata\\CSJOURQ8.txt", ios::out);
	f2<<"XII Computer Science Journal(2019-2020)"<<endl;
	f2<<"Jasmin Chaughule Roll No. 2"<<endl;
	f2<<"Assignment 8 - Manipulating a text file"<<endl<<endl;

	f1.open("C:\\Jdata\\Lines.txt", ios::out);
	char content[15000];
	int lines,i;

	cout<<"Enter number of lines: ";
	cin>>lines;
	f2<<"Enter number of lines: "<<lines<<endl;

	for(i=1;i<=lines;i++)
	{	//cout<<"Line "<<i<<endl;
		cout<<"Enter line "<<i<<" : ";
		gets(content);
		f1<<content<<endl;
		f2<<"Enter line "<<i<<" : "<<content<<endl;
	}
	f1.close();

	cout<<endl<<"--------------------- Reading from file -------------------"<<endl;
	f2<<endl<<"--------------------- Reading from file -------------------"<<endl;

	f1.open("C:\\Jdata\\Lines.txt", ios::in);
	f1.seekg(0);
	for(i=1;i<=lines;i++)
	{       int cw=0,cv=0;
		f1.getline(content,200,'\n');
		cout<<"Line "<<i<<"\t";
		cout<<content<<endl;
		cout<<"      \t";

		f2<<"Line "<<i<<"\t";
		f2<<content<<endl;
		f2<<"      \t";

		for(int j=strlen(content)-1;j>=0;j--)
		{	cout<<content[j];
			f2<<content[j];
			if(content[j]==' ')
				cw++;
			if(content[j]=='a'||content[j]=='e'||content[j]=='i'||content[j]=='o'||content[j]=='u'||content[j]=='A'||content[j]=='E'||content[j]=='I'||content[j]=='O'||content[j]=='U')
				cv++;
		}  
		cout<<endl;
		cout<<"      \t"<<"Number of words: "<<cw+1<<"\t"<<"Number of vowels: "<<cv<<endl;
		cout<<"-----------------------------------------------------------"<<endl;

		f2<<endl;
		f2<<"      \t"<<"Number of words: "<<cw+1<<"\t"<<"Number of vowels: "<<cv<<endl;
		f2<<"-----------------------------------------------------------"<<endl;

	}
	f1.close();
	f2.close();

	getch();
}


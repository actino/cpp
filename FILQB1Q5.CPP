#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>

void main()
{       int count=0;
	char content[80];
	clrscr();   void linecount();
	fstream filin;
	filin.open("C:\\Jdata\\LINES.txt",ios::out);
	cout<<"Enter file content: ";
	gets(content);
	filin<<content;
	filin.close();
	linecount();
	getch();
}

void linecount()
{       fstream filin; int count=0; char content[80];
	filin.open("C:\\Jdata\\LINES.txt",ios::in);
	while(!filin.eof())
	{     	filin.getline(content,500,'.') ;
		puts(content);
		if(content[0]=='A'||content[0]=='a')
		count++;
	}
	filin.close();
	cout<<"Number of lines beginning with 'A' are: "<<count;
}

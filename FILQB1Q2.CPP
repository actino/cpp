#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>

void main()
{       int count=0;
	char content[80];
	clrscr();
	fstream filin;
	filin.open("C:\\Jdata\\DIALOUGE.txt",ios::out);
	cout<<"Enter file content: ";
	gets(content);
	filin<<content;
	filin.close();

	filin.open("C:\\Jdata\\DIALOUGE .txt",ios::in);
	while(!filin.eof())
	{	filin.getline(content,3,' ') ;
		puts(content);
		if(content[0]=='i'&&content[1]=='s')
		count++;
	}
	filin.close();
	cout<<"Number of times is occurs is: "<<count;
	getch();
}
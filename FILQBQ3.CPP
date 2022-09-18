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
	filin.open("C:\\Jdata\\PARA.txt",ios::out);
	cout<<"Enter file content: ";
	gets(content);
	filin<<content;
	filin.close();

	filin.open("C:\\Jdata\\PARA.txt",ios::in);
	while(!filin.eof())
	{     //	filin.getline(content,500,' ') ;
	       //	puts(content);
	       //	if((strcmpi(content," ")==0))
		char ch;
		filin.get(ch);
		if(ch==' ')
		count++;
	}
	filin.close();
	cout<<"Number of words is: "<<count+1;
	getch();
}
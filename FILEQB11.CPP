#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<ctype.h>
#include<stdio.h>

void main()
{	int count=0;
	char content[80];
	clrscr();

	fstream filin;
	filin.open("C:\\Jdata\\article.txt",ios::out);
	cout<<"Enter file content: ";
	gets(content);
	filin<<content;
	filin.close();

	char ch;
	filin.open("C:\\Jdata\\article.txt",ios::in);
	while(!filin.eof())
	{	filin.get(ch);
		if(isupper(ch))
		count++;
	}
	filin.close();
	cout<<"No of uppercase alphabets in the file are: "<<count;
	getch();
}


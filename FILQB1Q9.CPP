#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<ctype.h>
#include<stdio.h>

void main()
{	char content[80];
	clrscr();
	void puretext();

	fstream filin;
	filin.open("C:\\Jdata\\MYNOTES.txt",ios::out);
	cout<<"Enter file content: ";
	gets(content);
	filin<<content;
	filin.close();

	puretext();
	getch();
}

	void puretext()
       {	fstream filin;  char content[80];
		char ch;
		filin.open("C:\\Jdata\\MYNOTES.txt",ios::in|ios::out);
		while(!filin.eof())
		{	filin.get(ch);
			if(ch=='k')
			{	filin.seekg(filin.tellp()-1);
				filin.put('c');
			}

		}
		filin.close();

		filin.open("C:\\Jdata\\MYNOTES.txt",ios::in);
		while(!filin.eof())
	       {	filin.getline(content,80,'.');
			puts(content);
	       }
		filin.close();
       }

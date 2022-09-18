#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

void main()
{       clrscr();
	ofstream filout;
	char content[80];
	void word4char();
	cout<<"Write....";
	gets(content);

	filout.open("C:\\Jdata\\Fop.txt",ios::out);
	filout<<content;

	filout.close();

	word4char();

	getch();
}


void word4char()
{	ifstream filin;
	filin.open("C:\\Jdata\\Fop.txt",ios::in);

	int count;
	char content[80];

	while(!filin.eof())
	{	filin.getline(content,80,' ');
		for(int i=0;i<strlen(content);i++)
		{	if(isalpha(content[i]))
			count++;
		}
		if(count==4)
		{ for(int j=0;j<4;j++)
			cout<<content[i];
			cout<<" ";
		}
	}
	filin.close();
}

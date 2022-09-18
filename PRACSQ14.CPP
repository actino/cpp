#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
#include<ctype.h>

void main()
{       clrscr();
	char content[100];
	int count;
	fstream filin;
	filin.open("C:\\Jdata\\GG.txt", ios::binary|ios::out);

	cout<<"Content: ";
	gets(content);
	filin<<content;
	filin.close();

	filin.open("C:\\Jdata\\GG.txt", ios::binary|ios::in);
	while(!filin.eof())
	{ filin.getline(content,100,' ');
		if(isalpha(content[0]))
		{
			if((content[0]!='A')&&(content[0]!='E')&&(content[0]!='I')&&(content[0]!='O')&&(content[0]!='U'))
			{	cout<<content<<"\t";
				count++;
			}
		}    cout<<endl<<count;

	}  filin.close();
	 getch();

}

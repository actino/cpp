#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class subject
{
	long int code;
	char name[20];
	public:
	void enter()
	{       cout<<"Name: ";
		gets(name);
		cout<<"Code:  ";
		cin>>code;
       }


	void display()
	{       cout<<name<<"\t"<<code;
	}

	int getcode()
	{
		return code;
	}


 };
void main()
{	clrscr();
	subject sub[5];

	fstream filin;
	filin.open("C:\\Jdata\\subject.dat", ios::binary|ios::out);

	for(int i=0;i<10;i++)
	{       cout<<i+1<<"."<<endl;
		sub[i].enter();
		filin.write((char*)&sub[i],sizeof(sub[i]));
	}
	filin.seekg(0);
	filin.close();
      //	filin.close();
	getch();
}



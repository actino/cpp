#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>

class directory
{	char name[20];
	char areacode[5];
	public:
	void Register()
	{	cout<<"Name: ";
		gets(name);
		cout<<"Area code: ";
		gets(areacode);
	}
	void show()
	{	cout<<"Name: "<<name<<"\t"<<"Area code: "<<areacode<<"\n";
	}
	int checkcode(char ac[])
	{ return strcmpi(areacode,ac);
	}
};


void main()
{       clrscr();
	directory d[10];
	directory d1;
	void copyabc();
	ofstream filin;
	ifstream filout;
	filin.open("C:\\Jdata\\telephone.dat", ios::binary|ios::out);
	for(int i=0;i<3;i++)
	{	d[i].Register();
		filin.write((char*)&d[i],sizeof(d[i]));
	}
	filin.close();
	copyabc();
	filout.open("C:\\Jdata\\teleback.dat", ios::binary|ios::in);

	while(1)
	{   	filout.read((char*)&d1,sizeof(d1));
		if(filout.eof()) break;
		d1.show();
	}
	filout.close();
	getch();
}

void copyabc()
{	ifstream filin;
	ofstream filout;
	filin.open("C:\\Jdata\\telephone.dat", ios::binary|ios::in);
	filout.open("C:\\Jdata\\teleback.dat", ios::binary|ios::out);

	directory d;
	int comp;
	char ac[]="ABC";
	while(1)
	{	filin.read((char*)&d,sizeof(d));
		if(filin.eof()) break;
		comp=d.checkcode(ac);
		if(comp==0)
		filout.write((char*)&d,sizeof(d));
	}
	filin.close();
	filout.close();
}
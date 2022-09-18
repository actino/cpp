#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>

class cameras
{	long int modelno;
	char brand[90];
	//int  megapixel;

	public:
	void enter()
	{       cout<<"Model No:  ";
		cin>>modelno;
		cout<<"Brand: ";
		gets(brand);
	}
	void display()
	{       cout<<"Model no: "<<modelno<<"\t";
		cout<<"Brand: "<<brand<<"\n";
	}

	int getmodelno()
	{	return modelno;
	}
};

void main()
{ 	clrscr();
	void write();
	void insert();
	write();
	insert();
	getch();
}


void write()
{       int i;
	ofstream filin;
	filin.open("C:\\Jdata\\CAMERA.dat",ios::binary|ios::out);

	 cameras lens[10];
	 for(i=0;i<3;i++)
	 {      cout<<i+1<<".";
		lens[i].enter();
		filin.write((char*)&lens[i],sizeof(lens[i]));
	 }  filin.close();
}

void insert()
{       long int mno;     char found='n'; cameras lens, l;
	cout<<"Enter details of model whoose record you wish to add: ";
	l.enter();
	ifstream filin;
	filin.open("C:\\Jdata\\CAMERA.dat",ios::binary|ios::in);
	fstream filout;
	filout.open("C:\\Jdata\\temp.dat",ios::binary|ios::out);
	while(1)
	{       filin.read((char*)&lens,sizeof(lens));
		if(filin.eof()) break;
		if(l.getmodelno()<lens.getmodelno())
		   {  if(found=='n')
		      {	//lens.enter();
			filout.write((char*)&l,sizeof(l));
			found='y';     cout<<"Data saved"<<endl;
		      } //else  filout.write((char*)&lens,sizeof(lens));
		   }
	     //	else
		     filout.write((char*)&lens,sizeof(lens));
	}

	if(found=='n')
	filout.write((char*)&l,sizeof(l));

	filin.close();
	filout.close();
	remove("C:\\Jdata\\CAMERA.dat");
	rename("C:\\Jdata\\temp.dat","C:\\Jdata\\CAMERA.dat");

	filin.open("C:\\Jdata\\CAMERA.dat",ios::binary|ios::in);

	cout<<"Updated file: "<<"\n";
	while(1)
	{	filin.read((char*)&lens,sizeof(lens));
		if(filin.eof()) break;
		lens.display();
	}
	filin.close();

}




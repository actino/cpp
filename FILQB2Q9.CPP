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
	{       cout<<"Model NO:  ";
		cin>>modelno;
		cout<<"Brand: ";
		gets(brand);
	}
	void display()
	{       cout<<"MOdel no: "<<modelno<<"\t";
		cout<<"Brand: "<<brand<<"\n";
	}

	int getmodelno()
	{	return modelno;
	}
};

void main()
{ 	clrscr();
	void write();
	void remove();
	write();
	remove();
	getch();
}


void write()
{       int i;
	ofstream filin;
	filin.open("C:\\Jdata\\CAMERA.dat",ios::binary|ios::out);

	 cameras lens[10];
	 for(i=0;i<5;i++)
	 {      cout<<i+1<<".";
		lens[i].enter();
		filin.write((char*)&lens[i],sizeof(lens[i]));
	 }  filin.close();
}

void remove()
{       long int mno;     char found='n';
	cout<<"Enter model no whoose record you wish to delete: ";
	cin>>mno;
	cameras lens;
	ifstream filin;
	filin.open("C:\\Jdata\\CAMERA.dat",ios::binary|ios::in);
	fstream filout;
	filout.open("C:\\Jdata\\temp.dat",ios::binary|ios::out);
	while(1)
	{       filin.read((char*)&lens,sizeof(lens));
		if(filin.eof()) break;
		if(mno==lens.getmodelno())
		   {	found='y';
		   }
		else
		filout.write((char*)&lens,sizeof(lens));
	}

	if(found=='n')
	cout<<"Record not found"<<"\n";
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




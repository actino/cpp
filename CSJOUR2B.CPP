#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<fstream.h>

class complex
{	int real,img;

	public:
	//to read numbers
	void read()
	{
		fstream fx;

		cout<<"Enter real part of complex number: ";
		cin>>real;
		cout<<"Enter imaginary part of complex number: ";
		cin>>img;
		fx.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
		fx<<"Enter real part of complex number: "<<real<<endl;
		fx<<"Enter imaginary part of complex number: "<<img<<endl;
		fx.close();
	}
	//[1]
	complex add(complex complex1,complex complex2)
	{       complex temp;
		temp.real=complex1.real+complex2.real;
		temp.img=complex1.img+complex2.img;
		return temp;
	}
	//[2]
	complex subtract(complex complex1,complex complex2)
	{       complex temp;
		temp.real=complex1.real-complex2.real;
		temp.img=complex1.img-complex2.img;
		return temp;
	}
	//[3]
	complex multiply(complex complex1,complex complex2)
	{       complex temp;
		temp.real=(complex1.real*complex2.real)-(complex1.img*complex2.img);
		temp.img=(complex1.real*complex2.img)+(complex1.img*complex2.real);
		return temp;
	}
	//[4]
	complex divide(complex complex1,complex complex2)
	{	complex temp;
		int denominator; //to calculate the denominator
		denominator = (complex2.real*complex2.real)+(complex2.img*complex2.img);
		temp.real=((complex1.real*complex2.real)+(complex1.img*complex2.img))/denominator;
		temp.img=((complex2.real*complex1.img)-(complex2.img*complex1.real))/denominator;
		return temp;
	}
	//[5]
	complex conjugate(complex complex1)
	{	complex temp;
		temp.real=complex1.real;
		temp.img=(complex1.img)*(-1);
		return temp;
	}
	//[6]
	void display(complex proxy)
	{
		fstream fy;

		fy.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
		if(proxy.img>0) {
		cout<<"Answer is: "<<proxy.real<<" +"<<proxy.img<<" i";
		fy<<"Answer is: "<<proxy.real<<" +"<<proxy.img<<" i";
		}
		else if(proxy.img==0) {
		cout<<"Answer is: "<<proxy.real;
		fy<<"Answer is: "<<proxy.real;
		}
		else {
		cout<<"Answer is: "<<proxy.real<<" "<<proxy.img<<"i";
		fy<<"Answer is: "<<proxy.real<<" "<<proxy.img<<"i";
		}
		fy.close();
	}
};

void main()
{	clrscr();
	int choice;
	char ans='y';
	fstream f1;

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 2 - Operations on complex numbers"<<endl<<endl;

	f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::out);
	f1<<"XII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 2 - Operations on complex numbers"<<endl<<endl;
	f1.close();

	while(ans=='y'||ans=='Y')
	{	cout<<endl;
		cout<<"MAIN MENU"<<endl;
		cout<<"1.Add"<<"\t\t"<<"2.Subtract"<<"\t"<<"3.Multiply"<<endl<<"4.Divide"<<"\t"<<"5.Conjugate"<<"\t"<<"6.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
		f1<<endl<<"MAIN MENU"<<endl;
		f1<<"1.Add"<<"\t\t"<<"2.Subtract"<<"\t"<<"3.Multiply"<<endl<<"4.Divide"<<"\t"<<"5.Conjugate"<<"\t"<<"6.Exit"<<endl;
		f1<<"Enter choice: "<<choice<<endl;
		f1.close();

		switch(choice)
		{     	case 1: complex c1,c2,c3;
				cout<<"Enter First Complex Number"<<endl;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"Enter First Complex Number"<<endl;
				f1.close();
				c1.read();
				cout<<"Enter Second Complex Number"<<endl;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"Enter Second Complex Number"<<endl;
				f1.close();
				c2.read();
				c3=c3.add(c1,c2);
				c3.display(c3);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"\n"<<"Would you like to continue?(y/n)"<<ans<<endl;
				f1.close();
				break;
			case 2: complex c4,c5,c6;
				cout<<"Enter First Complex Number"<<endl;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"Enter First Complex Number"<<endl;
				f1.close();
				c4.read();
				cout<<"Enter Second Complex Number"<<endl;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"Enter Second Complex Number"<<endl;
				f1.close();
				c5.read();
				c6=c6.subtract(c4,c5);
				c6.display(c6);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"\n"<<"Would you like to continue?(y/n)"<<ans<<endl;
				f1.close();
				break;
			case 3: complex c7,c8,c9;
				cout<<"Enter First Complex Number"<<endl;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"Enter First Complex Number"<<endl;
				f1.close();
				c7.read();
				cout<<"Enter Second Complex Number"<<endl;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"Enter Second Complex Number"<<endl;
				f1.close();
				c8.read();
				c9=c9.multiply(c7,c8);
				c9.display(c9);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"\n"<<"Would you like to continue?(y/n)"<<ans<<endl;
				f1.close();
				break;
			case 4: complex c10,c11,c12;
				cout<<"Enter First Complex Number"<<endl;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"Enter First Complex Number"<<endl;
				f1.close();
				c10.read();
				cout<<"Enter Second Complex Number"<<endl;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"Enter Second Complex Number"<<endl;
				f1.close();
				c11.read();
				c12=c12.divide(c10,c11);
				c12.display(c12);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"\n"<<"Would you like to continue?(y/n)"<<ans<<endl;
				f1.close();
				break;
			case 5: complex c13,c14;
				cout<<"Enter Complex Number"<<endl;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"Enter Complex Number"<<endl;
				f1.close();
				c13.read();
				c14=c14.conjugate(c13);
				c14.display(c14);
				cout<<"\n"<<"Would you like to continue?(y/n)";
				cin>>ans;
				f1.open("C:\\Jdata\\CSJOURQ2.txt", ios::app);
				f1<<"\n"<<"Would you like to continue?(y/n)"<<ans<<endl;
				f1.close();
				break;
			default: exit(0);
				 break;
		}
	}

      //	getch();
}




#include<math.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#define PI 3.141

/* Area of triangle */
float area(int base, int height)
{
	return(base*height/2);
}

/* Area of square */
float area(double side)
{
	return side*side;
}

/* Area of circle */
float area(const float radius)
{
	return (PI*radius*radius);
}

void main()
{
	int b,h;
	double s;
	float r;
	int chr;
	fstream f1;

	clrscr();
/*	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 4 - Function Overloading"<<endl<<endl;
*/

	f1.open("C:\\Jdata\\CSJOURQ4.txt", ios::out);	

	do
	{
		cout<<"\n\n *****Menu***** \n";
		cout<<"\n 1. Area of triangle";
		cout<<"\n 2. Area of square";
		cout<<"\n 3. Area of circle";
		cout<<"\n 4. Exit";
		cout<<"\n\n Enter Your Choice : ";
		cin>>chr;

		f1<<"\n\n *****Menu***** \n";
		f1<<"\n 1. Area of triangle";
		f1<<"\n 2. Area of square";
		f1<<"\n 3. Area of circle";
		f1<<"\n 4. Exit";
		f1<<"\n\n Enter Your Choice : "<<chr;

		switch(chr)
		{
			case 1:
			{
				cout<<"\n Enter the Base & Height of Triangle = ";
				cin>>b>>h;
				f1<<"\n Enter the Base & Height of Triangle = "<<b<<"   "<<h;
				cout<<"\n Area of Triangle : "<<area(b,h);
				f1<<"\n Area of Triangle : "<<area(b,h);
				break;
			}
			case 2:
			{
				cout<<"\n Enter the side of a square : ";
				cin>>s;
				f1<<"\n Enter the side of a square : "<<s;
				cout<<"\n Area of Square : "<<area(s);
				f1<<"\n Area of Square : "<<area(s);
				break;
			}
			case 3:
			{
				cout<<"\n Enter the radius of Circle : ";
				cin>>r;
				f1<<"\n Enter the radius of Circle : "<<r;
				cout<<"\n Area of Circle : "<<area(r);
				f1<<"\n Area of Circle : "<<area(r);
				break;
			}
			case 4:
				f1.close();
				exit(0);
			default:
				cout<<"\n Invalid Choice...";
				f1<<"\n Invalid Choice...";
		}
	} while(chr!=4);

	
}
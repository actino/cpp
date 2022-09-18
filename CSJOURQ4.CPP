#include<math.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
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

	clrscr();
/*	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 4 - Function Overloading"<<endl<<endl;
*/
	do
	{
		cout<<"\n\n *****Menu***** \n";
		cout<<"\n 1. Area of triangle";
		cout<<"\n 2. Area of square";
		cout<<"\n 3. Area of circle";
		cout<<"\n 4. Exit";
		cout<<"\n\n Enter Your Choice : ";
		cin>>chr;

		switch(chr)
		{
			case 1:
			{
				cout<<"\n Enter the Base & Height of Triangle = ";
				cin>>b>>h;
				cout<<"\n Area of Triangle : "<<area(b,h);
				break;
			}
			case 2:
			{
				cout<<"\n Enter the side of a square : ";
				cin>>s;
				cout<<"\n Area of Square : "<<area(s);
				break;
			}
			case 3:
			{
				cout<<"\n Enter the radius of Circle : ";
				cin>>r;
				cout<<"\n Area of Circle : "<<area(r);
				break;
			}
			case 4:
				exit(0);
			default:
				cout<<"\n Invalid Choice...";
		}
	} while(chr!=4);
}
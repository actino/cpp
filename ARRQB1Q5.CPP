#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int M[100];
int i,pos=0,neg=0,zero=0,n;

cout<<"Please define a limit: ";
cin>>n;

	cout<<"Enter elements of array: ";
	for(i=0;i<n;i++)
	{
	  cin>>M[i];
	}
	for(i=0;i<n;i++)
	{
	  if(M[i]>0)
		pos++;
	  else if(M[i]<0)
		neg++;
	  else if(M[i]==0)
		zero++;
	}



cout<<"\n"<<"Number of positive numbers: "<<pos;
cout<<"\n"<<"Number of negative numbers: "<<neg;
cout<<"\n"<<"Number of zeros: "<<zero;
getch();
}

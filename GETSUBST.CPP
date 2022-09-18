#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void main()
{ clrscr();
char mainstr[80],substr[80]={""};
int i,j,l,pos,sl,e;

	cout<<"Enter string: ";
	gets(mainstr);
	l=strlen(mainstr);

	cout<<"Enter the position of string: ";
	cin>>pos;
	cout<<"Enter length of string: ";
	cin>>sl;

	e=(pos+sl)-1;

		if(pos>l||(pos+sl)-1>l)
			cout<<"Insuficient length of string: ";
		else
		     {	for(i=0,j=0;i<l,j<l;i++,j++)
			{       if(i>=pos-1&&i<e)
				 substr[j]=mainstr[i];   }

			cout<<"\n"<<"REQUIRED SUBSTRING: ";
			for(j=0;j<e;j++) cout<<substr[j];
		     } getch();}












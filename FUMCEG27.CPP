#include<iostream.h>
#include,conio.h>
#include<ctype.h>
#include<string.h>

void main()
{	clrscr();
	void convert(char a[25], int n)
	char b[25];
	int l;
	cout<<"Enter string: ";
	gets(b);
	l=strlen(b);
	convert(b[25],l);
	getch():
}

void convert(char a[25], int n)
{
	for(i=0;i<n;i++)
	{ 	if(islower(a[i]))
		{ char temp;
		  temp = toupper(a[i]);
		  a[i]=temp;}
		else
		a[i]=a[i];
	  cout<<a[i];
	}
}
}
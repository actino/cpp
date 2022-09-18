#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void main()
{
clrscr();
char a[22]={""},b[25]={""},c[50]={""};
int i,l1,l2;

	cout<<"Enter string 1. "<<endl;
	gets(a);
	cout<<endl<<"Enter string 2. "<<endl;
	gets(b);

	l1=strlen(a);
	l2=strlen(b);
    //	puts(a); cout<<" "; puts(b);

	for(i=0;i<l1;i++)
	c[i]=a[i];

     //	cout<<a[i];cout<<" ";
	for(i=0;i<l2;i++)   c[i+l1]=b[i];

      //	cout<<b[i];
      cout<<endl; puts(c);
	getch();
}



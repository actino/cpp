#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

void main()
{	clrscr();

	void concat(char a[80],char b[80]);//char c[160],int n,int m);
	char str1[80], str2[80];//str3[160];
	int l1,l2;

	cout<<"Enter string 1: ";
	gets(str1);
	cout<<"Enter string 2: ";
	gets(str2);

       //	l1=strlen(str1);
       //	l2=strlen(str2);

	concat(str1,str2);//str3,l1,l2);
	getch();
}

void concat(char a[80],char b[80])//char c[160],int n,int m)
{//int i,j;
       /*	for(i=0,j=0;i<n,j<n;i++,j++)
	{ c[j]=a[i];
	  cout<<c[j];}

	for(i=0,j=0;i<m,j<m;i++,j++)
	{ c[j]=b[i];
	  cout<<c[j];}            */

       strcat(a,b);
       puts(a);
}




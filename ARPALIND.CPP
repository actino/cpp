#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

void main()
{
clrscr();

char a[100]={""},b[100]={""};
int i,l,j;

cout<<"Enter a string: ";
gets(a);
l=strlen(a);

for(i=0;i<l;i++)
cout<<a[i];
cout<<"\n"<<l<<"\n";

	for(i=0,j=l-1;i<l;i++,j--)
	  b[j]=a[i];
	  for(j=0;j<l;j++)
		     cout<<b[j];
	  cout<<"\t";


       if(strcmp(a,b)==0) //c++
	// if(c=0)
	 {
       cout<<"String is a palindrome." ;
	 /*for(j=0;j<l+2;j++)
		     cout<<b[j];*/
		     }

       else  {
       cout<<"String is not a palindrome.";
		    /* for(j=0;j<l+2;j++)
		     cout<<b[j];*/
		     }

       getch();
}

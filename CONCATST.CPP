#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

void main()
{clrscr();
char str1[80], str2[80], str3[160];
int i,j,l1,l2;

cout<<"Enter string 1: ";
gets(str1);
cout<<"Enter string 2: ";
gets(str2);

l1=strlen(str1);
l2=strlen(str2);

for(i=0;i<l1;i++)
str3[i]=str1[i];

for(j=0;j<l2;j++)
str3[l1+j]=str2[j];

puts(str3);
getch();
}



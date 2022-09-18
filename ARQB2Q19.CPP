#include<iostream.h>
#include<conio.h>
#include<string.h>
//#include<stdio.h>

void main()
{ clrscr();
  char a[8][21]={""} ;
  int i;

  cout<<"Enter name: ";
   for(i=0;i<2;i++)
  cin.getline(a[i],21);

  for(i=0;i<8;i++)
  cout<<"\n"<<a[i];
  getch();
}


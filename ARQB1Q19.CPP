#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int marks[10];
int i,e=0,f=0;

cout<<"Enter marks: ";
for(i=0;i<10;i++) {
cin>>marks[i];
	if(marks[i]>80)
	e++;
	else if(marks[i]<40)
	f++;
}

cout<<"\n"<<e<<"\n"<<f;
getch();
}



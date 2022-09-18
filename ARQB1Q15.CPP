#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a[10];
int i,e=0,o=0;

cout<<"Enter nos: ";
for(i=0;i<10;i++) {
cin>>a[i];
	if(a[i]%2==0)
	e++;
	else
	o++;   }

cout<<"\n"<<"EVEN= "<<e<<"\n"<<"ODD= "<<o ;
getch();
}

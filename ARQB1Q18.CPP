#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a[10];
int i;

cout<<"Enter nos: ";
for(i=0;i<10;i++) {
cin>>a[i]; }
int min=a[0];
	for(i=0;i<10;i++) {
	if(a[i]<min)
	min=a[i];   }

cout<<"\n"<<min;
getch();
}

#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a[3][3];
int i,j;

cout<<"Enter elements: ";
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
		cin>>a[i][j];
}
cout<<endl;
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
		cout<<a[i][j]<<"\t";
cout<<endl;
}
cout<<endl;
for(j=0;j<3;j++)
{
	for(i=0;i<3;i++)
		cout<<a[i][j]<<"\t";
cout<<endl;
}
getch();
}

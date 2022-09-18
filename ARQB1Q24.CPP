#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a[10]={2,3,4,5,6,7,9} ;
int b[10]={5,7,8,9,4,0,4};
int i,j;
int match=1;

for(i=0,j=0;i<10,j<10;i++,j++) {
    if( a[i]!=b[j]){
	match = 0;
	break;
    }
}
   if(match)
	cout<<"Arrays are equal!!!";
   else
	cout<<"Arrays are not equal :(";

getch();
}
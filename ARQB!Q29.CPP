#include<iostream.h>
#include<conio.h>

void swap(int a[], int n)
{
int temp=0,j;
for(j=0;j<n;j++)
	{ if(j+1!=n){
	temp=a[j];
	a[j]=a[j+1];
	a[j+1]=temp; }
	j++;
	}
for(j=0;j<n;j++)
cout<<a[j]<<"\t";
}

void main()
{
clrscr();
int a[100];
int i,n;

cout<<"Enter limit: ";
cin>>n;

cout<<"Enter elements of array: ";
for(i=0;i<n;i++)
{
cin>>a[i];
}

swap(a,n);
getch();
}



#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a[10];
int j,i,n,m;

cout<<"Enter no of elements: ";
cin>>n;
cout<<"Enter nos: ";

for(i=0;i<n;i++) {
cin>>a[i];     }
cout<<"Enter no to be deleted: ";
cin>>m;

	for(i=0;i<n;i++) {
		if(a[i]==m)
		{	for(j=i;j<n-1;j++)
				a[j]=a[j+1];
			a[j]=0;

			i--;
		}

	}

	for(i=0; i<n; i++) cout<<a[i]<<"\t";
getch();
}



 ff
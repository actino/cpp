#include<iostream.h>
#include<conio.h>

void main()
{
	int a[10];
	int j,i,n,m,p;

	clrscr();

	cout<<"Enter no of elements: ";
	cin>>n;

	cout<<"Enter nos: ";
	for(i=0;i<n;i++) {
		cin>>a[i];
	}

	cout<<"Enter no to be deleted: ";
	cin>>m;

	for(i=0;i<n;i++)
	{
		if(a[i]==m) {
			for(j=i;j<n;j++) a[j]=a[j+1];
			a[n-1]=0;
		       //	i=n;
			break;
		}


	}

	for(i=0; i<n; i++) cout<<a[i]<<"\t";

	getch();
}




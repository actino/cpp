#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	void chg(float a[100],int n,float x);
	float b[100],k;
	int i,l;

	cout<<"Enter length of array: ";
	cin>>l;

	cout<<"Enter array: " ;
	for(i=0;i<l;i++) cin>>b[i];

	cout<<"Enter the value of float you want to change the array to: ";
	cin>>k;

	chg(b,l,k);
	getch();
}

void chg(float a[100],int n, float x)
{
	int j;
	for(j=0;j<n;j++)
	{ a[j]=x;
	  cout<<a[j]<<"\t";
	}
}



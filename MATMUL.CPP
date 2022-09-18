#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a[10][10],b[10][10],c[10][10];
int m,n,p;
int i,j,k;

cout<<"Enter number of rows of matrix a [Max 10]: ";
cin>>m;
cout<<"Enter number of columnns of matrix a [Max 10]: ";
cin>>n;

cout<<"Number of rows of matrix b: "<<n<<"\n";
cout<<"Enter number of columnns of matrix b [Max 10]: ";
cin>>p;


cout<<"Enter elements of matrix a: "<<"\n";
for(i=0;i<m;i++)
{       cout<<"Row "<<i+1<<"="<<"\n";
	for(j=0;j<n;j++)
		cin>>a[i][j];
}
cout<<endl;
cout<<"Enter elements of matrix b: "<<"\n";
for(j=0;j<n;j++)
{       cout<<"Row "<<j+1<<"="<<"\n";
	for(k=0;k<p;k++)
		cin>>b[j][k];
}
cout<<endl;

for(i=0;i<m;i++)
{
	for(k=0;k<p;k++)
		{
			for(j=0;j<n;j++)
				{ c[i][k]+=a[i][j]*b[j][k];

				}
			cout<<c[i][k]<<"\t";

		}
	cout<<endl;
}
getch();
}

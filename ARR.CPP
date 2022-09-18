#include<iostream.h>
#include<conio.h>

void main()
{	clrscr();
	int r,c,i,j;
	int a[10][10];
	cout<<"Rows: ";
	cin>>r;
	cout<<"Columns: ";
	cin>>c;
	cout<<"Enter elements: ";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cin>>a[i][j];
	}
	int x,temp;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{     if(j==i||j(+1)=(r-1))
		     {	x+=a[j][i];  //cout<<"p";
			//a[j][i]=a[x][i]; // cout<<"q";
			//a[x][i]=temp;   //cout<<"r";
		     }
		 }    //cout<<"HOLA";
	} cout<<sum;

	/*for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}*/
	getch();
}
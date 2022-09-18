#include<iostream.h>
#include<conio.h>
#include<math.h>

void main()
{
	clrscr();
	float sum(float a,int b);
	int n;
	float x,sumseries=0.0;

	cout<<"Enter a no: ";
	cin>>x;
	cout<<"Enter no of terms: ";
	cin>>n;

	sumseries=sum(x,n);
	cout<<"SUM OF SERIES IS: "<<sumseries;

	getch();
}

float sum(float a,int b)
{
	int i,f=1,j;
	float p;
	float term,summ=0.0;

	for (i=1;i<=b;i++)
	{       f=1;
		for(j=1;j<=i;j++) f*=j;
		//cout<<endl<<"Factorial: "<<f;
		p=pow(a,i-1);
		//cout<<endl<<"Power: "<<p;
		term=p/f;
		//cout<<endl<<"Term: "<<term;
		summ+=term;
	}
	return summ;
}
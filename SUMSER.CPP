#include<iostream.h>
#include<conio.h>
#include<math.h>

void main()
{       clrscr();
	float sumseries(int x,int  n);
	float sum=0;
	int a,l;

	cout<<"Enter number";
	cin>>a;
	cout<<"Enter length: ";
	cin>>l;

	sum=sumseries(a,l);
	cout<<sum;
	getch();
}

float sumseries(int x,int n,int r)
{       float s=1;
	for(int i=2;i<=n;i++)
	{ float p=pow(x,i-1);
			int f=1;
			for(int j=1;j<=i;j++)
			f*=j;
	  float z=p/f;
	 s+=z;// cout<<s<<endl;
	}
	return s;
}










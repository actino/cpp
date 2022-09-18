#include<iostrea,.h>
#include<conio.h>

void main()
{	clrscr();
	int palindrome(int b[10],int t);
	int a[10];
	int n,c;

	cout<<"Enter no of nos: ";
	cin>>n;
	cout>>"ENTER Nos: ";
	for(i=0;i<n;i++)
	cin>>a[i];
	palindrome(a,n);
	getch();
}

int palindrome(int b[10], int t)
{ int j,p,s=0,r,a;
	for(j=0;j<t;j++)
	{	a=b[i];
		while(a>0)
		{  	r=a%10;
			a=a/10;
			s=(s*10)+r;
		}
		if(s==a)  p++;
		return p;
}








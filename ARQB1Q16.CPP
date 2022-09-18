#include<iostream.h>
#include<conio.h>

primeornot(int n)
{int j,f=0;
	for(j=2;j<n/2;j++)
	{       if(n%j==0)
		f++;
	}
return f;

}

void main()
{
clrscr();
int a[10];
int i,p,np=0;

cout<<"Enter nos: ";
for(i=0;i<10;i++) {
cin>>a[i]; }

for(i=0;i<10;i++)
{ 	p=primeornot(a[i]);
	if(p==0)
	np++;
}

cout<<"Number of primes in array are: "<<np;
getch();
}



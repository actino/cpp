#include<iostream.h>
#include<conio.h>

void main()
{ 	clrscr();
	int prime(int d[10]);
	int DATA[10];
	int count;
	int i;

	cout<<"Enter elements: ";
	for(i=0;i<10;i++) cin>>DATA[i];

	count=prime(DATA);
	cout<<"NO OF PRIMES ARE: "<<count;

	getch();
}

int prime(int d[10])
{	int i,j,c=0,p=0;
	for(i=0;i<10;i++)
	{       if(d[i]==2) c++;
		for(j=2;j<=d[i]/2;j++)
			if(d[i]%j==0)  p++;

	      //	if(p==0) c++;
	}
	return c;
}






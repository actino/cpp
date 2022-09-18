#include<iostream.h>
#include<conio.h>

int cfact(int num)
{
int j,c=0;
	cout<<"\n"<<"Factors of "<<num<<" are ";
	for(j=2;j<=num/2;j++){

		if(num%j==0) {
			cout<<j<<" , ";
			c++;
		}

	}

return c;

}


void main()
{
clrscr();
int a[10]={2,22,34,-1,-67,44,3,0,678,333};
int max=0,maxpos,min=0,minpos,i=0;
double pro=1;
int maxelement=0,maxfact=0;

max=a[i];
min=a[i];
maxpos=1;minpos=1;
  if(a[i]>0)
  {
	pro=pro*a[i];
  }
i++;
do
{ if(a[i]>max)
  {
	max=a[i];
	maxpos=i+1;
  }
  if(a[i]<min)
   {
	min=a[i];
	minpos=i+1;
  }
  if(a[i]>0)
  {
	pro*=a[i];
  }
i++;
} while(i<10);

cout<<"\n"<<"Maximum number is: "<<max<<"\n"<<"Position of maximum number: "<<maxpos;
cout<<"\n"<<"Miniimum number is: "<<min<<"\n"<<"Position of minimum number: "<<minpos;
cout<<"\n"<<"Product of all positive numbers: "<<pro;

int tmp=0;
for(i=0;i<10;i++)
{
 tmp=cfact(a[i]);
 if(tmp>maxfact)
{ maxfact=tmp;
 maxelement=a[i];}
}

cout<<"\n"<<"Element with maximum factors is: "<<maxelement;
cout<<"\n"<<"No of factors: "<<maxfact;
getch();
}

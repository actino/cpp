#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int ref(int n,int m);
	int l,y;
	float a;

	cout<<"Enter number: ";
	cin>>l>>y;

       a=ref(l,y);  cout<<a;
	getch();
}

int ref(int n, int m)
{       if(n%2!=0&&m%2==0)
	return*&n;
	if(n%2==0&&m%2!=0)
	return*&m;
	if(n%2!=0&&m%2!=0)
	{ if(n<m) return*&n;
	  else return*&m;
	}
       //	if(n%2==0&&m%2==0)

}

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
void main()
{
	clrscr();
	int rep(char *str,char ch1,char ch2);

	char a[100];
	char p,q;
	int cnt=0;

	cout<<"Enter string.";
	gets(a);
	cout<<"ENnter character to be replaced: ";
	cin>>p;
	cout<<"Enter the replacement: ";
	cin>>q;

      //	rep(a,p,q);      cout<<endl;
	cnt=rep(a,p,q);
	cout<<cnt;

	getch();
}

int rep (char *str,char ch1,char ch2)

{  int i,l,c=0;
	l=strlen(str);
	for(i=0;i<l;i++)
	{
	       if (str[i]==ch1) {
		str[i]=ch2;
		c++;  }
	}

	puts(str);
	return c;
}







#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void main()
{
	clrscr();
	int cmp(char str1[20], char str2[20]);
	void cpy(char ar1[20], char ar2[20]);
	char a[20],b[20];
	int y=0;

	cout<<"Enter strimg 1";
	gets(a);
	cout<<"Enter strimg 2";
	gets(b);

	y=cmp(a,b);
	cout<<y; cout<<endl;
	cpy(a,b);
	getch();
}

int cmp(char str1[20], char str2[20])
{
	int i,j,l1,l2;
	int flag=0;
	l1=strlen(str1);
	l2=strlen(str2);

	for(i=0;i<l1;i++)
	{ 	for(j=0;j<l2;j++)
			if(str1[i]!=str2[j]) {
			flag=-1;
			break; }

			else
			flag=0;
	}
	return flag;
}

void cpy(char ar1[20], char ar2[20])
{
	char ar3[40]={""};
	int i,j,l1,l2;
	l1=strlen(ar1);
	l2=strlen(ar2);

	for(i=0;i<l1;i++)
	{ ar3[i]=ar1[i];}

	for(i=0;i<l2;i++)
	{ ar3[i+l1]=ar2[i];}

	puts(ar3);

}



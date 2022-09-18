#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void main()
{        clrscr();
	 char a[10], b[10];
	 int l1,l2,n;

	 cout<<"Enter string 1: ";
	 gets(a);
	 cout<<"Enter string 2: ";
	 gets(b);

	 l1=strlen(a);
	 l2=strlen(b);

		if(l1>l2)
		{	strcpy(a,b);
			puts(a); 	}
		else if(l2>l1)
		{ 	strcpy(b,a);
			puts(b);	}
		else if (l1==l2)
		{	cout<<"Both strings are of equal lenght.";
			cout<<endl;
			cout<<"Which one do you wish to copy(1/2): ";
			cin>>n;
				if(n==1)
				{	strcpy(b,a);
					puts(b); 	}
				else
				{ 	strcpy(a,b);
					puts(a);	}
		}
	getch();
}

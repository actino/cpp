#include<iostream.h>
#include<ctype.h>
#include<conio.h>
//#include<stdio.h>
void main()
{	clrscr();

	void isalphax(char c);
	char ch;

	cout<<"Enter character: "<<endl;
	cin>>ch;

	isalphax(ch);
	getch();
}

void isalphax(char c)
{
	if(islower(c))
	       { cout<<"Lowercase.";
		char temp;
		temp = toupper(c);
		cout<<endl<<"Uppercase: "<<temp;}
	       //	cout<<endl<<toupper(c);
	       //	putchar(toupper(c));
		}
       else if(isupper(c))
	      {	cout<<"Uppercase.";
		char temp1;
		temp1 = tolower(c);
		cout<<endl<<"Lowercase: "<<temp1;}
       else
		cout<<"NOT AN ALPHABET!!!!!!!!";
}



#include<iostream.h>
#include<conio.h>
#include<ctype.h>


void main()
{ 	clrscr();
	char printall(char ch);
      //	char printlast(char ch1);
	char a,m;

	cout<<"Enter letter: ";
	cin>>a;
	cout<<endl;

       //	printall(a);
       //	m=printlast(a);
      // m=printall(a);
       if(isalpha(a))
       cout<<endl<<"Last letter is: "<<printall(a);
       else
       cout<<"You have not entered a letter.";

       getch();
}

char printall(char ch)
{      // if(isalpha(ch)){
		char nextchar;
		int i;

		cout<<ch<<"\t";
		for(i=1;i<=5;i++)
		{	nextchar= ch + i;
			cout<<nextchar<<"\t"; }
		return nextchar;
       /*	else
	cout<<"You have not entered a letter.";   */
}




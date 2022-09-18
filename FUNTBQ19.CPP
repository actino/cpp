#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int cmp(char p, char q);    void exp(int z);
	char ch1,ch2;
	int y;

	cout<<"Enter characters: ";
	cin>>ch1>>ch2;

	cout<<endl;
	y=cmp(ch1,ch2);
	cout<<y; cout<<endl;
	exp(y);

	getch();
}

int cmp(char p, char q)
{
	int flag=0;

	if(p==q)
     {  flag=0;     return flag; }
       //	cout<<"Both are equal.";}

	else if(p<q)
     {   flag=-1;   return flag; }
      //	cout<<"1st argument less than 2nd."; }

	else if(p>q)
      {	flag=1;     return flag; }
       //	cout<<"2nd argument less than ist."; }
}

void exp(int z){
	if(z==0)  cout<<"Both are equal.";
	if(z==-1) cout<<"1st argument less than 2nd.";
	if(z==1)  cout<<"2nd argument less than 1st.";
}
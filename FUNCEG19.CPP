#include<iostream.h>
#include<conio.h>
#include<process.h>
void main()
{clrscr();
void calc(int a,int b, char ch);
int  x,y,r;
char o,ch;
cout<<"Enter two nos: ";
cin>>x>>y;
cout<<"Enter operator: ";
cin>>o;  cout<<endl<<endl;
calc(x,y,o);
getch();
}

void calc(int a,int b,char ch){
//int ans;
//ans = achb;
//return ans;}
switch(ch) {
	case '+': cout<<a+b;
		break;
	case '-' :  if(a>b) cout<<a-b;
		    else  cout<<b-a;
		break;
	case '*' : cout<<a*b;
		break;
	case '/' : cout<<a/b;
		break;
	case'%' : cout<<a%b;
		break;
	default : cout<<"Wrong operator. ";
		break;}
}

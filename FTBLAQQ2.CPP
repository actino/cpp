#include<iostream.h>
#include<conio.h>
#include<math.h>

void main()
{
clrscr();
int satis(int a,int b,int c,int d);
int p,q,r,s;
int y=0;
cout<<"Enter nos: ";
cin>>p>>q>>r>>s;
y=satis(p,q,r,s);
cout<<y; getch();
}

int satis(int a,int b,int c,int d)
{ long int LHS=0,RHS;
   int flag=0;
  RHS=pow(d,3);
  LHS=pow(a,3)+pow(b,3)+pow(c,3);
  if(LHS==RHS)
  flag=0;
  else
  flag=-1;   cout<<LHS; cout<<endl; cout<<RHS; cout<<endl;
  return flag;     }




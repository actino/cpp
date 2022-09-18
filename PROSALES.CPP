#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int pns[3][3];
int p,s,p1=0,p2=0,p3=0,s1=0,s2=0,s3=0,sumall=0;

for(p=0;p<3;p++)
{  for(s=0;s<3;s++)
   {cout<<"Enter no pieces of product "<<p+1<<" sold by salesman "<<s+1<<"\n";
	  cin>>pns[p][s];
   }
}
cout<<endl;
for(p=0;p<3;p++)
{     for(s=0;s<3;s++)
      {cout<<pns[p][s]<<"\t";
      }
      cout<<endl;
}
	for(s=0;s<3;s++)
	{ p1+=pns[0][s];
	  p2+=pns[1][s];
	  p3+=pns[2][s];}

	for(p=0;p<3;p++)
	 {s1+=pns[p][0];
	  s2+=pns[p][1];
	  s3+=pns[p][2];}

for(p=0;p<3;p++)
{     for(s=0;s<3;s++)
      { sumall+=pns[p][s];
      }
}



cout<<"\n"<<"Number of sales of product 1 are: "<<p1;
cout<<"\n"<<"Number of sales of product 2 are: "<<p2;
cout<<"\n"<<"Number of sales of product 3 are: "<<p3;

cout<<"\n"<<"Number of sales done by salesman 1 are: "<<s1;
cout<<"\n"<<"Number of sales done by salesman 2 are: "<<s2;
cout<<"\n"<<"Number of sales done by salesman 3 are: "<<s3;

cout<<"\n"<<"Total sales = "<<sumall;

getch();
}
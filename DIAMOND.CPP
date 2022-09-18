#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int r,s,i,j;
cout<<"Please enter odd number of rows: ";
cin>>r;

/*loop for asterick of upper half of diamond*/
if(r%2!=0)
{
for(i=1;i<=(r/2)+1;i++)
       {
	 for (int k=0; k<=(r/2-i); k++) cout<<"  ";

	 for(j=1;j<=2*i-1;j++)
	 {
		 cout<<"$ ";
	 }
	 cout<<"\n";
	}

/*loop for astericks in lower half of diamonds */
		  int k=0;
for(i=1;i<=(r/2);i++)
    {

	 for (int k=0; k<=(r/2); k++){
	      if (k<i) cout<<"  ";
	 }


	 for(j=1;j<=r-(2*i);j++)
	 {
	   //	if (j<i) cout<<"  ";
		 cout<<"$ ";
	 }
	 cout<<"\n";

}
	cout<<"AWESOME!!!!!!!!!";
 }
 else {
	cout<<"Go back to school you idiot. You dont know whats an odd number.";
 }
getch();
}



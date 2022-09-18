#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
//#include<process.h>
#include<ctype.h>

void  main()
{
	clrscr();
	char country[10][15]={"GERMANY","NEPAL","JAPAN","CANADA","IRAQ","SRI LANKA","BRAZIL","AUSTRALIA","INDIA","SOUTH AFRICA"};
	char capital[10][15]={"BERLIN","KATHMANDU","TOKYO","MONTREAL","BAGHDAD","COLOMBO","BRASILIA","PERTH","DELHI","PRETORIA"};
	int i,c=0,p;
	char cnt[20];
	char e[4]={"XXX"};

	do{ i=0;c=0;
	cout<<endl;
	cout<<"Enter 'XXX' to exit.";


	cout<<"Please enter country[Use block letters]: ";
//cin.get(cnt, 20);
//cout<<cnt;
	gets(cnt);

	if(strcmpi(cnt,e)!=0){

		for(i=0;i<10;i++) {
		//cout<<country[i]<<"\n";
			if(strcmpi(country[i],cnt)==0){
			c++;
			 //<<i/*<<c<" val of c"*/;
			p=i;
			}
		}

		if(c==0)
		cout<<"Country not found.Please try again."<<endl;
		else
		{	//for(i=0;i<10;i++)
			cout<<capital[p];
		}
	}
      //	else
	//	exit(0);
	}while(strcmpi(cnt,e)!=0);
   //	getch();
}
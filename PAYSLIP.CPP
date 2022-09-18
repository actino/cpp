#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
void main()
{
clrscr();
float basic,da,hra,total,yearly,tax,monthly_tax,final_salary;
int grade;
cout<<"Please enter basic salary: ";
cin>>basic;
	if(basic>=10000)
	grade=1;
	if(basic>=5000&&basic<10000)
	grade=2;
	if(basic>2000&&basic<5000)
	grade=3;
	if(basic<=2000)
	grade=4;

	switch(grade){
		case 1:
			da= 0.4*basic;
			hra=0.3*basic;
			total= basic + da + hra;
			yearly=total*12;
			if(yearly>50000)
				 tax=0.3*(yearly-50000);
			else
				tax=0;
			monthly_tax=tax/12;
			final_salary = total - monthly_tax;
			break;


		case 2:
			da= 0.3*basic;
			hra=0.25*basic;
			total= basic + da + hra;
			yearly=total*12;
			if(yearly>50000)
				 tax=0.3*(yearly-50000);
			else
				tax=0;
			monthly_tax=tax/12;
			final_salary = total - monthly_tax;
			break;


		case 3:
			da= 0.3*basic;
			hra=0.2*basic;
			total= basic + da + hra;
			yearly=total*12;
			if(yearly>50000)
				 tax=0.3*(yearly-50000);
			else
				tax=0;
			monthly_tax=tax/12;
			final_salary = total - monthly_tax;
			break;

		case 4:
			da= 0.3*basic;
			hra=0.15*basic;
			total= basic + da + hra;
			yearly=total*12;
			if(yearly>50000)
				 tax=0.3*(yearly-50000);
			else
				tax=0;
			monthly_tax=tax/12;
			final_salary = total - monthly_tax;
			break;
		}
cout.setf(ios::fixed);
cout<<"GRADE"<<"\t"<<setw(12)<<grade<<"\n";
cout<<"D.A"<<"\t"<<setw(12)<<setprecision(2)<<da<<"\n";
cout<<"H.R.A"<<"\t"<<setw(12)<<setprecision(2)<<hra<<"\n";
cout<<"TOTAL"<<"\t"<<setw(12)<<setprecision(2)<<total<<"\n";
cout<<"TAX"<<"\t"<<setw(12)<<setprecision(2)<<monthly_tax<<"\n";
cout<<"==========================="<<"\n";
cout<<"SALARY"<<"\t"<<setw(12)<<setprecision(2)<<final_salary;
getch();

}
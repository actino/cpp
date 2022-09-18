#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class speakers
{ private:
	char company[25];
	char model[25];
	int rating;
	float price;

  public:
	void read_data()
	{   // for(i=0;i<3;i++)
		//{
		  cout<<"Enter company name: "<<endl;
		  gets(company);

		  cout<<"Enter model name: "<<endl;
		  gets(model);

		  cout<<"Enter price "<<endl;
		  cin>>price;

		  cout<<"Enter rating"<<endl;
		  cin>>rating;
	      //	}
	}

	void disp_data()
	{    //for(i=0;i<3;i++0 )	{
		  cout<<"Copany: "<<company<<endl;
		  cout<<"Model: "<<model<<endl;
		  cout<<"Price: "<<price<<endl;
		  cout<<"Rating: "<<rating<<endl;
	       //	}
	}

	int rating_return()
	{    //for(i=0;i<3;i++){
		return rating;
	       //	}
	}

       /*	void check_and_disp
	 for(i=0;i<3;i++)
	{	proxy[i]=rating_return(rating[i];
		if(proxy[i]>=8)
		disp_data();
	}
	    */
    /*void copyy()
     {
	int copy[3];
	for(i=0;i<3;i++)
	{	copy[i]=rating[i];
	}
     }     */
};

void main()
{	clrscr();
	speakers ob1[10];
	//ob1.read_data(); // ob1.check_and_disp();
       //int proxy[3];
       for(int i=0;i<3;i++)
	{	ob1[i].read_data();
		cout<<endl;
	} cout<<endl;

	for (int j=0; j<3; j++) {
	    if (ob1[j].rating_return()>=8)
		ob1[j].disp_data(); cout<<endl;
	}
	 getch();
}
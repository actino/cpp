#include<iostream.h>
#include<conio.h>

void main()
{       clrscr();
	int i,j,n,temp;
	int arr[10];
	cout<<"Enter elements: ";
	for(i=0;i<5;i++)
	cin>>arr[i];

	for(i=0;i<5;i++)
	{       cout<<"Pass no: "<<i+1<<endl;
		for(j=i+1;j<5;j++)
		{	if(arr[i]>arr[j])
			{	temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}//cout<<arr[i]<<"\t"<<arr[j]<<"\t";
		}
		for(n=0;n<5;n++)
		cout<<arr[n]<<"\t";
		cout<<endl;
	}
	/*for(n=0;n<5;n++)
	cout<<arr[n]<<"\t";
	cout<<endl; */
	getch();
}
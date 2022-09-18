#include<iostream.h>
#include<conio.h>

void sort(int arr[],int n)
{   int i,j,k,temp;
    for(i=1;i<n;i++)
	{  j=i-1; temp=arr[i];
	   while((temp>arr[j])&&(j>=0))
	   {	arr[j+1]=arr[j];
		j=j-1;
	   }    arr[j+1]=temp;
	   cout<<"Pass no: "<<i<<endl;
	   for(k=0;k<n;k++)
	   cout<<arr[k];
	   cout<<endl;
	}
}

void main()
{       clrscr();
	int i,A[10];
	cout<<"Enter elements: ";
	for(i=0;i<5;i++)
	cin>>A[i];
	sort(A,5);
	getch();
}

#include<iostream.h>
#include<conio.h>


void bubblesort(int Arr[],int n)
{
	int i,j,temp;

	for(i=0;i<n;i++) {  cout<<"pass: "<<i+1<<endl;

		for(j=i+1;j<n;j++) {

			if(Arr[i]>Arr[j])	{

				temp=Arr[j];
				Arr[j]=Arr[i];
				Arr[i]=temp;

			}cout<<Arr[j]<<"\t";
		} cout<<endl;

	}

	cout<<"Sorted array: ";
	for(i=0;i<n;i++)
		cout<<Arr[i]<<" ";
}

void main()
{	clrscr();
	int i,n;
	int A[5];

	cout<<"enter elements: ";
	for(i=0;i<5;i++)
	cin>>A[i];

	bubblesort(A,5);
	getch();
}
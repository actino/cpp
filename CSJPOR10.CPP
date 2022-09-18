#include<iostream.h>
#include<conio.h>

void bubblesort(int Arr[],int p)
{	int i,j,temp;
	for(i=0;i<p-1;i++)
	{	for(j=0;j<p-i-1;j++)
		{	if(Arr[j]>Arr[j+1])
			{	temp=Arr[j];
				Arr[j]=Arr[j+1];
				Arr[j+1]=temp;
			}
		}
	}
	cout<<"Sorted array: ";
	for(i=0;i<p;i++)
	cout<<Arr[i]<<" ";
}

void binarysearch(int arr[],int n)
{      int search;

	bubblesort(arr,n);
	cout<<"\nEnter element to be searched: ";
	cin>>search;

	int first=0;
	int last=n-1;
	int middle=(first+last)/2;

	while(first<=last)
	{	if(search>arr[middle])
		first=middle+1;
		else if(search=arr[middle])
		{	cout<<"\nSearch found at posituon number  "<<middle+1;
			break;
		}
		else
		last=middle-1;
		middle=(first+last)/2;
	}

	if(first>last)
	cout<<"Not found.";
}


void main()
{       clrscr();
	int i,k;
	int A[100];

	cout<<"Enter no of elements: ";
	cin>>k;

	cout<<"\nEnter elements: ";
	for(i=0;i<k;i++)
	cin>>A[i];

	binarysearch(A,k);
	getch();
}

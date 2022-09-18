#include<iostream.h>
#include<conio.h>

void bubblesort(int Arr[],int n)
{	
	int i,j,temp;
	
	for(i=0;i<n;i++) {	
		
		for(j=0;j<n-i-1;j++) {	
			
			if(Arr[j]>Arr[j+1])	{	
				
				temp=Arr[j];
				Arr[j]=Arr[j+1];
				Arr[j+1]=temp;
			}
		}

	}

	cout<<"Sorted array: ";
	for(i=0;i<n;i++)
		cout<<Arr[i]<<" ";
}

void binarysearch(int arr[],int n)
{

	int search;

	cout<<"\n\nEnter element to be searched: ";
	cin>>search;

	int first=0;
	int last=n-1;
	int middle=(first+last)/2;

	while(first<=last) {

		if(search>arr[middle]) {
			first=middle+1;
		} else if(search==arr[middle]) {
			cout<<"\n"<<search<<" found at position number "<<middle+1;
			break;
		} else {
			last=middle-1;
		}

		middle=(first+last)/2;
	}

	if(first>last)
		cout<<"Number not found in the array.";
}


void main()
{
	clrscr();
	int i,k;
	int A[100];

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 10 - Bubble Sort and Binary Search of an Array"<<endl<<endl;
	
	cout<<"Enter no of elements: ";
	cin>>k;

	cout<<"\nEnter elements: ";
	for(i=0;i<k;i++)
		cin>>A[i];

	bubblesort(A,k);
	binarysearch(A,k);
	getch();
}

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>

void bubblesort(int Arr[],int n)
{
	int i,j,temp;
	fstream f1;

	for(i=0;i<n;i++) {

		for(j=0;j<n-i-1;j++) {

			if(Arr[j]>Arr[j+1])	{

				temp=Arr[j];
				Arr[j]=Arr[j+1];
				Arr[j+1]=temp;
			}
		}

	}

	f1.open("C:\\Jdata\\CSJOUQ10.txt", ios::app);

	cout<<"Sorted array: ";
	f1<<"Sorted array: ";
	for(i=0;i<n;i++) {
		cout<<Arr[i]<<" ";
		f1<<Arr[i]<<" ";
	}
	f1<<endl;
	f1.close();
}

void binarysearch(int arr[],int n)
{
	fstream f1;
	int search;

	cout<<"\n\nEnter element to be searched: ";
	cin>>search;
	f1.open("C:\\Jdata\\CSJOUQ10.txt", ios::app);
	f1<<"\n\nEnter element to be searched: "<<search<<endl;
	
	int first=0;
	int last=n-1;
	int middle=(first+last)/2;

	while(first<=last) {

		if(search>arr[middle]) {
			first=middle+1;
		} else if(search==arr[middle]) {
			cout<<"\n"<<search<<" found at position number "<<middle+1;
			f1<<"\n"<<search<<" found at position number "<<middle+1;
			break;
		} else {
			last=middle-1;
		}

		middle=(first+last)/2;
	}

	if(first>last) {
		cout<<"Number not found in the array.";
		f1<<"\nNumber not found in the array.";
	}

	f1<<endl;
	f1.close();
}


void main()
{
	clrscr();
	int i,k;
	int A[100];
	fstream f1;

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 10 - Bubble Sort and Binary Search of an Array"<<endl<<endl;
	
	f1.open("C:\\Jdata\\CSJOUQ10.txt", ios::app);
	f1<<"\n\nXII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 10 - Bubble Sort and Binary Search of an Array"<<endl<<endl;
	
	
	cout<<"Enter no of elements: ";
	cin>>k;
	f1<<"Enter no of elements: "<<k<<endl;

	cout<<"\nEnter elements: ";
	f1<<"\nEnter elements: ";
	for(i=0;i<k;i++) {
		cin>>A[i];
		f1<<A[i]<<" ";
	}
	f1<<endl;
	f1.close();

	bubblesort(A,k);
	binarysearch(A,k);
	getch();
}

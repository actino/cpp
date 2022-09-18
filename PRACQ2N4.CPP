#include<iostream.h>
#include<conio.h>

void sort(int arr[],int n)
{    int i,j,k,temp;
     for(i=0;i<n-1;i++)
     {	for(j=0;j<n-i-1;j++)
	{	if(arr[j]>arr[j+1])
		{	temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	} }
	cout<<"Pass no: "<<i+1<<endl;
	for(k=0;k<10;k++)
	cout<<arr[k]<<"\t";
	cout<<endl;

}

void search(int arr[],int n)
{       //sort(arr,10);
	int search, first,middle,last;
	first=0;
	last=n-1;
	middle=((first+last)/2);
	cout<<"Enter element to be searched: ";
	cin>>search;
	while(first<=last)
	{	if(search>arr[middle])
		first=middle+1;
		else if(search==arr[middle])
		{	cout<<"Found at: "<<middle+1;
			break;
		}
		else
		last=middle-1;
		middle=((first+last)/2);
	}
	if(first>last)
	cout<<"Not found.";
}

void main()
{       clrscr();
	int i,A[10];
	cout<<"Enter elements: ";
	for(i=0;i<10;i++)
	cin>>A[i];

	sort(A,10);
	search(A,10);
	getch();
}

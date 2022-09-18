#include<iostream.h>
#include<conio.h>

void ExchangeSort(int num[],int n);
void InsertionSort( int a[],int n);

void main()
{
	clrscr();
	int n, i;
	int ch;
	int arr[20];

	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 11 - Exchange Sort and Insertion Sort of an Array"<<endl<<endl;

	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;

	cout<<"Enter elements: ";
	for(i = 0; i < n; i++){
		cin>>arr[i];
	}

	cout<<"******Menu*******"<<endl;
	cout<<"1.Sort using Exchange sort technique"<<endl;
	cout<<"2.Sort using Insertion sort technique"<<endl;
	cout<<"Select Option: ";
	cin>>ch;

	switch(ch)
	{
		case 1:	ExchangeSort(arr,n);
			getch();
			break;
		case 2:	InsertionSort(arr,n);
			getch();
			break;
		default:
			cout<<"Invalid option!";
	}
}

void ExchangeSort(int num[],int n)
{
    int i, j;
    int temp;   // holding variable

    for (i=0; i<n-1; i++)    // element to be compared
    {
	 for(j = (i+1); j < n; j++)   // rest of the elements
	 {
	       if (num[j] < num[i])          // ascending order
	       {
			temp= num[j];          // swap
			num[j] = num[i];
			num[i] = temp;
	       }
	  }
     }

    // Display the sorted data.
	cout<<"\nSorted Data "<<endl;
	for (i = 0; i < n; i++)
		cout<<" "<<num[i];
}


void InsertionSort(int a[],int n)
{
	int i,j,temp;

	for(i=1;i<n;i++){

		temp=a[i];
		j=i-1;

		while((temp<a[j])&&(j>=0))
		{
			a[j+1]=a[j];    //moves element forward
			j=j-1;
		}

		a[j+1]=temp;    //insert element in proper place
    }

	cout<<"\nSorted Data "<<endl;

	for (i = 0; i < n; i++)
		cout<<" "<<a[i];
}
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>

int insert(int a[],int n);
int Delete(int a[],int n);
void ExchangeSort(int a[],int n);
int binarysearch(int arr[],int n, int s);
void display(int a[], int n);

void main()
{
	clrscr();
	int n, i, ch;
	int arr[10];
	fstream f1;
	
	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 12 - Insertion and Deletion in an Array"<<endl<<endl;
	f1.open("C:\\Jdata\\CSJOUQ12.txt", ios::app);
	f1<<"\n\nXII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 12 - Insertion and Deletion in an Array"<<endl<<endl;
	
	cout<<"\nEnter the number of elements of array: ";
	cin>>n;
	f1<<"\nEnter the number of elements of array: "<<n<<endl;
	
	cout<<"Enter elements: ";
	f1<<"Enter elements: ";

	for(i = 0; i < n; i++) {
		cin>>arr[i];
		f1<<arr[i]<<" ";
	}

	ExchangeSort(arr, n);
	cout<<"Sorted array=>"<<endl;
	f1<<"\nSorted array=>"<<endl;
	f1.close();
	display(arr, n);

	do {
		cout<<"\n******Menu*******"<<endl;
		cout<< "1.Insert\t2.Delete\t3.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>ch;
		
		f1.open("C:\\Jdata\\CSJOUQ12.txt", ios::app);
		f1<<"\n******Menu*******"<<endl;
		f1<< "1.Insert\t2.Delete\t3.Exit"<<endl;
		f1<<"Enter choice: "<<ch<<endl;
		f1.close();
		
		switch(ch) {
		case 1:
			n=insert(arr,n);
			getch();
			break;
		case 2:
			n=Delete(arr,n);
			getch();
			break;
		case 3:	exit(0);
			break;
		default:cout<<"\nInvalid choice:\n";
			break;
	}
    }while(ch!=3);

}

void display(int a[], int n)
{
	int i;
	fstream f1;
	f1.open("C:\\Jdata\\CSJOUQ12.txt", ios::app);
	
	for (i = 0; i < n; i++) {
			cout<<a[i]<<" ";
			f1<<a[i]<<" ";
	}
	cout<<endl;
	f1<<endl;
	
	f1.close();
		
}

int insert(int a[],int n)   //inserting an element in to an array
{
	fstream f1;
	

	if(n==10) {
	    cout<<"\nArray full. Cannot insert.\n";
		f1.open("C:\\Jdata\\CSJOUQ12.txt", ios::app);	
		f1<<"\nArray full. Cannot insert.\n";
		f1.close();
	} else {
	    int i,val,pos;

	    f1.open("C:\\Jdata\\CSJOUQ12.txt", ios::app);
		cout<<"\nEnter the element to be inserted: ";
	    cin>>val;
		f1<<"\nEnter the element to be inserted: "<<val<<endl;
	    a[n]=val;
	    n++;
	    ExchangeSort(a,n);

	// Display the new array.
	    cout<<"\nElement added successfully. New array =>"<<endl;
		f1<<"\nElement added successfully. New array =>"<<endl;
		f1.close();
		display(a, n);
	}
	
	return n;
}

int Delete(int a[],int n)      //deleting an array element
{
	fstream f1;
	
	if(n==0) {
	    f1.open("C:\\Jdata\\CSJOUQ12.txt", ios::app);
		cout<<"\nArray is empty.";
		f1<<"\nArray is empty.";
		f1.close();
	} else {
	    int i,pos,val;
		f1.open("C:\\Jdata\\CSJOUQ12.txt", ios::app);
	    cout<<"\nEnter the element to be deleted: ";
	    cin>>val;
		f1<<"\nEnter the element to be deleted: "<<val<<endl;
	    pos=binarysearch(a,n,val);

	    if (pos==99) {
			cout<<"\nThe Element not found in the array.\n";
			f1<<"\nThe Element not found in the array.\n";
	    } else {
		for(i=pos;i<n;i++)
			a[i]=a[i+1];

		n=n--;

		cout<<"\nThe element " <<val<<" deleted. New array=>"<<endl;
		f1<<"\nThe element " <<val<<" deleted. New array=>"<<endl;
		f1.close();
		display(a, n);
	    }
	}
	
	return n;
}//end of delete()


void ExchangeSort(int arr[],int c)
{
    int i, j;
    int temp;   // holding variable

    for (i=0; i<c-1; i++)    // element to be compared
    {
	 for(j = (i+1); j < c; j++)   // rest of the elements
	 {
	       if (arr[j] < arr[i])          // ascending order
	       {
			temp = arr[j];          // swap
			arr[j] = arr[i];
			arr[i] = temp;
	       }
	  }
     }
}

int binarysearch(int arr[],int n, int s)
{
	int pos;
	int first=0;
	int last=n-1;
	int middle=(first+last)/2;

	while(first<=last) {

		if(s > arr[middle]) {
			first=middle+1;
		} else if(s == arr[middle]) {
			pos=middle;
			break;
		} else {
			last=middle-1;
		}

		middle=(first+last)/2;
	}

	if(first>last)
		pos=99;	//Element not found

	return pos;
}
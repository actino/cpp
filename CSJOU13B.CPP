#include<iostream.h>
#include<conio.h>
#include<fstream.h>

void Merge(int A[], int B[], int C[], int M, int N);

void main()
{	
	int A[100], B[100], C[200],i,m,n;
	fstream f1;
	
	clrscr();
	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 13 - Merging two integer arrays"<<endl<<endl;
	f1.open("C:\\Jdata\\CSJOUQ13.txt", ios::app);
	f1<<"\n\nXII Computer Science Journal(2019-2020)"<<endl;
	f1<<"Jasmin Chaughule Roll No. 2"<<endl;
	f1<<"Assignment 13 - Merging two integer arrays"<<endl<<endl;
	
	cout<<"\nEnter number of elements you want to insert in first array = ";
	cin>>m;
	f1<<"\nEnter number of elements you want to insert in first array = "<<m<<endl;

	cout<<"Enter elements in descending order =>\n";
	f1<<"Enter elements in descending order =>\n";
	for(i=0;i<m;i++) {
		cin>>A[i];
		f1<<A[i]<<" ";
	}

	cout<<"\nEnter number of elements you want to insert in second array = ";
	cin>>n;
	f1<<endl<<"\nEnter number of elements you want to insert in second array = "<<n<<endl;

	cout<<"Enter element in descending order =>\n";
	f1<<"Enter elements in descending order =>\n";
	for(i=0;i<n;i++) {
		cin>>B[i];
		f1<<B[i]<<" ";
	}
	f1<<endl;

	Merge(A,B,C,m,n);
	
	cout<<"\nThe Merged Array in Ascending Order =>"<<endl;
	f1<<"\nThe Merged Array in Ascending Order =>"<<endl;
	for(i=0;i<(m+n);i++) {
		cout<<C[i]<<" ";
		f1<<C[i]<<" ";
	}

	f1<<endl;
	f1.close();
	getch();
}


void Merge(int A[], int B[], int C[], int M, int N)
{
	int ctrA = M-1, ctrB = N-1, ctrC = 0;

	while (ctrA >= 0 && ctrB >= 0) {
		if (A[ctrA] <= B[ctrB]) {
			C[ctrC] = A[ctrA];
			ctrC++;
			ctrA--;
		} else {
			C[ctrC] = B[ctrB];
			ctrC++;
			ctrB--;
		}
	}

	if (ctrA < 0) {
		while (ctrB >= 0) {
			C[ctrC] = B[ctrB];
			ctrC++;
			ctrB--;
		}
	}

	if (ctrB < 0) {
		while (ctrA >= 0) {
			C[ctrC] = A[ctrA];
			ctrC++;
			ctrA--;
		}
	}
}
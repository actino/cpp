#include<iostream.h>
#include<conio.h>

void Merge(int A[], int B[], int C[], int M, int N);

void main()
{	
	int A[100], B[100], C[200],i,m,n;
	
	clrscr();
	cout<<"XII Computer Science Journal(2019-2020)"<<endl;
	cout<<"Jasmin Chaughule Roll No. 2"<<endl;
	cout<<"Assignment 13 - Merging two integer arrays"<<endl<<endl;
	
	cout<<"\nEnter number of elements you want to insert in first array = ";
	cin>>m;

	cout<<"Enter elements in descending order =>\n";
	for(i=0;i<m;i++) {
		cin>>A[i];
	}

	cout<<"\nEnter number of elements you want to insert in second array = ";
	cin>>n;

	cout<<"Enter element in descending order =>\n";
	for(i=0;i<n;i++) {
		cin>>B[i];
	}

	Merge(A,B,C,m,n);
	
	cout<<"\nThe Merged Array in Ascending Order =>"<<endl;
	for(i=0;i<(m+n);i++) {
		cout<<C[i]<<" ";
	}

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
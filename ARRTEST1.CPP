#include<iostream.h>
#include<conio.h>
#include<stdio.h>

int main()
{
	clrscr();
	int i;

	char *names[100]; //An array of 100 pointers
	//char *names[] = {"Sachin", "Kapil", "Ajay", "Sunil", "Anil"};
	char *name; //A name string
	//char name[30];

	for(i = 0; i < 5; i++) {
		name = new char[30];
		if (!name) {
			cout<<"Out of memory! Aborting!";
			return 1;
		}
		cout<<"Enter a Name: ";
		gets(name);
		names[i] = name;
	}

	for(i = 0; i < 5; i++) {
		cout <<endl;
		cout <<names[i];

	}

	getch();

    return 0;
}
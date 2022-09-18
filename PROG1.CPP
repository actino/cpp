#include<fstream.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
char myline[75];
int lc = 0;
ofstream outfile("C:\\Jdata\\out.txt", ios::app);
ifstream infile("C:\\Jdata\\data.txt", ios::in);
if (!infile) {
	cerr<<"Failed to open file\n";
	getch();
	exit(1);
}
while (1) {
	infile.getline(myline, 75, '.');
	if (infile.eof()) break;
	lc++;
	outfile << lc << ":"<<myline<<"\n";
}
infile.close();
outfile.close();
cout<<"Output"<<lc<<"records"<<endl;
getch();
return 0;
}
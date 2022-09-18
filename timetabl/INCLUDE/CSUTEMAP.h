/*
*				CSUTEMAP.h
*
*
*This is the input data from data entry screens and stored in binary files
*Total 20 grade-divisions each with upto 10 subjects and one teacher per subject
*/
struct classentity  
	{
		int classid;
		int grade;
		char divi;
		char cstream[20];
		
		int total_subjects;
		int total_lectures; //can be maximum 25
		
		struct
		{
			int subjcode;
			char subjname[20];
			int numlectures;
			struct 
			{
				int empid;
				char tname[20];
			}
			teacher;
		}
		subjects[10];
	};

const int num_Days = 5;		//No. of days in a week
const int num_Lect = 5; 	//No. of lectures per day
const int num_Slots = 25; 	//num_Days x num_Lect
const int num_ClassDiv = 20;//Max No. of class - divisions in the school
const int num_Tchr = 25;	//Max No. of Teachers in the school 
const char emptyString20[] = "                   ";  //20 char blank string - actually 19 with null terminator in end

int getlen(int icode) {
	
	unsigned int number_of_digits = 0;
	
	do {
		 ++number_of_digits; 
		 icode /= 10;
	} while (icode);
	
	return number_of_digits;
	
}

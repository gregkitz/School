// ----------------------------------------------------------------------------
// You write meaningful overview comments and assumptions here

#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int const MAXSIZE = 100;            // maximum number of records in total
int const MAXLENGTH = 31;           // maximum string length 
int const MAXGRADE = 100;           // highest possible grade
int const LOWGRADE = 0;             // lowest possible grade
int const GROUP = 10;               // group amount
int const HISTOGRAMSIZE = (MAXGRADE-LOWGRADE)/GROUP + 1;    // grouped by GROUP

struct StudentType  {               // information of one student
   int grade;                       // the grade of the student
   char last[MAXLENGTH];            // last name (MAXLENGTH-1 at most)
   char first[MAXLENGTH];           // first name (MAXLENGTH-1 at most)
};

// prototypes go here
bool sortInput(istream& infile, StudentType students[], int& size);
void moveData(StudentType students[], int location);
void moveData(StudentType dataToMove[], int location);
void printStudentReport (StudentType dataToPrint[], const int& size); 
//-----------------------------------------------------------------------------
int main()  {
   StudentType students[MAXSIZE];   // list of MAXSIZE number of students
   int size = 0;                    // total number of students
   int histogram[HISTOGRAMSIZE];    // grades grouped by GROUP
   int average = 0;                 // average exam score, truncated

   // creates file object and opens the data file
   ifstream infile("data2.txt");
   if (!infile)  { 
      cout << "File could not be opened." << endl; 
      return 1;  
   }

   // read and sort input by last then first name
   bool successfulRead = sortInput(infile, students, size); 
   cout << "Successfully Read?" << successfulRead << endl;  
   printStudentReport(students, size);   

   // display list, histogram, and class average 
  // if (successfulRead)  {
  //    displayList(const StudentType students[], int size);
  //    setHistogram(... you figure parameters ...);
  //    displayHistogram(... you figure parameters ...);
  //    average = findAverage(... you figure parameters ...);
  //    cout << "Average grade: " << average << endl << endl;
  // }
   return 0;
}

// ----------------------------------------------------------------------------
// functions go here
bool sortInput(istream& infile, StudentType students[], int& size){
	StudentType temp; 
	// reads in data to temp location 
for(;;){
	infile >> temp.last >> temp.first >> temp.grade; 

	// sorts it using insertion sort 
	int savedSpot = 0; 
	for (int i = size - 1; i >= 0; i--) { 
	cout << "reentering loop" << endl; 	
	cout << "temporary last" << temp.last << "current last" << students[i].last << "size is: " << size << endl; 
	if (strcmp (temp.last, students[i].last) < 0 ) { 
			cout << "first if statement hit, new name is less than current name" << endl; 
		      students[i+1] = students [i];  
		      savedSpot = i; 
		}
	else if (strcmp (temp.last, students[i].last) == 0 && strcmp(temp.first, students[i].first) < 0){ 
			cout << "second if statement hit, last names are equal and first is less" << endl;  
	 		students[i+1] = students[i]; 
			savedSpot = i; 	
			}
	else { 
		cout << "found right place, breaking loop" << endl;
	       savedSpot = i+1; 	
		break; 
		}
	}
	students[savedSpot] = temp; 
	size++; 
	if (infile.eof()) break;


}
return true; 
	}
// -----------------------MOVE DATA--------------------------------------------
// Used in the insertion sort, moves the data towards the front of the array
void moveData(StudentType dataToMove[], int location) { 
	for (int i = 0; i < location; i++){
		dataToMove[i] = dataToMove[i+1]; 
	}

}
void printStudentReport (StudentType dataToPrint[], const int& size) { 
	for (int i = 0; i < size; i++)	{
	cout <<	"last name: " << dataToPrint[i].last << dataToPrint[i].first << dataToPrint[i].grade << endl; 

      }		

   }


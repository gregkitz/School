// -------------------------------------------------------------------------------------------------------
// CSS 342, Spring 2014
// Lab 1
// Greg Kitzmiller
//--------------------------------------------------------------------------------------------------------
// Sorts student data by last name and, if last names are equivalent, by first name.
// Display a list of students using an insertion sort to standard output.
// Data includes last name, first name, and grade. For example: 
//
// duck donald 90
// mouse mickey 50
// witch wicked 78
//
// Display a histogram of grade data to standard output. 
//
// Assumptions: 
// 	- data in text file formatted correctly. 
// 	- Names are less than MAXLENGTH. 
// 	- There are less than 100 grade records. 
// 	- Grades are integers. 
//--------------------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------------- 
//Prototypes
bool sortInput(istream& infile, StudentType students[], int& size); // reads in and sorts the input using an insertion sort by last name/first name
void displayList (StudentType dataToPrint[], const int& size); // Displays student data
void setHistogram (StudentType dataToSet[], int* histogram, const int& size); // Takes grades from student data and builds an array for a histogram
void displayHistogram (int * histogram); // Displays grade info as a histogram
int findAverage(StudentType gradeBook[], int& size); // Calculates the average grade
//--------------------------------------------------------------------------------------------------------
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
  
  

   // display lists, histogram, and class average 
   if (successfulRead)  {
     displayList(students, size);
     setHistogram(students, histogram, size);
     displayHistogram(histogram);
    average = findAverage(students, size);
     cout << "Average grade: " << average << endl << endl;
   }
   return 0;
}

// -------------------------------------------------------------------------------------------------------
// sortInput
// Sorts array (second parameter) into ascending order by last name, then first name
// first parameter is a reference to the stream object where student data is read in to be sorted
// algorithm starts from the high end of the sorted data and moves larger data than the current element
// to one higher index to make room for the current data
bool sortInput(istream& infile, StudentType students[], int& size){
	StudentType temp; 
	// reads in data to temp location 
while(true){

	infile >> temp.last >> temp.first >> temp.grade;
	if (temp.grade < 0 || temp.grade > 100) {
	cout << "Infile contains invalid data." << endl; 
	return false; 
	}
	if (infile.eof()) break;
	// sorts it using insertion sort 
	int savedSpot = 0; 
	for (int i = size - 1; i >= 0; i--) { 
	 
	
	   if (strcmp (temp.last, students[i].last) < 0 ) { 

		      students[i+1] = students [i];  
		      savedSpot = i; 
	   }
	   else if (strcmp (temp.last, students[i].last) == 0 && strcmp(temp.first, students[i].first) < 0){ 

	 		students[i+1] = students[i]; 
			savedSpot = i; 	
	   } else { 

	       savedSpot = i+1; 	
		break; 
	   }
	
	}

	students[savedSpot] = temp; 
	size++; 



}

return true; 
	}


//--------------------------------------------------------------------------------------------------------
//displayList
// Lists student data
void displayList (StudentType dataToPrint[], const int& size) { 
	cout << "List of names sorted: " << endl; 
	for (int i = 0; i < size; i++)	{
	cout <<	setw(4) <<  dataToPrint[i].grade << " " << dataToPrint[i].last << " " << dataToPrint[i].first << endl; 

      }		

   }
//--------------------------------------------------------------------------------------------------------
//setHistogram
// Uses the data from the array of students to update the current grade data
// uses integer division knowing that the index to update is 1/10th of the grade
void setHistogram (StudentType dataToSet[], int* histogram, const int& size) {
	for (int gradeIndex = 0; gradeIndex < size; gradeIndex++){
		int currentGrade = dataToSet[gradeIndex].grade;
		currentGrade = currentGrade / 10; 
		histogram[currentGrade]++; 
		}

	}
//--------------------------------------------------------------------------------------------------------
//displayHistogram
// Prints out the histogram
void displayHistogram (int * histogram){
       int lowerbound = 0, upperbound = 9; 	
cout << "Histogram grades: " << endl; 
	for (int i = 0; i < HISTOGRAMSIZE; i++) { 
cout << setw(4) << lowerbound << "-->  " << upperbound << ":"; 
	for (int g = histogram[i]; g > 0; g--) { 
		cout <<	"*"; 
			} cout << endl; 
	lowerbound += 10; 
	upperbound != 99 ? upperbound += 10 : upperbound += 1; 
		}	

	}
//--------------------------------------------------------------------------------------------------------
//findAverage
// Finds the average student grade by totaling the grades from the array of students
int findAverage(StudentType gradeBook[], int& size){ 
	int total = 0; 	
	for (int i = 0; i < size; i++){ 
		total += gradeBook[i].grade; 
		}
	total = total / size; 
		return total; 
	}

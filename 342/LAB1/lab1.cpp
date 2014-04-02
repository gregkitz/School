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
//-----------------------------------------------------------------------------
int main()  {
   StudentType students[MAXSIZE];   // list of MAXSIZE number of students
   int size = 1;                    // total number of students
   int histogram[HISTOGRAMSIZE];    // grades grouped by GROUP
   int average = 0;                 // average exam score, truncated

   // creates file object and opens the data file
   ifstream infile("data1.txt");
   if (!infile)  { 
      cout << "File could not be opened." << endl; 
      return 1;  
   }

   // read and sort input by last then first name
   bool successfulRead = sortInput(infile, students, size); 
   cout << "Successfully Read?" << successfulRead << endl;    

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
cout << "hello" << endl;
return true; 
	}


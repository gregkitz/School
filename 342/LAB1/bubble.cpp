//-----------------------------------------------------------------------------
// Sort student data (by their ID). 
// Display a list of students using a bubble sort to standard output.
// Data includes last name, first name, and ID.  For example:
//
// duck donald 50
// mouse mickey 22
// witch wicked 78
//
// Assumptions:  
//    -- Format of data is correct.
//    -- All names are no more in length than MAXLENGTH.
//    -- IDs are correctly sized as integers.
//    -- Data beyond MAXSIZE number of names is not in the list. 

#include <iostream>
#include <iomanip>
#include <fstream>  
using namespace std; 

int const MAXSIZE = 50;                   // maximum number of students
int const MAXLENGTH = 30;                 // maximum string length

struct Student {                          // information on one student
   int id;
   char lastName[MAXLENGTH];    
   char firstName[MAXLENGTH];   
   // more data as needed
};

//-----------------------------------------------------------------------------
// myswap
// swap two values of any type

template <typename TheType>
void myswap(TheType& val1, TheType& val2) {
   TheType temp;
   temp = val1;
   val1 = val2;
   val2 = temp;
}

// function prototypes
bool readData(istream&, Student [], int& );   // read data for class of students
void bubbleSort(Student [], int);             // sort into ascending order by id
void printList(const Student [], int);        // print the list of students

//-----------------------------------------------------------------------------

int main() {
   Student myClass[MAXSIZE];                 // all the students
   int size = 0;                             // total number of students
 
   // create file object and open the datafile 
   ifstream infile("bubble.txt");
   if (!infile) {
      cout << "File could not be opened." << endl;
      return false;
   }

   // get student data from a file, fill array then sort and print
   bool success = readData(infile, myClass, size);
   if (success) {

      // sort the students in ascending order by ID and print the list
      bubbleSort(myClass, size);
      cout << "List of students sorted by ID" << endl
           << "-----------------------------" << endl;
      printList(myClass, size);
      cout << endl;
   }
   return 0;
}



//-----------------------------------------------------------------------------
// readData
// read the data from a file (the first parameter) for one class of students  
// and place into array (second parameter); the third parameter, size, is the
// number of items in the array, always less than the maximum size, MAXSIZE 

bool readData(istream& infile, Student myClass[], int& size) {
   infile >> myClass[size].lastName;
   while (size < MAXSIZE && !infile.eof()) {
      infile >> myClass[size].firstName >> myClass[size].id;
      size++;
      infile >> myClass[size].lastName;
   }

// An alternative way to code this is to use an infinite loop and break.
// Just always be sure to attempt to read the first piece of data that
// is not there so the EOF char is read which triggers the eof() function.
//
// for(;;) {
//    infile >> myClass[size].lastName >> myClass[size].firstName 
//           >> myClass[size].id;
//    if (infile.eof()) break;
//    size++;
// }

   return true;
}

//-----------------------------------------------------------------------------
// bubblesort
// Sort array (first parameter) into ascending order by id number; second
// parameter is number of elements considered in the array.
// Algorithm compares consecutive elements and swaps when out of order.

void bubbleSort(Student myClass[], int size) {
   int pass = 0;                            // counts each pass of the sort
   bool done = false;                       // whether sorted or not 

   // each pass puts one element into its sorted position,
   // smallest value bubbles to the top of the array
   while (!done) {
      done = true;                                 // possibly sorted

      // compare consecutive elements, swap if out of order
      for (int i = size-1; i > pass; i--) {
         if (myClass[i].id < myClass[i-1].id) {
            myswap(myClass[i], myClass[i-1]);
            done = false;                          // still not sorted
         }
      }
      pass++;
   }
}

//-----------------------------------------------------------------------------
// printList
// print the list of students in given array for size number of items

void printList(const Student myClass[], int size) {
   for (int i=0; i < size; i++)  
      cout << setw(4) << myClass[i].id 
           << " " << myClass[i].lastName 
           << " " << myClass[i].firstName << endl;
}


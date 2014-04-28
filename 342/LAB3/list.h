#include <iostream>
using namespace std;

#include "list.h"
#include "nodedata.h"
#include "employee.h"

//---------------------- testCopyConstructor --------------------------------
// Not a member function, pass by value forces a copy to be made.
// After makeEmpty, the pass by reference list will be empty, while 
// the pass by value list will be the original list as in main.
// Also tests destructor behind the scenes.
//---------------------------------------------------------------------------

template <typename Object>
void testCopyConstructor(List<Object>& byRefList, List<Object> byValList) {
	cout << "Test Copy Constructor and Destructor" << endl;
	cout << "------------------------------------" << endl;
	byRefList.makeEmpty();
	cout << "after emptying, byRefList is: " << endl << byRefList << endl;
	cout << "byValList is: " << endl << byValList << endl;
}

int main() {
	// list of NodeData, to be sorted by numerical value, then char
	List<NodeData> mylist, mylist2, mylist3;
	NodeData* p = new NodeData(20, 'n');  mylist.insert(p);
	p = new NodeData(10, 'f');  mylist.insert(p);
	p = new NodeData(16, 'u');  mylist.insert(p);
	p = new NodeData(25, '!');  mylist.insert(p);

	p = new NodeData(16, 'u');  mylist2.insert(p);
	p = new NodeData(15, 't');  mylist2.insert(p);
	p = new NodeData(19, 'f');  mylist2.insert(p);
	p = new NodeData(14, 's');  mylist2.insert(p);
	p = new NodeData(25, '!');  mylist2.insert(p);
	p = new NodeData(18, 'f');  mylist2.insert(p);
	cout << "mylist:" << endl << mylist << endl;
	cout << "mylist2:" << endl << mylist2 << endl;

	List<NodeData> mylist4(mylist2);
	cout << "mylist4" << mylist4 << endl; 
	cout << "emptying list 2" << endl;
	

	//// Many lists of employees, 
	//// to be sorted alphabetically by last name, then first.
	//// Vary the data files to test your list code.
	bool success;
	Employee* oneEmployee;
	List<Employee> company1, company2, company3, company4, company5, company6,
		company7, company8, company9, company10, company11;
	ifstream infile1("data31.txt"), infile2("data32.txt"),
		infile3("data33.txt"), infile4("data34.txt");

	company1.buildList(infile1);
	company2.buildList(infile2);
	company3.buildList(infile3);
	company4.buildList(infile4);

	cout << company1 << endl; 
	cout << company2 << endl; 
	cout << company3 << endl; 
	cout << company4 << endl; 
	company6 = company4;
	company7 = company1;
	company8 = company2;
	company10 = company11 = company3;

	cout << "company 10: " << endl << company10 << endl; 
	cout << "test == " << endl;
	cout << "--------" << endl;
	Employee emp1("Bell", "Regan");      // last name, first name
	Employee emp2("squirrel", "rocky");
	// knows emp1 and emp2 are in the lists, so deletes without checking
	success = company10.retrieve(emp1, oneEmployee); 
	//delete oneEmployee;
	cout << *oneEmployee << endl; 
	//cout << company10 << endl; 
	cout << success << endl; 
 //   success = company11.remove(emp2, oneEmployee);  delete oneEmployee;
	//cout << "Company10:" << endl << company10 << endl;
	//cout << "Company11:" << endl << company11 << endl;
	//cout << "company10 " << (company10 == company11 ? "equals" : "does not equal")
	//	<< " company11" << endl;
	//success = company11.remove(emp1, oneEmployee);  delete oneEmployee;
	//cout << "Company11:" << endl << company11 << endl;
	//cout << "company10 " << (company10 == company11 ? "equals" : "does not equal")
	//	<< " company11" << endl;

	//cout << "test remove and retrieve on 4" << endl;
	//cout << "-----------------------------" << endl;
	//Employee emp3("aaaaa", "aa");
	//Employee emp4("zzzzz", "zz");
	//success = company4.retrieve(emp3, oneEmployee);
	//if (success) cout << "Found in list:  " << *oneEmployee << endl;
	//else         cout << "Did not find aaaaa in list" << endl;
	//success = company4.retrieve(emp4, oneEmployee);
	//if (success) cout << "Found in list:  " << *oneEmployee << endl;
	//else         cout << "Did not find zzzzz in list" << endl;
	//Employee emp5("ghost", "casper");
	//Employee emp6("rella", "barbara");
	//Employee emp7("bear", "bertha");
	//success = company4.remove(emp5, oneEmployee);
	//if (success) {
	//	cout << "Removed:  " << *oneEmployee << endl;
	//	delete oneEmployee;                          // could insert elsewhere
	//}
	//else
	//	cout << "Did not find ghost in list" << endl;
	//success = company4.remove(emp6, oneEmployee);
	//if (success) {
	//	cout << "Removed:  " << *oneEmployee << endl;
	//	delete oneEmployee;
	//}
	//else
	//	cout << "Did not find rella in list" << endl;
	//success = company4.remove(emp7, oneEmployee);
	//if (success) {
	//	cout << "Removed:  " << *oneEmployee << endl;
	//	delete oneEmployee;
	//}
	//else
	//	cout << "Did not find bear in list" << endl;
	//cout << "Company4 after removes:" << endl << company4 << endl;

	//testCopyConstructor(company10, company10);
	//cout << "back in main, Company10:" << endl << company10 << endl;
	return 0;
}

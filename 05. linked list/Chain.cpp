#include "Chain.h"
using namespace std;

int main() {
	Chain<int> list1;
	Chain<int> list2;

	cout << "print list1 state: ";
	list1.Print();
	cout << "print list2 state: ";
	list2.Print();
	cout << endl;

	for (int i = 0; i < 10; i++) { 
		const int j = i;
		if (i % 2 == 1) list1.InsertBack(j); 
	}
	cout << "After list1 InsertBack..." << endl;
	list1.Print();
	cout << endl << endl;
	

	for (int i = 0; i < 10; i++) { 
		const int j = i;
		if (i % 2 == 0) list2.InsertBack(j); 
	}
	cout << "After list2 InsertBack..." << endl;
	list2.Print();
	cout << endl << endl;

	list1.Concatenate(list2);
	cout << "After list1 and list2 Concatenate..." << endl;
	list1.Print();
	cout << endl << endl;

	list1.Reverse();
	cout << "After Reverse the list1..." << endl;
	list1.Print();
	return 0;
}

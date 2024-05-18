#include <iostream>
#include "MaxHeap.h"
using namespace std;

int main() {
	MaxHeap<int> heap = MaxHeap<int>(10);

	for (int i = 0; i < 9; i++) {
		const int j = i;
		heap.Push(j);
	}
	cout << "After Push 9 nodes... " << endl;
	heap.Print();
	cout << endl;

	for (int i = 0; i < 5; i++) heap.Pop();
	cout << "After Pop 5 nodes... " << endl;
	heap.Print();
}

// HeapSort algorithm and helper functions
// Ambidextrous
// Written in C++
// March 2011

#include <iostream>
#include <cmath>
#include <vector>
#include <string> // For getline()
#include <sstream>
using namespace std;

const int SIZE = 11;	// Assuming array size = 10, 1-indexed

// Inline functions
inline int parent(int i) {
	return floor(i / 2);
}

inline int left(int i) {
	return 2 * i;
}

inline int right(int i) {
	return 2 * i + 1;
}

// Functions
// Assumption: array is 1-indexed

void maxHeapify(vector<int>& iVector, int i, int heapSize) {
	int l = left(i);
	int r = right(i);
	int largest;
	if(l <= heapSize && iVector[l] > iVector[i]) 
		largest = l;
	else
		largest = i;

	if(r <= heapSize && iVector[r] > iVector[largest])
		largest = r;

	if(largest != i) {
		swap(iVector[i], iVector[largest]);
		maxHeapify(iVector, largest, heapSize);		
	}
}

void buildMaxHeap(vector<int>& iVector, int heapSize) {
	for(int i = floor(SIZE / 2); i >= 1; i--)
		maxHeapify(iVector, i, heapSize);
}

void heapSort(vector<int>& iVector) {
	int heapSize = iVector.size() - 1; 
	buildMaxHeap(iVector, heapSize);
	for(int i = iVector.size()-1; i>=2; i--) {
		swap(iVector[1], iVector[i]);
		heapSize--;
		maxHeapify(iVector, 1, heapSize);
	}
}

void getUserInput(vector<int>& iVector) {
	for(int i = 1; i < SIZE; i++) {
		while(true) {
			string s;
			int in;
			stringstream checker;
			getline(cin, s);

			checker << s;
			// Check for type
			if(checker >> in) {
				// Check for leftovers
				char rem;
				if(checker >> rem) 
					cout << "Too much data, try again." << endl;
				else {
					iVector[i] = in;
					break;
				}
			} else
			cout << "Type mismatch, try again." << endl;
		}
	}
}

void displayOutput(vector<int>& iVector) {
	cout <<  "The sorted list is: " << endl;

	for(int i = 1; i < iVector.size() - 1; i++)
		cout << iVector[i] << " -- ";

	cout << iVector[iVector.size() - 1] << endl;
	cout << "HeapSort successful." << endl;
}

int main() {

	vector<int> iVector;
	iVector.resize(SIZE); // Or use ::push_back()

	cout << "Enter 10 numbers below: " << endl;
	getUserInput(iVector);

	heapSort(iVector);

	displayOutput(iVector);	
		
	return 0;
}

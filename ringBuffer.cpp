// Ring buffer implementation
// using <deque>
// Ambidextrous
// Mar 2011

#include <iostream>
#include <string> // For getline()
#include <sstream>
#include <deque>
#include <iomanip>
using namespace std;

int getInteger() {
	string s;
	stringstream checker;
	int i;

	while(true) {

		getline(cin, s);
		checker << s;
	
		// Check for type
		if(checker >> i) {
			// Check for extra data
			char rem;
			if(checker >> rem)
				cout << "Too much data! Try again." << endl;
			else 
				return i;
		} else 
			cout << "Type mismatch! Try again. " << endl;
	}
}

void getNumbers(deque<int>& ringBuffer) {
	cout << "How many elements? " << endl;
	int num = getInteger();

	cout << "Enter " << num << " values below: " << endl;
	for(int i = 0; i < num; i++) {
		int val = getInteger();
		ringBuffer.push_back(val);
	}
}

void cursorClockwise(deque<int>& ringBuffer) {
	// Move last element to front
	int last = ringBuffer.back();
	ringBuffer.pop_back();
	ringBuffer.push_front(last);
}

void cursorCounterClockwise(deque<int>& ringBuffer) {
	// Move first element to last
	int first = ringBuffer.front();
	ringBuffer.pop_front();
	ringBuffer.push_back(first);
}

void display(deque<int>& ringBuffer) {
	cout << "The ring buffer looks like: " << endl;

	for(size_t i = 0; i < ringBuffer.size(); i++)
		cout << ringBuffer[i] << " ";

	cout << endl;

	cout << "The cursor is at: " << endl;
	cout << ringBuffer[0] << endl;

	cout << setfill('-') << setw(20) << ' ' << endl;
}

int cursorRead(deque<int>& ringBuffer) {
	return ringBuffer.front();
}

void cursorWrite(deque<int>& ringBuffer, int value) {
	ringBuffer[0] = value;
}

int main() {

	deque<int> ringBuffer;

	getNumbers(ringBuffer);
	cout << "Obtained input." << endl;
	display(ringBuffer);
	cursorClockwise(ringBuffer);
	cout << "Clockwise rotation." << endl;
	display(ringBuffer);
	cursorCounterClockwise(ringBuffer);
	cout << "Counter clockwise rotation." << endl;
	display(ringBuffer);
	int val = cursorRead(ringBuffer);
	cout << "Value at cursor: " << val << endl;
	cursorWrite(ringBuffer, 7);
	cout << "Writing 7 to the cursor." << endl;
	display(ringBuffer);

	int i;
	cin >> i;

	return 0;
}

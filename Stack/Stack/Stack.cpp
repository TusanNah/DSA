#include "iostream"
#include "stdlib.h"
using namespace std;
class Stack { //Last In First Out (LIFO)
private:
	int arr[5];
	int top;
public:
	int getVal(int index) {
		return arr[index];
	}
	Stack() {
		top = -1;
		for (int i = 0; i < 5; i++)
			arr[i] = 0;
	}
	bool IsEmpty() {
		if (top == -1)
			return true;
		else
			return false;
	}
	bool IsFull() {
		if (top == 4)
			return true;
		else
			return false;
	}
	void Push(int val) {// Put a new item on the top of the stack 
		if (IsFull())
			cout << endl << "Stack overflow!!";
		else {
			top++;
			arr[top] = val;
		}
	}
	int Pop() { // Get the item at the top of the stack then delete it
		if (IsEmpty()) {
			cout << endl << "Stack underflow!";
			return 0;
		}
		else {
			int popVal = arr[top];
			top--;
			return popVal;
		}
	}
	int Peek(int pos) { // Get the item at the i position
		if (IsEmpty()) {
			cout << endl << "Can not get the item at that position!!";
		}
		else
			return arr[pos];
	}
	int Count() {
		return top + 1;
	}
	void Change(int pos, int val) {
		if (IsEmpty())
			return;
		else {
			arr[pos] = val;
		}
	}
	void Display() {
		if (IsEmpty()) {
			cout << endl << "There is no value to display!!";
			return;
		}
		else {
			for (int i = top; i >= 0; i--) 
				cout << endl << arr[i];
		}
	}
};
void main() {
	Stack s;
	int opt = -1;
	while (opt != 0) {
		cout << endl << "0. Stop program\n1.Push \n2. Pop\n3. Peek\n4. Count\n5. Change\n6. Display\n7. Display and delete stack";
		cout << endl << "Enter your option: ";
		cin >> opt;
		system("CLS");
		switch (opt) {
		case 0:
			exit(1);
		case 1:
			cout << endl << "Enter the value you want to push: ";
			int val; cin >> val;
			s.Push(val);
			break;
		case 2:
			cout << endl << "The pop value is " << s.Pop();
			break;
		case 3:
			cout << endl << "Enter the position u want to peek: ";
			int pos; cin >> pos;
			cout << endl << "The value at the position u want to peek is: " << s.Peek(pos);
			break;
		case 4:
			cout << endl << "The number of items: " << s.Count();
			break;
		case 5:
			cout << "Enter the position and value: ";
			cin >> pos >> val;
			s.Change(pos, val);
			cout << "The index after being changed is: " << s.getVal(pos);
			break;
		case 6:
			s.Display();
			break;
		default:
			exit(1);
			break;
		}
	}
}
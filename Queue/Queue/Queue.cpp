#include "iostream"
using namespace std;
class Queue { // First In First Out (FIFO) or Last In Last Out  (LILO)
private:
	int front;
	int rear;
	int arr[5];
public:
	Queue() {
		front = rear = -1;
	}
	int getFront() {
		return front;
	}
	int getRear() {
		return rear;
	}
	int getVal(int index) {
		return arr[index];
	}
	bool IsEmpty() {
		if (front == -1 && rear == -1)
			return true;
		else
			return false;
	}
	bool IsFull() {
		if (rear == 4)
			return true;
		else
			return false;
	}
	void Enqueue(int val){//Add an element at rear end (back end)
		if (IsFull()) {
			cout << endl << "Queue is full";
		}
		if (IsEmpty()) {
			front = rear = 0;
		}
		else {
			rear++;
		}
		arr[rear] = val;
	} 
	int Dequeue() {//Get an element at head end and remove it (front end)
		if (IsEmpty())
			return 0;
		if (front == rear) {
			int val = arr[front];
			front = rear = -1;
			return val;
		}
		else {
			int val = arr[front];
			front++;
			return val;
		}
	}
	int Count() {
		return rear - front + 1;
	}
};
void main() {
	Queue q;
	int opt = -1;
	while (opt != 0) {
		cout << endl << "1. Enqueue\n2. Dequeue\n3. Count\n4. Display\n0. Exit";
		cout << endl << "Enter your option: ";
		cin >> opt;
		switch (opt) {
		case 1:
			int val;
			cout << endl << "Enter the value u want to Enqueue: ";
			cin >> val;
			q.Enqueue(val);
			break;
		case 2:
			cout << endl << "The value at the front end: " << q.Dequeue();
			cout << endl << "---------";
			break;
		case 3:
			cout << endl << "Quantity: " << q.Count();
			cout << endl << "---------";
			break;
		case 4:
			for (int i = q.getFront(); i <= q.getRear(); i++)
				cout << endl << q.getVal(i);
			cout << endl << "---------";
			break;
		case 0:
			exit(1);
			break;
		}
	}
}
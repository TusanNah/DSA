#include "iostream"
using namespace std;
struct Node {
	int data;
	Node* next;
};
Node* CreateNode(int x) {
	Node* p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}
struct List {
	Node* pHead;
	Node* pTail;
};
void InitList(List& l) {
	l.pHead = l.pTail= NULL;
}
bool IsEmpty(List l) {
	return l.pHead == NULL && l.pTail==NULL;
}
void AddTail(List &l, int x) {
	Node* p = CreateNode(x);
	if (IsEmpty(l))
		l.pHead = l.pTail = p;
	else {
		l.pTail->next = p;
		l.pTail = p;
	}
}
// Find the nth node counted from the last node (take last node as the 0th)
int FindNodeN(List l, int n) {
	Node* p = l.pHead;
	int count = 0;
	while (p!=NULL) {
		count++;
		p = p->next;
	}
	int temp = count - n + 1;
	cout << endl << count;
	cout << endl << temp;
	count = 0;
	p = l.pHead;
	while (p!=NULL) {
		count++;
		if (count == temp)
			return p->data;
		p = p->next;
	}
}
void Test() {
	List l;
	InitList(l);
	cout << "Enter n: ";
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Enter value: ";
		int x; cin >> x;
		AddTail(l, x);
	}
	int item = FindNodeN(l, 2);
	cout << endl << item;
}
void main() {
	Test();
}
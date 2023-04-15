#include "iostream"
using namespace std;
struct Node {
	int data;
	Node* next;
	Node* prev;
};
Node* CreateNode(int data) {
	Node* p = new Node;
	p->data = data;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
struct List {
	Node* pHead;
	Node* pTail;
};
void InitList(List& l) {
	l.pHead = l.pTail = NULL;
}
bool IsEmpty(List l) {
	return l.pHead == NULL && l.pTail == NULL;
}
void AddTail(List& l, int x) { // Successfully
	Node* p = CreateNode(x);
	if (IsEmpty(l))
		l.pHead = l.pTail = p;
	else {
		l.pTail->next = p;
		p->prev = l.pTail;
		l.pTail = p;
	}
}
void AddHead(List& l, int x) { // Successfully
	Node* p = CreateNode(x);
	if (IsEmpty(l))
		l.pHead = l.pTail = p;
	else {
		p->next = l.pHead;
		l.pHead->prev = p;
		l.pHead = p;
	}
}
void Dash() {
	cout << endl << "-------------------" << endl;
}
void AddAfterNodeQ(List& l, Node* q, int x) {
	Node* p = CreateNode(x);
	if (IsEmpty(l))
		return;
	Node* temp = l.pHead;
	while (temp != NULL) {
		if (temp == q) {
			if (temp == l.pTail)
				AddTail(l, x);
			else {
				p->prev = q;
				p->next = q->next;
				q->next = p;
				p->next->prev = p;
			}
		}
		temp = temp->next;
	}
}
void AddBeforeNodeQ(List& l, Node* q, int x) {
	Node* p = CreateNode(x);
	if (IsEmpty(l))
		return;
	Node* temp = l.pHead;
	while (temp != NULL) {
		if (temp == q) {
			if (temp == l.pHead)
				AddHead(l, x);
			else {
				p->prev = q->prev;
				p->next = q;
				p->prev->next = p;
				q->prev = p;
			}
			temp = temp->next;
		}
	}
}
void DeleteNodeQ(List& l, Node* q) { 
	if (q == l.pHead && q == l.pTail) {
		delete q;
		l.pHead = l.pTail = NULL;
		return;
	}
	Node* temp = l.pHead;
	while (temp != NULL) {
		if (temp == q) {
			if (temp == l.pHead) {
				temp->next->prev = NULL;
				l.pHead = temp->next;
				delete temp;
				temp->next = temp->prev = NULL;
				return;
			}
			else if (temp == l.pTail) {
				temp->prev->next = NULL;
				l.pTail = temp->prev;
				delete temp;
				temp->next = temp->prev = NULL;
				return;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				temp = q->next;
				delete q;
				q->next = q->prev = NULL;
				continue;
			}
		}
		temp = temp->next;
	}
}
void DeleteAfterNodeQ(List& l, Node* q) {
	if (q == l.pTail)
		return;

}
void Test() {
	
}
void main() {
	Test();
}

#pragma once
#include "iostream"
typedef struct Node* pNode;
//struct Node {
//	int data;
//	pNode next;
//};
//using namespace std;
//void heapify(int a[], int n, int i) {
//	int largest = i;
//	int left = 2 * i + 1;
//	int right = 2 * i + 2;
//	if (left<n && a[left]>a[largest])
//		largest = left;
//	if (right<n && a[right]>a[largest])
//		largest = right;
//	if (largest != i) {
//		swap(a[largest], a[i]);
//		heapify(a, n, largest);
//	}
//}
//// Rearrange array
//void buildMaxHeap(int a[], int n) {
//	for (int i = (n - 2) / 2; i >= 0; i--) {
//		heapify(a, n, i);
//	}
//}
//void heapSort(int a[], int n) {
//	buildMaxHeap(a, n);
//	int j = n - 1;
//	for (int i = n-1; i >= 0; i--) {
//		swap(a[0],a[i]);
//		heapify(a, i, 0);
//	}
//}
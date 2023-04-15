#include "iostream"
#include <vector>
#include <cmath>
using namespace std;

template <class T>
void Swap(T a, T b) {
	T temp = a;
	a = b;
	b = temp;
}
void SelectionSort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		int min = a[i];
		for (int j = i + 1; j < n; j++) {
			if (a[j] < min)
				min = a[j];
		}
		swap(min, a[i]);
	}
}
//<InsertionSort
void InsertionSort(int* a, int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int j = i - 1;
		while (j >= 0 && x < a[j]) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = x;
	}
}
//Insertion Sort>

//<QuickSort
int patrition(int* a, int l, int r, int pivot) {
	int i = l;
	swap(a[pivot], a[r]);
	int j = r - 1;
	while (i <= j) {
		while (a[i] < a[r])
			i++;
		while (a[j] >=a[r])
			j--;
		if (i < j)
			swap(a[i], a[j]);
	}
	swap(a[i], a[r]);
	return i;
}
void QuickSort(int* a, int l, int r) {
	if (l < r) {
		int pivot = (l + r) / 2;
		int k = patrition(a,l,r,pivot);
		QuickSort(a, l, k - 1);
		QuickSort(a, k + 1, r);
	}
}
//QuickSort>

//<MergeSort
void Merge(int* a, int l, int m, int r) {
	int nL = m - l + 1; //So phan tu cua mang ben trai
	int nR = r - (m + 1) + 1; //So phan tu cua mang ben phai
	int* L = new int[nL];
	int* R = new int[nR];
	for (int i = 0; i < nL; i++)
		L[i] = a[l + i];
	for (int j = 0; j < nR; j++)
		R[j] = a[ m + 1 + j];
	int iL = 0, iR = 0, iA = l; 
	while (iL < nL && iR < nR) { // Noi 2 mang tang dan lai voi nhau
		if (L[iL] < R[iR]) {
			a[iA] = L[iL];
			iA++;
			iL++;
		}
		else {
			a[iA] = R[iR];
			iA++;
			iR++;
		}
	}
	while (iL < nL) //Neu mang ben trai con phan tu thi tiep tuc noi vo mang lon a
		a[iA++] = L[iL++];
	while (iR < nR) //Neu mang ben phai con phan tu thi tiep tuc noi vo mang lon a
		a[iA++] = R[iR++];
	delete[] L, R;
}
void MergeSort(int* a, int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		MergeSort(a, l, mid);
		MergeSort(a, mid + 1, r);
		Merge(a, l, mid, r);
	}
}
//Merge Sort>

//<Radix Sort
int MaxDigits(int* a, int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	int count = 0;
	while (max != 0) {
		count++;
		max /= 10;
	}
	return count;
}
void RadixSort(int* a, int n) { //
	// Count max digits
	int maxDigits = MaxDigits(a, n);
	cout << endl << "mx digits: " << maxDigits << endl;
	vector <vector<int>> hash(10);
	// To mark if the nth position of hash table contains value or not
	for (int i = 1; i <= maxDigits; i++) { // i=1, array is sorted by increasing order of units; i=2,.....of dozens,.... 
		for (int j = 0; j < n; j++) {
			int remain = (a[j]/(int)pow(10,i-1))%10; // get the digits of unit, dozen, hundred
			hash[remain].push_back(a[j]); // if this array needs sorting by decreasing, let hash[9-main].
		}
		int count = 0; // Assign hash table to array
		for (int k = 0; k < 10; k++) {
			for (int l=0;l<hash[k].size();l++){
				a[count++] = hash[k][l];
			}
			hash[k].clear();
		}
	}
}

//Radix Sort>

//<Heap sort
void heapify(int* a,int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left<n && a[left]>a[largest])
		largest = left;
	if (right<n && a[right]>a[largest])
		largest = right;
	if (largest != i) {
		swap(a[largest], a[i]);
		heapify(a, n, largest);
	}
}
void builMaxHeap(int* a, int n) {
	for (int i = (n - 2) / 2; i >= 0; i--) {
		heapify(a, n, i);
	}
}
void HeapSort(int* a, int n) {
	builMaxHeap(a, n);
	for (int i = n - 1; i >= 1; i--) {
		swap(a[i], a[0]);
		heapify(a, i, 0);
	}
}
//Heap sort>
void main() {
	vector<vector <int>> v(10);
	cout << endl << "n: ";
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	HeapSort(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " " ;
	}
	delete[] arr;
	arr = NULL;
	//cout << endl << endl;
	//int a[] = { 3,-2,5,8,7,9,6,3232,245,23 };
	//int lengthA = sizeof(a) / sizeof(a[0]);
	//QuickSort(a, 0, lengthA - 1);
	//for (int i = 0; i < lengthA; i++) {
	//	cout << a[i] << " ";
	//}
	//cout << endl;
	//int b[] = { 3,-2,5,8,7,9,6 };
	//int lengthB = sizeof(b) / sizeof(b[0]);
	//InsertionSort(b, lengthB);
	//for (int i = 0; i < lengthB; i++) {
	//	cout << b[i] << " ";
	//}
	//cout << endl;
	//int c[] = { 3,-2,5,8,7,9,6 };
	//int lengthC = sizeof(c) / sizeof(c[0]);
	//MergeSort(c, 0, lengthC-1);
	//for (int i = 0; i < lengthB; i++) {
	//	cout << c[i] << " ";
	//}
}
#include "iostream"
using namespace std;
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
};
struct Tree {
	TreeNode* root;
};

void PrintLeaf(TreeNode* p) { // Print all the leaves
	if (p == NULL)
		return;
	if (p->left == NULL && p->right == NULL)
		cout << p->data << " ";
	PrintLeaf(p->left);
	PrintLeaf(p->right);
}

void NodeHasOnlyChild(TreeNode* p) { // 
	if (p == NULL)
		return;
	if (p->left == NULL || p->right == NULL)
		cout << p->data << " ";
	NodeHasOnlyChild(p->left);
	NodeHasOnlyChild(p->right);
}

int CountNodeHasOddAndEven(TreeNode* p) { //Count Node that has both odd and even number
	if (p == NULL)
		return 0;
	int c = 0;
	if (p->left != NULL && p->right != NULL) {
		if (p->left->data % 2 == 0 && p->right->data % 2 != 0)
			c++;
		else if (p->left->data % 2 != 0 && p->right->data % 2 == 0)
			c++;
	}
	int a=CountNodeHasOddAndEven(p->left);
	int b = CountNodeHasOddAndEven(p->right);
	return a + b + c;
}

int Height(TreeNode* p) { // Calculate the height of a tree.
	if (p == NULL)
		return 0;
	int a=Height(p->left);
	int b = Height(p->right);
	return max(a, b) + 1;
}
void MaxHeap(int a[], int n, int i) { // For complete binary tree
	int maxIndex = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && a[left] > a[maxIndex])
		maxIndex = left;
	if (right < n && a[right] > a[maxIndex])
		maxIndex = right;
	if (maxIndex != i) {
		swap(a[maxIndex], a[i]);
		MaxHeap(a, n, maxIndex);
	}
}
void main() {
	int n; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	MaxHeap(a, n, 0);
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << a[i]<< " ";
}

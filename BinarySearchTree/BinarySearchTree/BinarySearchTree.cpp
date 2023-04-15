#include "iostream"

using namespace std;
struct NODE {
	int data;
	NODE* left;
	NODE* right;
};
struct BST {
	NODE* root;
};
bool IsEmpty(BST tree) {
	return tree.root == NULL;
}
void InitBST(BST& tree) {
	tree.root = NULL;
}

//1. Initialize a NODE from a given value :

NODE* CreateNodeTree(int x) {
	NODE* p = new NODE;
	p->data = x;
	p->left = NULL;
	p->right = NULL; 
	return p;
}

// 2. Add a NODE with given value into a given Binary Search Tree 

void InsertNode(NODE* &root, int x) {
	if (root == NULL) {
		NODE* p = CreateNodeTree(x);
		root = p;
		return;
	}
	if (x < root->data)
		InsertNode(root->left, x);
	else if (x > root->data)
		InsertNode(root->right, x);
	else
		return;
}


// Print max of BST
void printMax(NODE* root) {
	if (root == NULL)
		return;
	if (root->right == NULL)
		cout << root->data;
	printMax(root->right);
}



//3. Pre-order Traversal
void NLR(NODE* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	NLR(root->left);
	NLR(root->right);
}
// 4. In-order Traversal

void LNR(NODE* root) {
	if (root == NULL)
		return;
	LNR(root->left);
	cout << " " << root->data << " ";
	LNR(root->right);
}

// 5. Post-order Traversal
void  LRN(NODE* root) {
	if (root == NULL)
		return;
	LRN(root->left);
	LRN(root->right);
	cout << " " << root->data << " ";
}



//7. Calculate the height of a given Binary Tree;
int Height(NODE* pRoot) {
	if (pRoot == NULL)
		return 0;
	int leftHeight = 1;
	int rightHeight = 1;
	if (pRoot->left != NULL)
		leftHeight = 1 + Height(pRoot->left);
	if (pRoot->right != NULL)
		rightHeight = 1 + Height(pRoot->right);
	return max(leftHeight, rightHeight);
}
// 6. Level-order Traversal
void printCurrentLevel(NODE* pRoot, int level) {
	if (pRoot == NULL)
		return;
	if (level == 0)
		cout << pRoot->data << " ";
	else if (level > 0) {
		printCurrentLevel(pRoot->left, level - 1);
		printCurrentLevel(pRoot->right, level - 1);
	}
}
void LevelOrder(NODE* pRoot) {
	int h = Height(pRoot);
	for (int i = 0; i <= h; i++) {
		printCurrentLevel(pRoot, i);
	}
}

//8. Count the number of NODE from a given Binary Tree :

int countNode(NODE* pRoot) {
	if (pRoot == NULL)
		return 0;
	return 1 + countNode(pRoot->left) + countNode(pRoot->right);
}
//9. Calculate the total value of all NODEs from a given Binary Tree :
int sumNode(NODE* pRoot) {
	if (pRoot == NULL)
		return 0;
	return pRoot->data + sumNode(pRoot->left) + sumNode(pRoot->right);
}
// 10. Find and return a NODE with given value from a given Binary Search Tree:
NODE* SearchNode(NODE* root, int x) {
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	if (x < root->data)
		return SearchNode(root->left, x);
	else
		return SearchNode(root->right, x);
}

//11. Remove a NODE with given value from a given Binary Search Tree :
NODE* maxNodeBST(NODE* root) {
	if (root == NULL)
		return NULL;
	if (root->right == NULL)
		return root;
	return maxNodeBST(root->right);
}
NODE* minNodeBST(NODE* root) {
	if (root == NULL)
		return NULL;
	if (root->left == NULL)
		return root;
	return minNodeBST(root->left);
}

void Remove(NODE*& pRoot, int x) {
	if (pRoot == NULL)
		return;
	if (x < pRoot->data)
		Remove(pRoot->left, x);
	if (x > pRoot->data)
		Remove(pRoot->right, x);
	else {
		if (pRoot->left == NULL && pRoot->right == NULL) {
			delete pRoot;
			pRoot = NULL;
		}
		if (pRoot->right==NULL) {
			pRoot = pRoot->left;
		}
		else if (pRoot->left == NULL) {
			pRoot = pRoot->right;
		}
		else { //Having 2 children
			NODE* temp = maxNodeBST(pRoot->left);
			pRoot->data = temp->data;
			Remove(pRoot->left, x);
		}
	}
}

// Delete BST node
NODE* deleteBSTNode(NODE* root, int x) {
	if (x < root->data)
		root->left = deleteBSTNode(root->left, x);
	else if (x > root->data)
		root->right = deleteBSTNode(root->right, x);
	else {
		if (root->left == NULL && root->right == NULL) {
			return NULL;
		}
		else if (root->right == NULL) {
			NODE* pTemp = root->left;
			delete root;
			return pTemp;
		}
		else if (root->left == NULL) {
			NODE* pTemp = root->right;
			delete root;
			return pTemp;
		}
		NODE* temp = maxNodeBST(root->left);
		root->data = temp->data;
		deleteBSTNode(root->left, root->data);
	}
	return root;
}

//12. Initialize a Binary Search Tree from a given array:
NODE* createTree(int a[], int n) {
	NODE* root = CreateNodeTree(a[0]);
	for (int i = 1; i < n; i++)
		InsertNode(root, a[i]);
	return root;
}

//13. Completely remove a given Binary Search Tree :
void removeTree(NODE*& pRoot) {
	if (pRoot == NULL)
		return;
	removeTree(pRoot->left);
	removeTree(pRoot->right);
	delete pRoot;
	pRoot = NULL;
//	if (pRoot->left != NULL && pRoot->right != NULL) {
//		NODE* tempLeft = pRoot->left;
//		NODE* tempRight = pRoot->right;
//		delete pRoot;
//		pRoot = NULL;
//		removeTree(tempLeft);
//		removeTree(tempRight);
//	}
//	if (pRoot->left == NULL) {
//		NODE* tempRight = pRoot->right;
//		delete pRoot;
//		pRoot = NULL;
//		removeTree(tempRight);
//	}
//	if (pRoot->right == NULL) {
//		NODE* tempLeft = pRoot->left;
//		delete pRoot;
//		pRoot = NULL;
//		removeTree(tempLeft);
//	}
}


//14. Calculate the height of a NODE with given value : (return -1 if value not exist)
int heightNode(NODE* pRoot, int value) {
	NODE* p=SearchNode(pRoot, value);
	if (p == NULL)
		return -1;
	return Height(p);
}
//15. * Calculate the level of a given NODE :
int Level(NODE* pRoot, NODE* p) {
	return Height(pRoot) - Height(p);
}
// 16. * Count the number leaves from a given Binary Tree:
int countLeaf(NODE* pRoot) {
	if (pRoot == NULL)
		return 0;
	if (pRoot->left == NULL && pRoot->right == NULL)
		return 1 + countLeaf(pRoot->left) + countLeaf(pRoot->right);
	return  countLeaf(pRoot->left) + countLeaf(pRoot->right);
}

//17. * Count the number of NODE from a given Binary Search Tree which key value is less than a given value :
int countLess(NODE* pRoot, int x) {
	if (pRoot == NULL)
		return 0;
	if (pRoot->data < x)
		return 1 + countLess(pRoot->left, x) + countLess(pRoot->right, x);
	return countLess(pRoot->left, x) + countLess(pRoot->right, x);
}
//18. * Count the number of NODE from a given Binary Search Tree which key value is greater than a
//given value :
int countGreater(NODE* pRoot, int x) { // count node greater than x
	if (pRoot == NULL)
		return 0;
	if (pRoot->data > x)
		return 1 + countGreater(pRoot->left, x) + countGreater(pRoot->right, x);
	return countGreater(pRoot->left, x) + countGreater(pRoot->right, x);
 }
	
//19. * Determine if a given Binary Tree is Binary Search Tree 

bool isBST(NODE* pRoot) {
	if (pRoot == NULL)
		return true;
	bool Left = true;
	bool Right = true;
	if (pRoot->left != NULL) {
		if (pRoot->left->data < pRoot->data)
			Left = true;
		else
			Left = false;
	}
	if (pRoot->right != NULL) {
		if (pRoot->right->data > pRoot->data)
			Right = true;
		else
			Right= false;
	}
	return Left && Right && isBST(pRoot->left) && isBST(pRoot->right);

}
//20. * Determine if a given Binary Tree is a Full Binary Search Tree :
bool IsFullTree(NODE* pRoot) {
	if (pRoot == NULL)
		return true;
	bool check = false;
	if (pRoot->left != NULL && pRoot->right != NULL)
		check = true;
	else if (pRoot->left == NULL && pRoot->right == NULL)
		check = true;
	return check && IsFullTree(pRoot->left) && IsFullTree(pRoot->right);
}
bool isFullBST(NODE* pRoot) {
	return IsFullTree(pRoot) && isBST(pRoot);
 }


void main() {
	BST tree;
	//InitBST(tree);
	//cout << "Enter number of node: ";
	//int n; cin >> n;
	//for (int i = 0; i < n; ++i) {
	//	cout << "Enter value of node " << i + 1 << ": ";
	//	int x; cin >> x;
	//	InsertNode(tree.root, x);
	//}
	//cout << endl << "Count node: " << countNode(tree.root);
	//cout << endl << "Count less: " << countLess(tree.root, 15) << endl;
	////cout << endl << "Count greater: " << countGreater(tree.root, 15) << endl;
	//cout << "Inorder ";
	//LNR(tree.root);
	//cout <<endl << "Preorder ";
	//NLR(tree.root);
	//cout << endl << "Postorder ";
	//LRN(tree.root);
	int a[] = { 20, 12, 30, 7,9, 8, 65, 6, 25 ,10};
	int n = sizeof(a) / sizeof(a[0]);
	NODE* root = createTree(a, n);
	LNR(root);
	cout << endl << isBST(root);
	cout << endl << Height(root);
	cout << endl << countGreater(root, 70);
	cout << endl << countLess(root, 24);
	cout << endl << countLeaf(root) << endl;
	LevelOrder(root);
	// 9 20 10 30 7 9 8 65 6 25 
}
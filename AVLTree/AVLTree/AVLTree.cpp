#include "iostream"
using namespace std;
struct NODE {
	int key;
	NODE* pLeft;
	NODE* pRight;
	int height;
};

NODE* CreateNodeTree(int x) {
	NODE* p = new NODE;
	p->key = x;
	p->pRight = NULL;
	p->pLeft = NULL;
	p->height = 1;
	return p;
}
int Height(NODE* pRoot) {
	if (pRoot == NULL)
		return 0;
	int LeftHeight = 1 + Height(pRoot->pLeft);;
	int RightHeight = 1 + Height(pRoot->pRight);
	return max(LeftHeight, RightHeight);
}
// Get Balance factor of node N  
int getBalanceFactor(NODE* n) {
	if (n == NULL)
		return 0;
	return Height(n->pLeft) - Height(n->pRight);
}

NODE* pRightRotate(NODE*& pRoot) {
	NODE* x = pRoot->pLeft;
	NODE* T2 = x->pRight;

	// Perform rotation  
	x->pRight = pRoot;
	pRoot->pLeft = T2;

	x->height = 1 + max(Height(x->pLeft), Height(x->pRight));
	pRoot->height = 1 + max(Height(pRoot->pLeft), Height(pRoot->pRight));

	return x;
}

NODE* pLeftRotate(NODE*& pRoot) {
	NODE* x = pRoot->pRight;
	NODE* T2 = x->pLeft;

	// Perform rotation  
	x->pLeft = pRoot;
	pRoot->pRight = T2;

	x->height = 1 + max(Height(x->pLeft), Height(x->pRight));
	pRoot->height = 1 + max(Height(pRoot->pLeft), Height(pRoot->pRight));

	return x;
}

// 2. Add a node with given value x into a given AVL tree (Notify if the given value existed)
NODE* InsertNode(NODE* pRoot, int x) {
	if (pRoot == NULL) {
		return CreateNodeTree(x);
	}
	if (x < pRoot->key)
		pRoot->pLeft=InsertNode(pRoot->pLeft, x);
	else if (x > pRoot->key)
		pRoot->pRight=InsertNode(pRoot->pRight, x);
	else
		return pRoot;
	pRoot->height = 1 + max(Height(pRoot->pLeft), Height(pRoot->pRight));


	int bf = getBalanceFactor(pRoot);

	if (bf > 1) {
		if (x < pRoot->pLeft->key) // LL
			return pRightRotate(pRoot);
		if (x > pRoot->pLeft->key) { // LR
			pRoot->pLeft=pLeftRotate(pRoot->pLeft);
			return pRightRotate(pRoot);
		}
	}


	if (bf < -1) {
		if (x > pRoot->pRight->key) // RR
			return pLeftRotate(pRoot);
		if (x < pRoot->pRight->key) { // RL
			pRoot->pRight=pRightRotate(pRoot->pRight);
			return pLeftRotate(pRoot);
		}
	}
	
	// Unchange
	return pRoot;
}


// 3. Remove a node with given value x from a given AVL tree (Notify if the given value not existed):
NODE* minkeyNode(NODE* pRoot) {
	if (pRoot== NULL)
		return NULL;
	if (pRoot->pLeft == NULL)
		return pRoot;
	return minkeyNode(pRoot->pLeft);
}

NODE* Remove(NODE* pRoot, int x) {
	// base case 
	if (pRoot == NULL) {
		return NULL;
	}
	// If the key to be deleted is smaller than the root's key, 
	// then it lies in pLeft subtree 
	else if (x < pRoot->key) {
		pRoot->pLeft = Remove(pRoot->pLeft, x);
	}
	// If the key to be deleted is greater than the root's key, 
	// then it lies in pRight subtree 
	else if (x > pRoot->key) {
		pRoot->pRight = Remove(pRoot->pRight, x);
	}
	// if key is same as root's key, then This is the node to be deleted 
	else {
		// node with only one child or no child 
		if (pRoot->pLeft == NULL && pRoot->pRight == NULL)
			return NULL;
		else if (pRoot->pLeft == NULL) {
			NODE* temp = pRoot->pRight;
			delete pRoot;
			return temp;
		}
		else if (pRoot->pRight == NULL) {
			NODE* temp = pRoot->pLeft;
			delete pRoot;
			return temp;
		}
		else {
			// node with two children: Get the inorder successor (smallest 
			// in the pRight subtree) 
			NODE* temp = minkeyNode(pRoot->pRight);
			// Copy the inorder successor's content to this node 
			pRoot->key = temp->key;
			// Delete the inorder successor 
			pRoot->pRight = Remove(pRoot->pRight, temp->key);
			//deleteNode(r->pRight, temp->key); 
		}
	}

	int bf = getBalanceFactor(pRoot);
	// pLeft pLeft Imbalance/Case or pRight rotation 
	if (bf == 2) { // LL or LR
		if (getBalanceFactor(pRoot->pLeft) >= 0) // LL
			return pRightRotate(pRoot);
		// pLeft pRight Imbalance/Case or LR rotation 
		if (getBalanceFactor(pRoot->pLeft) == -1) { // LR
			pRoot->pLeft=pLeftRotate(pRoot->pLeft);
			return pRightRotate(pRoot);
		}
	}
	// pRight pRight Imbalance/Case or pLeft rotation	
	else if (bf == -2) { // RR or RL
		if (getBalanceFactor(pRoot->pRight) <= 0) // RR
			return pLeftRotate(pRoot);
		// pRight pLeft Imbalance/Case or RL rotation 
		if (getBalanceFactor(pRoot->pRight) == 1) { // RL
			pRoot->pRight=pRightRotate(pRoot->pRight); 
			return pLeftRotate(pRoot);
		}
	}

	//Unchage
	return pRoot;
}


// Pre-order Traversal
void NLR(NODE* root) {
	if (root == NULL)
		return;
	cout << root->key << " ";
	NLR(root->pLeft);
	NLR(root->pRight);
}
//  In-order Traversal

void LNR(NODE* root) {
	if (root == NULL)
		return;
	LNR(root->pLeft);
	cout << " " << root->key << " ";
	LNR(root->pRight);
}

//  Post-order Traversal
void  LRN(NODE* root) {
	if (root == NULL)
		return;
	LRN(root->pLeft);
	LRN(root->pRight);
	cout << " " << root->key << " ";
}
// 4. * Determine if a given Binary Tree is an AVL Tree:
bool isAVL(NODE* pRoot) {
	if (pRoot == NULL)
		return true;
	return abs(getBalanceFactor(pRoot)) <= 1 && isAVL(pRoot->pLeft) && isAVL(pRoot->pRight);
}
void main() {
	NODE* pRoot = NULL;
	int n = 0;
	while (n < 6) {
		int x; cin >> x;
		pRoot=InsertNode(pRoot, x);
		n++;
	}
	NLR(pRoot);
	pRoot = Remove(pRoot, 6);
	cout << endl;
	NLR(pRoot);
	if (isAVL(pRoot))
		cout << endl << "This is an AVL tree";
	else
		cout << endl << "This is not an AVL tree";
}
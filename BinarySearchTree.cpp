#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* leftChild = NULL;
	Node* rightChild = NULL;
};

class BinarySearchTree {
public:
	Node* root;

	BinarySearchTree() {
		cout << "Creating root Node" << endl;
		root = NULL;
	}

	Node* insert(int key, Node* t) {
		if (t == NULL) {
			t = new Node;
			t->data = key;
			t->leftChild = NULL;
			t->rightChild = NULL;
		}
		else if (key < t->data) {
			t->leftChild = insert(key, t->leftChild);
		}
		else if (key > t->data) {
			t->rightChild = insert(key, t->rightChild);
		}
		return t;
	}

	void inorder(Node* t) {
		if (t == NULL) {
			return;
		}
		inorder(t->leftChild);
		cout << t->data << " ";
		inorder(t->rightChild);
	}

	void preorder(Node* t) {
		// method not tested in main, some slight issues that are being worked through
		cout << t->data << " ";
		preorder(t->leftChild);
		preorder(t->rightChild);
	}

	void postorder(Node* t) {
		// method not tested in main, some slight issues that are being worked through
		postorder(t->leftChild);
		postorder(t->rightChild);
		cout << t->data << " ";
	}

	void insert(int x) {
		cout << "Inside insert Node function" << endl;
		root = insert(x, root);
	}
	void search(int x, Node* t) {
		cout << "Inside search function" << endl;
		if (x == t->data) {
			cout << "Data found" << endl;
		}
		else if ((x < t->data) && t->leftChild != NULL){
			search(x, t->leftChild);
		}
		else if ((x > t->data) && t->rightChild != NULL) {
			search(x, t->rightChild);
		}
	}
	void remove(int x, Node* t) {
		cout << "Inside the remove function" << endl;
		if (x < t->data) {
			if (x == t->leftChild->data && t->leftChild->leftChild == NULL && t->leftChild->rightChild == NULL) {
				cout << "Deleting Leaf Node" << endl;
				delete t->leftChild;
				t->leftChild = NULL;
				return;
			}
			else if (x == t->leftChild->data) {
				if (t->leftChild->leftChild != NULL && t->leftChild->rightChild == NULL) {
					cout << "When left child not null" << endl;
					Node* temp = t->leftChild->leftChild;
					delete t->leftChild;
					t->leftChild = temp;
					return;
				}
				else if (t->leftChild->leftChild == NULL && t->leftChild->rightChild != NULL) {
					cout << "When right child is not null" << endl;
					Node* temp = t->leftChild->rightChild;
					delete t->leftChild;
					t->leftChild = temp;
					return;
				}
				else if (t->leftChild->leftChild != NULL && t->leftChild->rightChild != NULL) {
					cout << "Both children are present in left tree" << endl;
					Node* temp = t->leftChild->rightChild;
					delete t->leftChild;
					t->leftChild = temp;
				}
			}
			remove(x, t->leftChild);
		}
		else if (x > t->data) {
			if (x == t->rightChild->data && t->rightChild->leftChild == NULL && t->rightChild->rightChild == NULL) {
				cout << "deleting leaf" << endl;
				delete t->rightChild;
				t->rightChild = NULL;
				return;
			}
			else if (x == t->rightChild->data) {
				if (t->rightChild->leftChild != NULL && t->rightChild->rightChild == NULL) {
					cout << "When left child is not null" << endl;
					Node* temp = t->rightChild->leftChild;
					delete t->rightChild;
					t->rightChild = temp;
					return;
				}
				else if (t->rightChild->leftChild == NULL && t->rightChild->rightChild != NULL) {
					cout << "When right child is not null" << endl;
					Node* temp = t->rightChild->rightChild;
					delete t->rightChild;
					t->rightChild = temp;
					return;
				}
				else if (t->rightChild->leftChild != NULL && t->rightChild->rightChild != NULL) {
					cout << "Both children are present in the right tree" << endl;
				}
			}
			remove(x, t->rightChild);
		}
	}

	void display_inorder() {
		cout << "Inside inorder display" << endl;
		inorder(root);
		cout << endl;
	}
	void display_preorder() {
		// preorder method does not work at this moment
		cout << "Inside preorder display" << endl;
		preorder(root);
		cout << endl;
	}
	void display_postorder() {
		// postorder method does not work at this moment
		cout << "Inside postorder display" << endl;
		postorder(root);
		cout << endl;
	}
};

int main() {

	BinarySearchTree tree;
	tree.insert(20);
	tree.insert(32);
	tree.insert(14);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	tree.insert(12);
	tree.insert(28);
	tree.insert(39);
	tree.insert(50);
	tree.display_inorder();
	tree.remove(7, tree.root);
	tree.display_inorder();
	tree.search(20, tree.root);
	tree.search(50, tree.root);
	tree.remove(50, tree.root);
	tree.display_inorder();

	return 0;
}
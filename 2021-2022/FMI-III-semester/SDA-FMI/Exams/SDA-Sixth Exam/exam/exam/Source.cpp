#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;


struct Node{
	int data;
	 Node* left;
	 Node* right;
};

Node* newNode(int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->right = temp->left = NULL;
	return temp;
}

Node* Insert(Node* node, int key) {
	if (node == nullptr) {
		return newNode(key);
	}
	if (key < node->data) {
		node->left = Insert(node->left, key);
	}
	else if (key > node->data) {
		node->right = Insert(node->right, key);
	}
	return node;
}


void find(Node* root, int level, int& maxLevel, int& res){
	if (root != NULL){
		find(root->left, ++level, maxLevel, res);
		if (level > maxLevel){
			res = root->data;
			maxLevel = level;
		}
		find(root->right, level, maxLevel, res);
	}
}

// Returns value of deepest node 
int deepestNode(Node* root){
	int res = -1;
	int maxLevel = -1;

	find(root, 0, maxLevel, res);

	return res;
}

Node* minValueNode(Node* node) {
	Node* current = node;
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

Node* deleteNode(Node* root, int key)
{
	// base case
	if (root == NULL)
		return root;
	if (key < root->data)
		root->left = deleteNode(root->left, key);
	else if (key > root->data)
		root->right = deleteNode(root->right, key);
	else {
		if (root->left == NULL) {
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			Node* temp = root->left;
			free(root);
			return temp;
		}
		Node* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}
void inorder(Node* temp){
	if (temp == NULL)
		return;

	inorder(temp->left);
	cout << temp->data << ' ';
	inorder(temp->right);
}


int main(){

	int n;
	int key;
	cin >>n;
	Node* root = nullptr;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		root = Insert(root, input);
	}
	for (int i = 0; i < n; i++){
		key = deepestNode(root);
		deleteNode(root, key);
	}
	inorder(root);

	return 0;
}



//void modifiedLevelOrder(struct Node* node){
//	
//	if (node == NULL)
//		return;
//
//	if (node->left == NULL && node->right == NULL){
//		cout << node->data;
//		return;
//	}
//
//	queue<Node*> myQueue;
//	stack<Node*> myStack;
//
//	struct Node* temp = NULL;
//	int size;
//	int changeDiraction = 0;
//	bool rightToLeft = false;
//
//	myQueue.push(node);
// 
//	while (!myQueue.empty()){
//		changeDiraction++;
//
//		size = myQueue.size();
//
//		for (int i = 0; i < size; i++){
//			temp = myQueue.front();
//			myQueue.pop();
//
//			if (rightToLeft == false) {
//				cout << temp->data << " ";
//			}else {
//				myStack.push(temp);
//			}
//			if (temp->left) {
//				myQueue.push(temp->left);
//			}
//			if (temp->right) {
//				myQueue.push(temp->right);
//			}
//		}
//		if (rightToLeft == true){
//			while (!myStack.empty()){
//				temp = myStack.top();
//				myStack.pop();
//
//				cout << temp->data << " ";
//			}
//		}
//		if (changeDiraction == 1){
//			rightToLeft = !rightToLeft;
//			changeDiraction = 0;
//		}
//	}
//}
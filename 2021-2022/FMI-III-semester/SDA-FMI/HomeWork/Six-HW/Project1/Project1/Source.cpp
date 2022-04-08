#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
	int data;
	struct Node* left, * right;
};

Node* newNode(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->right = temp->left = NULL;
	return temp;
}

Node* Insert(Node* node, int key) {
	if (node==nullptr){
		return newNode(key);
	}
	if (key< node->data){
		node->left = Insert(node->left, key);
	}else if (key > node->data) {
		node->right = Insert(node->right, key);
	}
	return node;
}

int KthLargestBST(Node *root, int K){
	Node* current = root;
	Node* KthLargest = nullptr;
	int count = 0;
		while (current != NULL){
			if (current->right == NULL){
				count = count + 1;
				if (count == K)
					KthLargest = current;
				current = current->left;
			}	else{
				Node *successor = current->right;
				while (successor->left != NULL && successor->left != current)
					successor = successor->left;
						if (successor->left == NULL){
							successor->left = current;
							current = current->right;
						}
						else{
							successor->left = NULL;
							count = count + 1;
								if (count == K)
								KthLargest = current;
								current = current->left;
						}
			}
		}
		return KthLargest->data;
}

Node* minValueNode( Node* node){
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


void printLevelOrder(Node* root){
	
	if (root == NULL) return; 
	queue<Node*> q; 
	q.push(root);

	while (q.empty() == false){
		int nodeCount = q.size();

		while (nodeCount > 0){
			Node* node = q.front();
			cout << node->data << " ";
			q.pop();
			if (node->left != NULL)
				q.push(node->left);
			if (node->right != NULL)
				q.push(node->right);
			nodeCount--;
		}
	}
}



int main() {
	
	int a, b;

	cin >> a >> b;
	Node* root = nullptr;
	for (int i = 0; i < a; i++){
		int input;
		cin >> input;
		root = Insert(root, input);	
	}
	root = deleteNode(root, KthLargestBST(root, b));
	printLevelOrder(root);

	return 0;
}

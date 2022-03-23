//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//
//class Node
//{
//public:
//	int data;
//	Node* left;
//	Node* right;
//	int height;
//};
// 
//int max(int a, int b); 
//int height(Node* N){
//	if (N == nullptr) { return 0; }
//	return N->height;
//}
//int max(int a, int b){return (a > b) ? a : b;}
//
//
//Node* newNode(int data){
//
//	Node* node = new Node();
//	node->data = data;
//	node->left = NULL;
//	node->right = NULL;
//	node->height = 1; // new node is initially 
//					  // added at leaf  
//	return(node);
//}
//
//Node* right_To_Rotate(Node* data){
//	Node* x = data->left;
//	Node* T2 = x->right;
//
//	// Rotate
//	x->right = data;
//	data->left = T2;
//	// Update heights  
//	data->height = max(height(data->left), height(data->right)) + 1;
//	x->height = max(height(x->left),height(x->right)) + 1;
//	// Return new root  
//	return x;
//}
//
//Node* left_To_Rotate(Node* data){
//	Node* y = data->right;
//	Node* T2 = y->left;
//
//	// Perform rotation  
//	y->left = data;
//	data->right = T2;
//
//	// Update heights  
//	data->height = max(height(data->left),height(data->right)) + 1;
//	y->height = max(height(y->left),height(y->right)) + 1;
//
//	// Return new root  
//	return y;
//}
//
//// Blance of Node 
//int getBalance(Node* node){
//	if (node == NULL){ return 0; }
//	return height(node->left) - height(node->right);
//}
//
//Node* insert(Node* node, int data)
//{
//	//Rotate
//	if (node == NULL){ return(newNode(data)); }
//		
//	if (data < node->data) {
//		node->left = insert(node->left, data);
//	}else if (data > node->data) {
//		node->right = insert(node->right, data);
//	}else{return node;} // No equal nodes
//		
//	//Update height of grandfather
//	node->height = 1 + max(height(node->left),height(node->right));
//	//Check if node is unbalanced
//	int balance = getBalance(node);
//
//	// Left Left Case  
//	if (balance > 1 && data < node->left->data) { return right_To_Rotate(node); }
//
//	// Right Right Case  
//	if (balance < -1 && data > node->right->data) { return left_To_Rotate(node); }
//		
//
//	// Left Right Case  
//	if (balance > 1 && data > node->left->data){
//		node->left = left_To_Rotate(node->left);
//		return right_To_Rotate(node);
//	}
//
//	// Right Left Case  
//	if (balance < -1 && data < node->right->data){
//		node->right = right_To_Rotate(node->right);
//		return left_To_Rotate(node);
//	}
//
//	/* return the (unchanged) node pointer */
//	return node;
//}
//
//Node* minValueNode(Node* node){
//	Node* current = node;
//
//	/* loop down to find the leftmost leaf */
//	while (current->left != NULL){ current = current->left; }
//	return current;
//}
// 
//Node* deleteNode(Node* root, int data)
//{
//	if (root == NULL) { return root; }
//
//
//	if (data < root->data) {
//		root->left = deleteNode(root->left, data);
//
//	}
//	else if (data > root->data) {
//		root->right = deleteNode(root->right, data);
//	} else{
//		if ((root->left == nullptr) || (root->right == nullptr)){
//			Node* temp = root->left ? root->left : root->right;
//			// No child case  
//			if (temp == nullptr){
//				temp = root;
//				root = nullptr;
//			}else {
//				*root = *temp;
//			} 
//			free(temp);
//		}else{ 
//			Node* temp = minValueNode(root->right);
//			root->data = temp->data; 
//			root->right = deleteNode(root->right,temp->data);
//		}
//	}
//
//	if (root == nullptr)
//		return root;
//
//	// Update hight
//	root->height = 1 + max(height(root->left),height(root->right));
//
//	//Get balance, check unbalance
//	int balance = getBalance(root);
//
//	// Left To Left Case  
//	if (balance > 1 && getBalance(root->left) >= 0)
//		return right_To_Rotate(root);
//
//	// Left To Right  
//	if (balance > 1 && getBalance(root->left) < 0){
//		root->left = left_To_Rotate(root->left);
//		return right_To_Rotate(root);
//	}
//
//	// Right To Right   
//	if (balance < -1 && getBalance(root->right) <= 0)
//		return left_To_Rotate(root);
//
//	// Right To Left Case  
//	if (balance < -1 && getBalance(root->right) > 0){
//		root->right = right_To_Rotate(root->right);
//		return left_To_Rotate(root);
//	}
//
//	return root;
//}
//void inOrder(Node* node) {
//	if (node == nullptr) {
//		return;
//	}
//	inOrder(node->left);
//	cout << ("%s ", node->data) << " ";
//	inOrder(node->right);
//}
//
//int main() {
//	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
//	Node* root = nullptr;
//
//	int n;
//	cin >> n;
//
//	string add = "add";
//	string inorder = "inorder";
//	string del = "del";
//	string StringNumber;
//
//	for (int i = 0; i <= n; i++) {
//		string command;
//		getline(cin, command);
//
//		
//		int number = 0;
//		int choice = 0;
//
//		if (inorder == command.substr(0, 7)) {
//			choice = 1;
//		}
//		if (add == command.substr(0, 3)) {
//			choice = 2;
//			StringNumber = command.substr(4);
//			number = stoi(StringNumber);
//
//		}
//		if (del == command.substr(0, 3)) {
//			choice = 3;
//			StringNumber = command.substr(4);
//			number = stoi(StringNumber);
//		}
//
//		switch (choice) {
//		case 1:
//			inOrder(root);
//			cout << endl;
//			break;
//		case 2:
//			root = insert(root, number);
//			break;
//		case 3:
//			root = deleteNode(root, number);
//			break;
//		}
//	}
//	return 0;
//}


#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a, b, result = 0;

	result = min(max(2, 3), 6);
	cout << result;
}
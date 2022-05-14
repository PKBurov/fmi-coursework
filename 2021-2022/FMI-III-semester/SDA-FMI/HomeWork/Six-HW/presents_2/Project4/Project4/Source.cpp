#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
	int key;
	vector<Node*> nodes;
};
Node tree[1000000];

int TreeHight(Node* root) {
	int res = root->nodes.size();
	for (int i = 0; i < (int)root->nodes.size(); i++) {
		res += TreeHight(root->nodes[i]);
	}
	return res;
}

void ConstructTree(int node, int value) {
	tree[node].key = node;
	tree[node].nodes.push_back(&tree[value]);
	tree[value].key = value;
}

void Inorder(Node* root) {
	cout << TreeHight(root) << " ";
	for (int i = 0; i < root->nodes.size(); i++) {
		Inorder(root->nodes[i]);
	}
}

int getTreesHeight(Node* root) {
	int max = 0;
	for (int i = 0; i < root->nodes.size(); i++) {
		int height = getTreesHeight(root->nodes[i]);
		if (height > max)
			max = height;
	}
	return max + 1;
}

void PrintTLevel(struct Node* root, int level) {
	if (root == NULL)
		return;
	if (level == true) {
		cout << TreeHight(root) << " ";
	}
	else if (level > true) {
		for (int i = 0; i < root->nodes.size(); i++) {
			PrintTLevel(root->nodes[i], level - 1);
		}
	}
}
void printAllTLevls(Node* root) {
	int height = getTreesHeight(root);
	for (int i = 1; i <= height; i++) {
		PrintTLevel(root, i);
	}
}
int n, node, value;
void Input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> node >> value;
		ConstructTree(node, value);
	}
}
void Result() {
	const int ConstVal = 0;
	printAllTLevls(&tree[ConstVal]);
}

int main(){

	Input();
	Result();
	
	/*int n = 0;

	cin >> n;
	for (int i = 0; i < n-1; i++){
		int node, value = 0;
		cin >> node >> value;
		ConstructTree(node, value);
	}
	printAllTLevls(&tree[0]);*/
	return 0;
}


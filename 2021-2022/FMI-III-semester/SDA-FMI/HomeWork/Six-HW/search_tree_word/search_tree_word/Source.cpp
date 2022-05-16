#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int WORD_SIZE = 10;
struct Node{
	struct Node* children[WORD_SIZE];
	bool isEndOfWord;
};

Node* getNode(void){
	Node* pNode = new Node;
	pNode->isEndOfWord = false;

	for (int i = 0; i < WORD_SIZE; i++) {
		pNode->children[i] = nullptr;
	}
	return pNode;
}

void insert(struct Node* root, string key){
	 Node* pCrawl = root;

	for (int i = 0; i < key.length(); i++){
		int index = key[i] - 'a';
		if (!pCrawl->children[index]) {
			pCrawl->children[index] = getNode();
		}
		pCrawl = pCrawl->children[index];
	}
	pCrawl->isEndOfWord = true;
}

bool search(struct Node* root, string key){
	 Node* pCrawl = root;

	for (int i = 0; i < key.length(); i++){
		int index = key[i] - 'a';
		if (!pCrawl->children[index]) {
			return false;
		}
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main()
{

	int n,q;
	cin >> n;
	string* keys = new string[n];
	struct Node* root = getNode();

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		insert(root, input);
	}
	cin >> q;
	for (int i = 0; i < q; i++){
		string input;
		cin >> input;
		search(root, input) ? cout << "YES\n" :
			cout << "NO\n";
	}

	delete[] keys;
	return 0;
}
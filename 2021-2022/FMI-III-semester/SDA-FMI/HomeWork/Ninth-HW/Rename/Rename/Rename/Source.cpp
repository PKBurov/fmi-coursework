

//#include<iostream>
//#include<vector>
//#include<set>
//
//using namespace std;
//typedef long long int lli;
//
//int main()
//{
//	int n, s, t;
//	cin >> n >> t >> s;
//
//	int m;
//	vector<int> vv;
//	cin >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int x;
//		cin >> x;
//		vv.push_back(x);
//	}
//	int ans = (n + 1) / (s + 1);
//	set<int> v;
//	v.insert(0);
//	v.insert(n + 1);
//
//	set<int>::iterator it1, it2;
//	// cout<<" ini "<<ans<<endl;
//	for (int i = 0; i < m; i++){
//		int pos;
//		pos = vv[i];
//		it1 = v.lower_bound(pos);
//		it2 = v.lower_bound(pos);
//		it2--;
//		// cout<<*it2<<" "<<*it1<<endl;
//
//		int gap = (*it1 - *it2 - 1);
//		//  cout<<" gap "<<gap<<endl;
//
//		ans -= ((gap + 1) / (s + 1));
//		ans += (pos - *it2) / (s + 1);
//		ans += (*it1 - pos) / (s + 1);
//		// cout<<" new ans "<<ans<<endl;
//		if (ans < t){
//			cout << i + 1 << endl;
//			exit(0);
//		}
//		v.insert(pos);
//	}
//	cout << "-1" << endl;
//}



//
#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main()
{
	vector<int> vec;
	set<int> Set;
	Set.insert(0);
	set<int>::iterator iter1, iter2;
	int answ = 0;
	int space = 0; 
	int position = 0;

	int battleshipCells, numberOfShips, lenghtOfShips, amountOfShots;
	cin >> battleshipCells >> lenghtOfShips  >> numberOfShips >> amountOfShots;

	for (int i = 0; i < amountOfShots; i++) {
		int input;
		cin >> input;
		vec.push_back(input);
	}
	answ = (battleshipCells + 1) / (numberOfShips + 1);
	Set.insert(battleshipCells + 1);
	for (int i = 0; i < amountOfShots; i++) {
		position = vec[i];
		iter1 = Set.lower_bound(position);
		iter2 = Set.lower_bound(position);
		iter2--;

		space = (*iter1 - *iter2 - 1);

		answ -= ((space + 1) / (numberOfShips + 1));
		answ += (position - *iter2) / (numberOfShips + 1);
		answ += (*iter1 - position) / (numberOfShips + 1);
		if (answ < lenghtOfShips) {cout << i + 1 << endl;exit(1);}
		Set.insert(position);
	}
	cout << "-1" << endl;
}
//int main()
//{
//	vector<int> vec;
//	set<int> Set;
//	Set.insert(0);
//	int ans = 0;
//	int gap = 0;
//	int pos = 0;
//
//	set<int>::iterator it1, it2;
//	int battleshipCells, numberOfShips, lenghtOfShips, amountOfShots;
//	cin >> battleshipCells >> numberOfShips >> lenghtOfShips >> amountOfShots;
//
//	for (int i = 0; i < amountOfShots; i++) {
//		int x;
//		cin >> x;
//		vec.push_back(x);
//	}
//	ans = (battleshipCells + 1) / (lenghtOfShips + 1);
//
//	Set.insert(battleshipCells + 1);
//
//	for (int i = 0; i < amountOfShots; i++) {
//		int pos;
//		pos = vec[i];
//		it1 = Set.lower_bound(pos);
//		it2 = Set.lower_bound(pos);
//		it2--;
//		 cout<<*it2<<" "<<*it1<<endl;
//
//		gap = (*it1 - *it2 - 1);
//		  cout<<" gap "<<gap<<endl;
//
//		ans -= ((gap + 1) / (lenghtOfShips + 1));
//		ans += (pos - *it2) / (lenghtOfShips + 1);
//		ans += (*it1 - pos) / (lenghtOfShips + 1);
//		 cout<<" new ans "<<ans<<endl;
//		if (ans < numberOfShips) {
//			cout << i + 1 << endl;
//			exit(0);
//		}
//		Set.insert(pos);
//	}
//	cout << "-1" << endl;
//}


//
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <unordered_map>
//#include<map>
//
//using namespace std;
//
//int main() {
//	int n, answ = 0;
//	scanf_s("%d", &n);
//
//	vector<int> keys(n);
//	vector<int> doors(n);
//	map<int, int> Chain;
//	int N = n - 1;
//	for (int i = 0; i < N; i++) { scanf_s("%d", &keys[i]); }
//	for (int i = 0; i < N; i++) { scanf_s("%d", &doors[i]);}
//	for (int i = 0; i < N; i++) {
//		Chain[keys[i]]++; // collect key
//		if (Chain.count(doors[i])) {
//			if (Chain[doors[i]]) {
//				Chain[doors[i]]--;
//			}else {answ++;}
//		}else {
//			answ++;
//		}
//	}
//	return printf("%d", answ), 0;
//}



//#include <vector>
//#include <unordered_map>
//using namespace std;
//typedef vector<int> vi;
//
//#define f(i, n) for(i=0;i<n-1;++i)
//#define s(a) scanf_s("%d", &a)
//
//int main() {
//	int n, i, r, c = 0;
//	s(n);
//	vi keys(n), doors(n);
//	unordered_map<int, int> keyChain;
//	f(i, n) s(keys[i]);
//	f(i, n) s(doors[i]);
//	f(i, n) {
//		keyChain[keys[i]]++; // collect key
//		if (keyChain.count(doors[i])) {
//			if (keyChain[doors[i]]) keyChain[doors[i]]--;
//			else c++;
//		}
//		else c++;
//	}
//	return printf("%d", c), 0;
//}

////////////////////////Елитизъм

//#include <string>
//#include <sstream>
//#include <map>
//#include <iostream>
//#include <queue>
//#include <vector>
//
//using namespace std;
//int main() {
//	priority_queue<int, vector<int>, greater<int>> minHeap;
//	priority_queue<int> maxHeap;
//	int N, a;
//
//	scanf_s("%d", &N);
//	while (N--) {
//		scanf_s("%d", &a);
//		maxHeap.push(a);
//		if (maxHeap.size() > minHeap.size() + 1)
//			minHeap.push(maxHeap.top()), maxHeap.pop();
//		else if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
//			maxHeap.push(minHeap.top()), minHeap.pop();
//			minHeap.push(maxHeap.top()), maxHeap.pop();
//		}
//		if (maxHeap.size() > minHeap.size())
//			printf("%d.0\n", maxHeap.top());
//		else {
//			a = maxHeap.top() + minHeap.top();
//			printf("%d.%d\n", a / 2, (a & 1) ? 5 : 0);
//		}
//	}
//	return 0;
//}



//#include <string>
//#include <sstream>
//#include <map>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//#define MAX 256 
//
//// Maximum length of an input word 
//#define MAX_WORD_LEN 500 
//
//// Trie Node. 
//struct trieNode
//{
//	struct trieNode* child[MAX];
//	int freq;  // To store frequency 
//};
//
//// Function to create a new trie node. 
//struct trieNode* newTrieNode(void)
//{
//	struct trieNode* newNode = new trieNode;
//	newNode->freq = 1;
//	for (int i = 0; i < MAX; i++)
//		newNode->child[i] = NULL;
//	return newNode;
//}
//
//// Method to insert a new string into Trie 
//void insert(struct trieNode* root, string str)
//{
//	// Length of the URL 
//	int len = str.length();
//	struct trieNode* pCrawl = root;
//
//	// Traversing over the length of given str. 
//	for (int level = 0; level < len; level++)
//	{
//		// Get index of child node from current character 
//		// in str. 
//		int index = str[level];
//
//		// Create a new child if not exist already 
//		if (!pCrawl->child[index])
//			pCrawl->child[index] = newTrieNode();
//		else
//			(pCrawl->child[index]->freq)++;
//
//		// Move to the child 
//		pCrawl = pCrawl->child[index];
//	}
//}
//
//// This function prints unique prefix for every word stored 
//// in Trie. Prefixes one by one are stored in prefix[]. 
//// 'ind' is current index of prefix[] 
//void findPrefixesUtil(struct trieNode* root, char prefix[],
//	int ind)
//{
//	// Corner case 
//	if (root == NULL)
//		return;
//
//	// Base case 
//	if (root->freq == 1)
//	{
//		prefix[ind] = '\0';
//		cout << prefix << " ";
//		return;
//	}
//
//	for (int i = 0; i < MAX; i++)
//	{
//		if (root->child[i] != NULL)
//		{
//			prefix[ind] = i;
//			findPrefixesUtil(root->child[i], prefix, ind + 1);
//		}
//	}
//}
//
//// Function to print all prefixes that uniquely 
//// represent all words in arr[0..n-1] 
//void findPrefixes(string arr[], int n)
//{
//	// Construct a Trie of all words 
//	struct trieNode* root = newTrieNode();
//	root->freq = 0;
//	for (int i = 0; i < n; i++)
//		insert(root, arr[i]);
//
//	// Create an array to store all prefixes 
//	char prefix[MAX_WORD_LEN];
//
//	// Print all prefixes using Trie Traversal 
//	findPrefixesUtil(root, prefix, 0);
//}
//
//// Driver function. 
//int main()
//{
//	string arr[] = { "alexander", "alina", "georgi"};
//	int n = sizeof(arr) / sizeof(arr[0]);
//	findPrefixes(arr, n);
//
//	return 0;
//}


/// 2 Ra

//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#include <string>
//#include <unordered_set>
//using namespace std;
//
//// Returns largest subarray with equal number of 0s and 1s
//
//int maxLen(vector<int>arr){
//	
//	unordered_map<int, int> map;
//	int n = arr.size();
//	int sum = 0;
//	int max_len = 0;
//	int ending_index = -1;
//
//	for (int i = 0; i < n; i++){ arr[i] = (arr[i] == 0) ? -1 : 1; }
//	
//	for (int i = 0; i < n; i++) {
//		sum += arr[i];
//		if (sum == 0) { max_len = i + 1; ending_index = i; }
//		if (map.find(sum + n) != map.end()) {
//			if (max_len < i - map[sum + n]) {
//				max_len = i - map[sum + n];
//				ending_index = i;
//			}
//		}
//		else { map[sum + n] = i; }
//	}
//	for (int i = 0; i < n; i++){ arr[i] = (arr[i] == -1) ? 0 : 1; }
//	int a = ending_index - max_len + 1;
//	int b = ending_index;
//	int result = 1;
//	while (a!=b){
//		result++;
//		a++;
//	}
//	printf("%d", result);
//	return max_len;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>arr(n);
//	for (int i = 0; i < n; i++){
//		int input;
//		cin >> input;
//		arr[i] = input;
//	}
//	maxLen(arr);
//	return 0;
//}



//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <set>
//#include <map>
//#include<string>
//
//#define f(i, n) for(i=0; i < n; ++i)
//#define Set set<string>
//#define Map map<string,int>
//#define Str string
//
//using namespace std;
//
//int main() {
//	int n = 0;
//	int j = 0;
//	int i = 0;
//	cin >> n;
//	Set set;
//	Map map;
//	Str que, tmp;
//
//	f(i,n){
//		cin >> que;
//		bool temp = false;
//		f(j,que.size()) {
//			tmp += que[j];
//			if (set.count(tmp) == 0 && temp == false) {
//				cout << tmp << "\n";
//				temp = true;
//			}
//			set.insert(tmp);
//		}
//		if (map.count(que) == 0) {
//			if (temp == false) { cout << que << "\n"; }
//			map[que] = 1;
//		}else {
//			map[que]++;  
//			cout << que<< " " << map[que] << endl;
//		}
//	}
//
//}



//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <set>
//#include <map>
//#include <string>
//#define Set set<string>
//#define Map map<string,int>
//#define Str string
//using namespace std;
//int main() {
//	int n = 0;
//	cin >> n;
//
//	Set set;
//	Map map;
//	Str que;
//	Str tmp;
//
//	for (auto i = 0; i < n; i++) {
//		cin >> que;
//		bool temp = false;
//		for (int j = 0; j < que.size(); j++) {
//			tmp += que[j];
//			if (set.count(tmp) == 0 && temp == false) {
//				// printf ("%s \n",tmp.c_str());
//				cout << tmp << "\n";
//				temp = true;
//			}
//			set.insert(tmp);
//		}
//		if (map.count(que) == 0) {
//			if (temp == false)
//				//printf ("%s \n",q.c_str());
//				cout << que << "\n";
//			map[que] = 1;
//		}
//		else {
//			map[que]++;
//			//printf ("%s",q.c_str());  
//			cout << que << " " << map[que] << endl;
//		}
//	}
//
//}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
#include<map>
using namespace std;
class Node
{
public:
	int left;
	int right;
	int temp;
	int data;
	Node(int data, int left, int right) : data(data), right(right), left(left) {}
};
vector<Node> vec;

void ViewFromTop(Node root){
	if (root.data == -1)  return;
	queue<Node>que;
	map<int, int> map;

	int temp = 0;
	root.temp = temp;

	que.push(root);

	while (que.size()==true){
		temp = root.temp;
		if (map.count(temp) == 0) map[temp] = root.data;
		if (root.left != -1){
			vec[root.left].temp = temp - 1;
			que.push(vec[root.left]);
		}
		if (root.right != -1){
			vec[root.right].temp = temp + 1;
			que.push(vec[root.right]);
		}
		que.pop();
		root = que.front();
	}

	for (auto i = map.begin(); i != map.end(); i++)
	{
		cout << i->second << " ";
	}

}
//int n, x, y;
//int Result() {
//	
//	int const ConstVal = 0;
//	ViewFromTop(vec[ConstVal]);
//}
//int Input() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> x >> y;
//		Node curr(i, x, y);
//		vec.push_back(curr);
//	}
//}
int constVal = 0;
int main() {
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		Node point(i, x, y);
		vec.push_back(point);
	}
	ViewFromTop(vec[constVal]);
	return 0;
}




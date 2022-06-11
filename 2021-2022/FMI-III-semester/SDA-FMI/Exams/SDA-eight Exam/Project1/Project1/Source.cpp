#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>


using namespace std;

struct Node {
	int x;
	int l;

	Node(int x = 0, int l = 0) : x(x), l(l) {}
	bool operator()(const Node& first, const Node& second) const {
		if (first.x == second.x)
			return first.l > second.l;
		else
			return first.x < second.x;
	}
};



int main() {
	auto n = 0, q = 0;
	auto s = 0, temp = 0;
	auto counter = 0;
	cin >> n >> q;
	vector<Node> vec;
	queue<int> queue;
	for (auto i = 0; i < n; i++) {
		cin >> s;
		cin >> temp;
		vec.emplace_back(s, 1);
		vec.emplace_back(temp, -1);
	}

	for (auto j = 0; j < q; ++j) {
		cin >> s;
		vec.emplace_back(s);
		queue.push(s);
	}

	sort(vec.begin(), vec.end(), Node());

	map<int, int> a;

	int size = vec.size();
	for (auto i = 0; i < size; ++i) {
		counter += vec[i].l;
		if (!vec[i].l)
			a[vec[i].x] = counter;
	}

	while (!queue.empty()) {
		cout << a[queue.front()] << " ";
		queue.pop();
	}

	return 0;
}




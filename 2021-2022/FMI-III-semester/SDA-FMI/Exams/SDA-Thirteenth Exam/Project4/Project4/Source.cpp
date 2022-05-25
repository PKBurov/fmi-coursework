//#include <iostream>
//#include <vector>
//#include <queue>
//#include <set>
//using namespace std;
//
//vector<set<int>> adj;
//queue<int> que;
//vector<int> flagged;
//
//
//int main() {
//	int N, M, a, b, 
//	int ress = 0;
//	scanf("%d", &N);
//	scanf("%d", &M);
//
//	adj.assign(101, set<int>());
//	flagged.assign(101, 0);
//
//	for (int i = 0; i < M; i++) {
//		scanf("%d", &a);
//		scanf("%d", &b);
//		adj[a].insert(b);
//		adj[b].insert(a);
//	}
//	for (int i = 1; i <= N; i++) {
//		if (adj[i].size() < 2) que.push(i);
//	}
//
//	while (!que.empty()) {
//		a = que.front();
//		que.pop();
//
//		if (adj[a].size() >= 1) {
//
//			b = *adj[a].begin();
//			adj[b].erase(a);
//
//			if (adj[b].size() < 2) que.push(b);
//
//			if (flagged[a]) ress++;
//			else flagged[b] ^= 1;
//		}
//	}
//
//	cout << ress << endl;
//	return 0;
//}
//

//#include <iostream>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//#include <list>
//#define max_int 100000
//#define f(i,n) for(int i=0; i<n ;i++)
//
//using namespace std;
//vector<bool> flaged;
//vector<list<int>> add;
//
//void DFS(int z, bool& cycle) {
//
//	if (flaged[z]) {
//		cycle = true;
//		return;
//	}
//	flaged[z] = true;
//	for (const auto& z : add[z]) {
//		DFS(z, cycle);
//	}
//	flaged[z] = false;
//}
//
//int main() {
//	int N, V, E, xi, yi, wi;
//	cin >> N;
//	while (N--) {
//		bool cyl(false);
//		cin >> V >> E;
//		add.assign(V, list<int>());
//		flaged.assign(V, 0);
//		while (E--) {
//			cin >> xi;
//			cin >> yi;
//			cin >> wi;
//			--xi;
//			--yi;
//			add[xi].push_back(yi);
//		}
//		f(i, V) { DFS(i, cyl); }
//		if (cyl != true) {
//			cout << "0" << "\t";
//		}else {
//			cout << "1" << "\t";
//		}
//	}
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <set>
//#include <algorithm>
//
//using namespace std;
//
//
//
//vector<pair<int, int>> edges;
//vector<int> vec;
//
//int discover(int a) {
//	if (vec[a] == a) { return a; }
//	return vec[a] = discover(vec[a]);
//}
//int main() {
//	int n, m, v1, v2, ques, input;
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> m;
//	vec.resize(n + 1);
//
//	for (int i = 0; i < m; ++i) {
//		cin >> v1 >> v2;
//		edges.emplace_back(v1, v2);
//	}
//	for (int i = 0; i < n; ++i) { vec[i] = i; }
//	for (int i = 0; i < m; ++i) {
//		int t1 = discover(edges[i].first);
//		int t2 = discover(edges[i].second);
//		if (t1 != t2) {
//			vec[t2] = t1;
//		}
//	}
//	cin >> ques;
//	for (int i = 0; i < ques; ++i) {
//		cin >> input >> v1 >> v2;
//		if (input == 1) {
//			if (discover(v1) == discover(v2)) {
//				cout << "1";
//			}
//			else {
//				cout << "0";
//			}
//		}
//		else {
//			int t3 = discover(v1);
//			int t4 = discover(v2);
//			if (t4 != t3) {
//				vec[t4] = t3;
//			}
//		}
//	}
//}
//
//

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#define SIZE (int)1e7
//using namespace std;
//struct leaf { int depth; int par; };
//leaf subSet[SIZE];
//int n, m, c, d;
//int find(int v) { if (v == subSet[v].par) return v; return v = find(subSet[v].par); }
//int djt(int v1, int v2) {
//	if (subSet[v1].depth < subSet[v2].depth) swap(v1, v2);
//	subSet[v2].par = v1;
//	subSet[v1].depth += subSet[v2].depth;
//	return subSet[v1].depth;
//}
//int check(int n) {
//	if (n == 1) {
//		cout << "0" << endl;
//		return 0;
//	}
//	return 0;
//}
//int input(int a) {
//	for (int i = 1; i <= a; i++) {
//		subSet[i].par = i;
//		subSet[i].depth = 1;
//	}
//	return 0;
//}
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin >> n >> m;
//	input(n);
//	check(n);
//	for (int i = 1; i <= m; i++) {
//		cin >> c >> d;
//		int r1 = find(c), r2 = find(d);
//		if (r1 != r2) {
//			if (djt(r1, r2) == n) {
//				cout << i << endl;
//				return 0;
//			}
//		}
//	}
//	cout << -1 << endl;
//	return 0;
//}




#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <climits>
using namespace std;

class Group{
private: int start, end, dist;
public:
	Group(int start, int end, int dist)
	{
		this->start = start;
		this->end = end;
		this->dist = dist;
	}
	int getStart() const
	{
		return start;
	}
	int getEnd() const
	{
		return end;
	}
	int getDist() const
	{
		return dist;
	}
	friend bool operator < (Group lhs, Group rhs)
	{
		if (lhs.dist < rhs.dist)
		{
			return true;
		}
		return false;
	}
};

struct Town {
	unordered_set<int> adj;
	int min;
};

vector<Group> v;
int n, m, start, end, dist, dif, min, max, v1, v2;
int main() {
	int min;
	int end;
	int max;
	int resMin = INT_MAX;
	int resMax = INT_MIN;

	cin >> n;
	cin >> m;

	Town* towns = new Town[n];

	for (int i = 0; i < m; i++)
	{
		cin >> start;
		cin >> end;
		cin >> dist;
		v.push_back({ start,end,dist });
	}

	sort(v.begin(), v.end());

	int size = v.size();

	for (int i = 0; i < size; i++){
		for (int j = 0; j < n; j++){
			towns[j].adj.clear();
			towns[j].min = j;
		}

		dif = n;
		max = INT_MIN;
		min = INT_MAX;

		for (int j = 0; j < n; j++){
			towns[j].min = j;
			towns[j].adj.insert(j);
		}

		int k = i;
		while (dif != 1 && k < size){
			v1 = v[k].getStart() - 1;	v2 = v[k].getEnd() - 1;
			if (towns[v1].min != towns[v2].min){
				if (min > v[k].getDist()){
					min = v[k].getDist();
				}
				if (max < v[k].getDist()){
					max = v[k].getDist();
				}
				dif--;
				if (towns[v1].min < towns[v2].min){
					for (auto x : towns[towns[v2].min].adj){
						towns[towns[v1].min].adj.insert(x);
						towns[x].min = towns[v1].min;
					}
				}
				else{
					for (auto x : towns[towns[v1].min].adj){
						towns[towns[v2].min].adj.insert(x);
						towns[x].min = towns[v2].min;
					}
				}
			}

			if (dif == 1){break;}
			k++;
		}
		if (dif != 1){break;}
		if (resMax == INT_MIN){resMax = max;resMin = min;}

		if (resMax - resMin > max - min){resMax = max;resMin = min;}
		if (resMax - resMin == max - min){
			if (resMin > min){resMax = max;resMin = min;}
		}
	}
	cout << resMin << " " << resMax << endl;

	return 0;
}
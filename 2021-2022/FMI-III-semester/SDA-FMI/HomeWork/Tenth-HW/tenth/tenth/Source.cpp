
//Горски пожари

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool isValid(int x, int y, int n, int m, vector<vector<int>>& grid) {
	return x < n && y < m && x >= 0 && y >= 0 && grid[x][y] == 1;
}

int bfs(int x, int y, vector<vector<int>>& grid, int n, int m) {
	int xd[] = { -1, -1, -1, 0, 0, 1, 1, 1 },
		yd[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	queue<pair<int, int>> Q;
	Q.push({ x, y });

	int cnt(0), SIZE(8), i;

	while (!Q.empty()) {
		auto coord = Q.front();
		Q.pop();
		++cnt;
		grid[coord.first][coord.second] = 0;

		for (i = 0; i < SIZE; ++i) {
			if (isValid(coord.first + xd[i], coord.second + yd[i], n, m, grid)) {
				Q.push({ coord.first + xd[i], coord.second + yd[i] });
				grid[coord.first + xd[i]][coord.second + yd[i]] = 0;
			}
		}
	}
	return cnt;
}

int main() {
	int n, m, i(0), j, area(0);
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m));

	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			cin >> grid[i][j];

	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			if (grid[i][j])
				area = max(area, bfs(i, j, grid, n, m));

	return cout << area, 0;
}
*/

// 

// Цикличен граф


// github.com/andy489

// https://www.hackerrank.com/contests/sda-exam-27-01-19-/challenges/-1-12/problem

/*
#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<list<int>> add;
vector<bool> flaged;

void DFS(int X, bool& cycle){

	if (flaged[X]) {
		cycle = true; 
		return;
	}
	flaged[X] = true;
	for (const auto& x : add[X]) {
		DFS(x, cycle);
	}
	flaged[X] = false;
}

int main() {
	int N, V, E, xi, yi, wi;
	cin >> N;

	while (N--) {
		bool cyl(false);
		cin >> V >> E;

		add.assign(V, list<int>());
		flaged.assign(V, 0);

		while (E--) {
			cin >> xi;
			cin >> yi;
			cin >> wi;
			--xi;
			--yi;
			add[xi].push_back(yi);
		}
		for (int i = 0; i < V; ++i){ DFS(i, cyl); }
		if (cyl) {
			cout << "true"<<endl;
		}else{
			cout << "false"<<endl;
		}
	}
	return 0;
}
*/

//

//

// github.com/andy489

// https://www.hackerrank.com/contests/sda-2019-2020-test-5/challenges/challenge-2299
//
//#include <iostream>
//#include <vector>
//#include <list>
//#include <queue>
//#include <set>
//
//using namespace std;
//
//int V, E, k, a, b, sz, lvl;
//
//vector<list<int>> adj;
//vector<bool> vis;
//set<int> ans;
//
//void bfs(int u) {
//	queue<int> Q;
//	Q.push(u);
//	vis[u] = true;
//	sz = 1;
//	while (!Q.empty()) {
//		auto curr = Q.front();
//		Q.pop();
//
//		--sz;
//		for (const auto& child : adj[curr]) {
//			if (!vis[child]) {
//				if (lvl == k - 1)
//					ans.insert(child);
//				Q.push(child);
//				vis[child] = true;
//			}
//		}
//
//		if (!sz) {
//			sz = Q.size();
//			++lvl;
//			if (lvl >= k)
//				return;
//		}
//	}
//}
//
//int main() {
//	cin >> V >> E >> k;
//
//	adj.assign(V + 1, list<int>());
//	vis.assign(V + 1, 0);
//
//	while (E--) {
//		cin >> a >> b;
//		adj[a].push_back(b);
//		adj[b].push_back(a);
//	}
//
//	bfs(V);
//
//	if (k == 0)
//		cout << V;
//	else if (!ans.size())
//		cout << "-1";
//	else
//		for (const auto& x : ans)
//			cout << x << ' ';
//	return 0;
//}


// Преписване Дейкстра




#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

#define f(i,n) for(int i=0;i<n;i++)
#define MAX_INT 10001
#define SET_PAIR set<pair<int,int>>
#define VEC_PAIR vector<pair<int,int>>
#define PAIR pair<int,int>

using namespace std;
int n, m, k;

VEC_PAIR vect[MAX_INT];
unsigned int dump[MAX_INT];

void Dij(int l){
	int i = 0;
	SET_PAIR Set;
	Set.insert(make_pair(0, l));
	dump[l] = 0;
	while (!Set.empty()){
		PAIR temp = *(Set.begin());
		Set.erase(Set.begin());
		int p = temp.second;
		int Q = vect[p].size();
		f(i, Q) {
			int index = vect[p][i].second;
			int W = vect[p][i].first;
			if (dump[index] > dump[p] + W){
				if (dump[index] != dump[n + 1]) {
					Set.erase(Set.find(make_pair(dump[index], index)));
				}
				dump[index] = dump[p] + W;
				Set.insert(make_pair(dump[index], index));
			}
		}
	}
}
void initialize() { Dij(0); }
void Cout(){
	if (dump[n - 1] < 10001) {
		cout << dump[n - 1] << endl;
	}
	else {
		cout << -1 << endl;
	}
}
void Make_pair(int a, int b, int c) {
	vect[a].push_back(make_pair(c, b));
	vect[b].push_back(make_pair(c, a));
}
void Initialize_Array(int& a) {
	dump[a] = -1;
}

int main() {
	cin >> n >> m >> k;
	int t,z,i=0;
	int temp = n + 2;
	f(i, m) { cin >> t >> z; Make_pair(t, z, false);}
	f(i,k){ cin >> t >> z; Make_pair(t, z, true);}
	f(i, temp) { Initialize_Array(i); }

	initialize();
	Cout();
	return 0;
}
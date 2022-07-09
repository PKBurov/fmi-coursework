
/*
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#define VV vector<vector<iPair>>
#define Pair typedef pair<int, int>





using namespace std;
 Pair iPair;

class Graph {
	VV adj;
	vector<bool> visited;
	vector<int> paths;

	int vertices;
	void deleteVisited() { visited.assign(vertices + 1, 0);}

public:
	Graph(int vert) : vertices(vert) {
		adj.assign(vert + 1, vector<pii>());
		paths.assign(vert + 1, INT_MAX);
	}

	void insert(pii v1, pii v2) {
		adj[v1.second].push_back(v2);
		adj[v2.second].push_back(v1);
	}

	void djiikstra(int start) {
		clearVisited();
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		pq.push({ 0, start });
		paths[start] = 0;

		while (!pq.empty()) {
			int dist = pq.top().first;
			int v = pq.top().second;
			pq.pop();
			if (visited[v])
				continue;
			visited[v] = true;
			for (const auto& child : adj[v]) {
				if (visited[child.second])
					continue;
				if (paths[v] + child.first < paths[child.second]) {
					paths[child.second] = paths[v] + child.first;
					pq.push({ paths[child.second], child.second });
				}
			}
		}

		for (int i = 1; i <= v; ++i) {
			if (i != start) {
				if (paths[i] == INT_MAX)
					printf("%d ", -1);
				else
					printf("%d ", paths[i]);
			}
		}
	}
};


int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);

		int v1, v2, weight;

		Graph G(n);

		while (m--) {
			scanf("%d %d %d", &v1, &v2, &weight);
			G.insert({ weight, v1 }, { weight, v2 });
		}

		int start;
		scanf("%d", &start);

		G.djiikstra(start);
		printf("\n");
	}
	return 0;
}
*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

#define Vec vector<pair<int,int>>
#define Pair pair<int, int>
#define Set set<pair<int, int>>
using namespace std;

Vec visited[200001];
unsigned int dtl[200001];
int n,m;

void Djkstra(int k){

	Set st;
	st.insert(make_pair(0, k));
	dtl[k] = 0;

	while (!st.empty()){
		Pair temp = *(st.begin());
		st.erase(st.begin());
		int u1 = temp.second;
		for (int i = 0; i < visited[u1].size(); i++){
			int vertIndx = visited[u1][i].second;
			int weight = visited[u1][i].first;
			if (dtl[vertIndx] > dtl[u1] + weight){
				if (dtl[vertIndx] != dtl[n + 1]) st.erase(st.find(make_pair(dtl[vertIndx], vertIndx)));
				dtl[vertIndx] = dtl[u1] + weight;
				st.insert(make_pair(dtl[vertIndx], vertIndx));
			}
		}
	}
}
int main()
{
	int a, b, c;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		visited[b].push_back(make_pair(c, a));
		visited[a].push_back(make_pair(c, b));
	}
	int input;
	scanf("%d", &input);
	for (int i = 0; i < n + 2; i++){ dtl[i] = -1;}
	unsigned int MaxLen = -1;
	Djkstra(input);
	for (int i = 1; i <= n; i++) {
		if (i != input) {
			if (dtl[i] == MaxLen) {
				printf("-1");
			}
			else {
				cout << dtl[i] << " ";
			}
		}
	}
	cout << endl;
	return 0;
}


int main()
{
	Read();
	int s;
	scanf("%d", &s);
	Init();
	unsigned int maxX = -1;
	Dijekstra(s);
	for (int i = 1; i <= n; i++) {
		if (i != s) {
			if (d[i] == maxX) printf("-1 ");
			else cout << d[i] << " ";
		}
	}
	cout << endl;
	return 0;
}
#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector< pair<int, int> >v[200000];
int n, m;
unsigned int d[200000];
void Read()
{
	int a, b, w;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &w);
		v[b].push_back(make_pair(w, a));
		v[a].push_back(make_pair(w, b));
	}
}
void Init()
{
	for (int i = 0; i < n + 2; i++)
	{
		d[i] = -1;
	}
}
void Dijekstra(int s)
{
	set< pair<int, int> >st;
	st.insert(make_pair(0, s));
	d[s] = 0;
	while (!st.empty())
	{
		pair<int, int> temp = *(st.begin());
		st.erase(st.begin());
		int u = temp.second;
		for (int i = 0; i < v[u].size(); i++)
		{
			int idx = v[u][i].second;
			int weight = v[u][i].first;
			if (d[idx] > d[u] + weight)
			{
				if (d[idx] != d[n + 1]) st.erase(st.find(make_pair(d[idx], idx)));
				d[idx] = d[u] + weight;
				st.insert(make_pair(d[idx], idx));
			}
		}
	}
}

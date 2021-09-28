/*
#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iostream>
#include <climits>
#define PriorQ priority_queue<ppair, vector<ppair>, greater<ppair>>
#define Pair typedef pair<int, int>
#define vectList vector<list<ppair>>
#define loop(n) for( int ii = 0; ii<n; n--)

using namespace std;
Pair ppair;

class G {
public:
	vectList adjent;
	vector<bool> visited;
	int vertices;
	void clearVisited() { visited.assign(vertices + 1, 0);}
public:
	vector<int> path;
	G(int t) : vertices(t) { adjent.assign(t + 1, list<ppair>()); path.assign(t + 1, INT_MAX);}
	void insert(ppair v1, ppair v2) {adjent[v1.second].push_back(v2); adjent[v2.second].push_back(v1);}

	void djiksta(int start) {
		clearVisited();
		PriorQ prioriti_que;
		prioriti_que.push({ 0, start });
		path[start] = 0;
		while (!prioriti_que.empty()) {
			int vert = prioriti_que.top().second;
			prioriti_que.pop();
			if (visited[vert]){ continue; }
			visited[vert] = true;
			for (const auto& son : adjent[vert]) {
				if (visited[son.second]){ continue; }
				if (path[vert] + son.first < path[son.second]) {
					path[son.second] = path[vert] + son.first;
					prioriti_que.push({ path[son.second], son.second });
				}
			}
		}
	}
};
int edges, vertcies, vertices_1, vertices_2, weight, z, stud;
void Input() {
	cin >> edges >> vertcies;
	G g(edges);
	loop(vertcies) {
		cin >> vertices_1 >> vertices_2 >> weight;
		g.insert({ weight, vertices_1 }, { weight, vertices_2 });
	}
	cin >> vertcies;
	loop(vertcies) {
		cin >> z;
		g.insert({ 0, z }, { 0, edges });
	}
	cin >> vertcies;
	g.djiksta(edges);
	loop(vertcies) {
		cin >> stud;
		cout << g.path[stud];
		cout << endl;
	}
}
int main() {
	Input();
}
*/



//#include <iostream> 
//#include <limits.h> 
//#include <list> 
//#include <stack> 
//#define NINF INT_MIN 
//using namespace std;
//
//class AdjListNode {
//	int v;
//	int weight;
//
//public:
//	AdjListNode(int _v, int _w)
//	{
//		v = _v;
//		weight = _w;
//	}
//	int getV() { return v; }
//	int getWeight() { return weight; }
//};
//
//
//class Graph {
//	int V;
//
//	list<AdjListNode>* adj;
//
//	void topologicalSortUtil(int v, bool visited[],
//		stack<int>& Stack);
//
//public:
//	Graph(int V);
//	~Graph();
//
//
//	void addEdge(int u, int v, int weight);
//
//
//	void longestPath(int s, int f);
//};
//
//Graph::Graph(int V)
//{
//	this->V = V;
//	adj = new list<AdjListNode>[V];
//}
//
//Graph::~Graph()
//{
//	delete[] adj;
//}
//
//
//void Graph::addEdge(int u, int v, int weight)
//{
//	AdjListNode node(v, weight);
//	adj[u].push_back(node);
//}
//
//void Graph::topologicalSortUtil(int v, bool visited[],
//	stack<int>& Stack)
//{
//	visited[v] = true;
//
//	list<AdjListNode>::iterator i;
//	for (i = adj[v].begin(); i != adj[v].end(); ++i) {
//		AdjListNode node = *i;
//		if (!visited[node.getV()])
//			topologicalSortUtil(node.getV(), visited, Stack);
//	}
//
//	Stack.push(v);
//}
//
//void Graph::longestPath(int s, int f)
//{
//	stack<int> Stack;
//	int dist[V];
//	long long count[V];
//
//	bool* visited = new bool[V];
//	for (int i = 0; i < V; i++)
//		visited[i] = false;
//
//	for (int i = 0; i < V; i++)
//		if (visited[i] == false)
//			topologicalSortUtil(i, visited, Stack);
//
//	for (int i = 0; i < V; i++) {
//		dist[i] = NINF;
//		count[i] = 1;
//	}
//	dist[s] = 0;
//	count[s] = 1;
//
//	while (Stack.empty() == false) {
//		int u = Stack.top();
//		Stack.pop();
//		list<AdjListNode>::iterator i;
//		if (dist[u] != NINF) {
//			for (i = adj[u].begin(); i != adj[u].end(); ++i) {
//				if (dist[i->getV()] == dist[u] + i->getWeight()) {
//					count[i->getV()] += count[u];
//				}
//				if (dist[i->getV()] < dist[u] + i->getWeight()) {
//					dist[i->getV()] = dist[u] + i->getWeight();
//					count[i->getV()] = count[u];
//				}
//			}
//		}
//	}
//
//	cout << dist[f] << " " << count[f] << endl;
//
//	delete[] visited;
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	Graph g(n);
//	int a, b, w;
//	for (int i = 0; i < m; i++) {
//		cin >> a >> b >> w;
//		g.addEdge(a, b, w);
//	}
//
//	int s, f;
//	cin >> s >> f;
//	g.longestPath(s, f);
//	return 0;
//}

/*
#include <iostream>
#include <queue>
#include <list>
#include <vector>
#define NN (int)1e9
#define Pair typedef pair<int, int>
#define LP list< pair<int, int> >
#define PriorQ priority_queue< pp, vector <pp>, greater<pp> >
#define vect vector<long long>
#define loop(n) for(int i=0;i<n;i++)
using namespace std;


int N;
Pair pp;
bool visited[(int)1e6];

class G{
	int Vertices;
	LP* adj;
public:
	G(int V) {
		this->Vertices = V;
		adj = new list<pp>[V];
	}
	void AddEdges(int K, int J, int W) {
		adj[K].push_back(make_pair(J, W));
	}
	void ShortestPath(int ss) {
		PriorQ prior_que;
		vect distance(Vertices, NN);
		vect visited_counted(Vertices, 1);
		prior_que.push(make_pair(0, ss));
		distance[ss] = 0;
		while (!prior_que.empty()) {
			int f = prior_que.top().second;
			prior_que.pop();
			if (visited[f] == false) {
				for (const auto& chld : adj[f]) {
					int t = chld.first;
					int weight = chld.second;
					if (distance[t] == distance[f] + weight) {
						visited_counted[t] += visited_counted[f];
						visited_counted[t] %= 1000000007;
					}else if (distance[t] > distance[f] + weight) {
						distance[t] = distance[f] + weight;
						prior_que.push(make_pair(distance[t], t));
						visited_counted[t] = visited_counted[f];
					}
				}
			}
			visited[f] = true;
		}
		if (distance[N] == NN) {
			cout << -1 << " " << 0 << endl;
		}
		else cout << distance[N] << " " << visited_counted[N] << endl;
	}
};

void Solve() {
	int M;
	cin >> N >> M;
	G g(N + 1);
	int ci, ui, vi;
	loop(M) {
		cin >> ci >> ui >> vi;
		g.AddEdges(ci, ui, vi);
	}
	g.ShortestPath(1);
}
int main()
{
	Solve();
	return 0;
}
*/






package consoleapp1;

import java.util.*;

public class AdjListNode
{

	private int v;
	private int weight;

	public AdjListNode()
	{

	}

	public AdjListNode(int _v, int _w)
	{
		this.v = _v;
		this.weight = _w;
	}
	public final int GetV()
	{
		return v;
	}
	public final int GetWeight()
	{
		return weight;
	}
}

public class Graph
{
	private static final int NINF = Integer.MIN_VALUE;

	private int V;

	private ArrayList<ArrayList<AdjListNode>> adj;

	private void TopologicalSortUtil(int v, boolean[] visited, Stack<Integer> stack)
	{
		visited[v] = true;


		for (AdjListNode item : adj.get(v))
		{
			AdjListNode node = item;
			if (!visited[node.GetV()])
			{
				TopologicalSortUtil(node.GetV(), visited, stack);
			}
		}

		stack.push(v);
	}

	public Graph(int V)
	{
		this.V = V;
		adj = new ArrayList<ArrayList<AdjListNode>>(V);
		for (int i = 0; i < V; i++)
		{
			adj.add(new ArrayList<AdjListNode>());
		}
	}

	public final void AddEdge(int u, int v, int weight)
	{
		AdjListNode node = new AdjListNode(v, weight);
		adj.get(u).add(node);
	}


	public final void LongestPath(int s, int f)
	{
		Stack<Integer> stack = new Stack<Integer>();
		int[] dist = new int[this.V];
		long[] count = new long[V];

		boolean[] visited = new boolean[V];
		for (int i = 0; i < V; i++)
		{
			visited[i] = false;
		}

		for (int i = 0; i < V; i++)
		{
			if (visited[i] == false)
			{
				TopologicalSortUtil(i, visited, stack);
			}
		}

		for (int i = 0; i < V; i++)
		{
			dist[i] = NINF;
			count[i] = 1;
		}
		dist[s] = 0;
		count[s] = 1;

		while (stack.size() > 0)
		{
			int u = stack.peek();
			stack.pop();
			if (dist[u] != NINF)
			{

				for (AdjListNode item : adj.get(u))
				{
					if (dist[item.GetV()] == dist[u] + item.GetWeight())
					{
						count[item.GetV()] += count[u];
					}
					if (dist[item.GetV()] < dist[u] + item.GetWeight())
					{
						dist[item.GetV()] = dist[u] + item.GetWeight();
						count[item.GetV()] = count[u];
					}
				}
			}
		}
		System.out.println(dist[f] + " " + count[f]);

	}
}


public class Program
{
	public static void main(String[] args)
	{

		int n, m = 0;

		int[] input = new Scanner(System.in).nextLine().split("[ ]", -1).Select(Integer.parseInt).ToArray();
		n = input[0];
		m = input[1];

		Graph g = new Graph(n);
		int a, b, w = 0;

		for (int i = 0; i < m; i++)
		{
			input = new Scanner(System.in).nextLine().split("[ ]", -1).Select(Integer.parseInt).ToArray();

			a = input[0];
			b = input[1];
			w = input[2];

			g.AddEdge(a, b, w);
		}

		int s, f;
		input = new Scanner(System.in).nextLine().split("[ ]", -1).Select(Integer.parseInt).ToArray();
		s = input[0];
		f = input[1];

		g.LongestPath(s, f);
	}
}
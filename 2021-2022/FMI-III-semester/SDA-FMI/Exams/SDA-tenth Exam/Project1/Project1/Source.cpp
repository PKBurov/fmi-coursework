#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_INT 500001
#define Vect vector<int> 
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
//
//using namespace std;
//int N=0, M=0, count_num = 0;
//Vect vect[MAX_INT];
//bool visited[MAX_INT];
//
//void dfs(int x, bool value) {
//	visited[x] = true;
//	bool temp = false;
//	int q = vect[x].size();
//	f(i, q) {
//		if (visited[vect[x][i]] == false) {
//			if (temp == false && value == true) {
//				count_num++;
//				temp = true;
//			}
//			dfs(vect[x][i], false);
//		}
//	}
//}
//
//void initialize(int& V, int& E) {
//	vect[V].push_back(E);
//	vect[E].push_back(V);
//}
//
//int main() {
//
//	cin >> M >> N;
//	int V, E,i=0;
//	f(i, N) {
//		cin >> V >> E;
//		initialize(V, E);
//	}
//	f(i, M) {
//		if (visited[i] == 0) { dfs(i, true);}
//	}
//	cout << count_num << endl;
//
//	return 0;
//}


	int main()
	{
		int m;
		cin >> m;
		int graph[10000][10000];
		for (int i = 0; i < m; i++){
			int input = 0;
			cin >> input;
			graph[i][1000] = input;
			for (int j = 0; j < input; j++){
				int temp_input = 0;
				cin >> temp_input;

				graph[i][temp_input] = 1;
				graph[temp_input][i] = 1;
			}
		}
		int q;
		cin >> q;

		for (int i = 0; i < q; i++)
		{
			int n;
			cin >> n;
			int a;
			cin >> a;
			int b = 0;
			bool isTrue = false;
			for (int j = 0; j < n - 1; j++){
				int b;
				cin >> b;
				if (graph[a][b] == 0){
					isTrue = true;
				}
				a = b;
			}
			if (isTrue){
				cout << ("0");

			}
			else
			{
				cout << ("1");

			}

		}
	}

//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <stack>
//#include <queue>
//using namespace std;
//
//
//int main() {
//	
//	int N;
//	int sum = 0;
//	cin >> N;
//
//	stack <int> stack1;
//	stack <int> second;
//
//	for (int i = 0; i < N; i++){
//		int input;
//		cin >> input;
//
//		if (input == -1){ //Undo //-2 -5 1 2 3 4 -1
//
//			if (stack1.empty() == false){
//				int temp = stack1.top();
//				second.push(temp);
//				stack1.pop();
//			}
//		}else if (input == -2) { //redo
//			if (second.empty() == false){
//				int temp2 = second.top();
//				stack1.push(temp2);
//				second.pop();
//			}
//		}
//		else {
//			stack1.push(input);
//
//		}
//	}
//	while (stack1.empty() == false){
//		sum += stack1.top();
//		stack1.pop();
//	}
//
//	cout << sum;
//
//	return 0;
//}



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int op[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool used[1000][1000];
int main() {
	int m, n, t;
	cin >> n >> m >> t;
	int dimensions = n * m;
	int x, y;
	queue<pair<int, int>>q;

	while (cin>>x>>y){
		q.push({ --x,--y });
		used[x][y] = true;
		dimensions--;
	}
	for (int i = 0; i < t; i++){
		int size = q.size();
		while (size--) {
			pair<int, int> cell = q.front();
			q.pop();
			for (int x = 0; x < 4; x++){
				int newX = cell.first + op[x][0];
				int newY = cell.second + op[x][1];
				if (newX >= 0 && newY <n && newY >=0 && newX<m){
					if (!used[newX][newY])
					{
						used[newX][newY] = true;
						q.push({ newX,newY });
						dimensions--;
					}
				}
			}
		}
	}
	cout << dimensions << endl;
	return 0;
}

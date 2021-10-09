#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Stack{

private:
	stack<pair<int, int>> s;
public:
		void Push(int x) {
			if (s.empty()){
				s.push({ x,x });
			}
			else {
				s.push({x,
					min(x,s.top().second)});
			}
		}
		void Pop() {
			s.pop();
		}
		void Peek() {
			cout << s.top().first << endl;
		}
		void Min() {
			cout << s.top().second << endl;
		}

		void CommandList(string& commnadList) {
			string push = "push";
			string pop = "pop";
			string peek = "peek";
			string min = "min";
			string StringNumber;

			int number = 0;
			int choice = 0;

			if (push == commnadList.substr(0, 4)) {
				choice = 1;
				StringNumber = commnadList.substr(5); 
				number = stoi(StringNumber);
			}
			if (pop == commnadList.substr(0, 3)) { choice = 2;}
			if (peek == commnadList.substr(0, 4)){ choice = 3;}
			if (min == commnadList.substr(0, 3)) { choice = 4;}

			switch (choice) {
			case 1:
				Push(number);
				break;
			case 2:
				Pop();
				break;
			case 3:
				Peek();
				break;
			case 4:
				Min();
				break;
			}
		}
};
	
int main() {
	
	Stack s;
	int N;
	cin >> N;
	for (int i = 0; i <= N; i++){
		string command;
		getline(cin, command);
		s.CommandList(command);
	}

	return 0;
}

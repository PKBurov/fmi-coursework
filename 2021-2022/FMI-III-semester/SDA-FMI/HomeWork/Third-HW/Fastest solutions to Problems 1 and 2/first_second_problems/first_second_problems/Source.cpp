
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int arr[1000001];
//
//int findLeft(int x, int l, int r)
//{
//	if (l >= r) return r;
//	int m = (l + r) / 2;
//	if (arr[m] < x)return findLeft(x, m + 1, r);
//	return findLeft(x, l, m);
//}
//int main() {
//	int n, q;
//	cin >> n >> q;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	sort(arr, arr + n);
//	for (int i = 0; i < q; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		int left_pos = findLeft(a, 0, n - 1);
//		int right_pos = findLeft(b + 1, 0, n - 1);
//
//
//		//cout<<left_pos<<" : "<<right_pos<<endl;
//		if (arr[left_pos] != a && arr[left_pos + 1] == a)left_pos++;
//		if (arr[right_pos] > b)right_pos--;
//		//if(left_pos == right_pos && a)
//		if (right_pos - left_pos < 0)cout << 0 << endl;
//		else cout << (right_pos - left_pos + 1) << endl;
//	}
//	return 0;
//}

/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long t[100001];
long long n, k;

long long findTime(long long l, long long r)
{
	if(l>=r)return r;
	long long m=(l+r)/2;
	long long curr_n = 0;
	for(int i=0;i<k;i++)
	{
		curr_n= curr_n +(m/t[i]);
		if(curr_n>=n)return findTime(l,m);
	}
	//cout<<l<<":"<<r<<"  m:"<<m<<" curr_n:"<<curr_n<<endl;
	return findTime(m+1,r);
}

int main() {
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		cin>>t[i];
	}
	long long u = findTime(1,100000000000000000);
	cout<<u<<endl;
	return 0;
}
*/
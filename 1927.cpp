#include <iostream>
#include <queue>
using namespace std;
int t;

struct cmp {
	bool operator()(int a, int b) {
		return a > b; 
	}
};
priority_queue<int, vector<int>, cmp> pq; 
int main() {
	ios_base::sync_with_stdio(false); 
	vector<int> result;
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		if (n == 0) {
			if (pq.empty()) {
				result.push_back(0);
			}
			else {
				result.push_back(pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(n);
		}
	}
	for (auto it : result) {
		cout << it << "\n";
	}
	return 0;
}
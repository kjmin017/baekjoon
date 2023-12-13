#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int n,  p;
	long long score;
	cin >> n >> score >> p;
	int* scores = new int[n];
	long long otherscore;
	int result = 1;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> otherscore;
		if (otherscore > score) {
			result++;
			cnt++;
		}
		else if (otherscore == score) {
			cnt++;
			continue;
		}
		
		
	}
	if (cnt==p && n!=0) {
		cout << -1;
	}

	else {
		cout << result;
	}

	
	delete[] scores;
	return 0;
}
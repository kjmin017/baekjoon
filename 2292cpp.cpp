#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t;
	cin >> t;
	long long cnt = 1;
	long long line = 0;
	while (cnt < t) {
		cnt += 6 * line;
		line++;
	}
	if (t == 1) {
		cout << 1;
	}
	else {
		cout << line;
	}
	
	return 0;
}
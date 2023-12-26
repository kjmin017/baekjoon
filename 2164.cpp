#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int n = 0;
	cin >> n;
	int answer = 0;
	int a = 1;
	while(n > a*2) {
		a *= 2;
	}
	answer = (n - a) * 2;
	if (n < 3) {
		cout << n;
	}
	else {
		cout << answer;
	}
	
	return 0;
}

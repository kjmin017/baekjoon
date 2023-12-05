#include <iostream>
#include <string>
using namespace std;

void play(int n) {
	if ((n - 6) % 6 == 0 || (n - 6) % 4 == 0 || (n - 6) % 2 == 0 || (n - 4) % 6 == 0 || (n - 4) % 4 == 0 || (n - 4) % 2 == 0) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	
	cin >> n;
	play(n);

	return 0;
}
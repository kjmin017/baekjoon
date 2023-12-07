#include <iostream>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int** c = new int*[n];
	for (int i = 0; i < n; i++) {
		c[i] = new int[2];
		for (int j = 0; j < 2; j++) {
			cin >> c[i][j];
		}
	}
	

	for (int i = 0; i < n; i++) {
		int rank = 1;
		for (int j = 0; j < n; j++) {
			if (c[i][1] < c[j][1] && c[i][0] < c[j][0]) {
				rank++;
			}
		}
		cout << rank << "\n";

	}

	for (int i = 0; i < n; i++) {
		delete[] c[i];
	}
	delete[] c;
	return 0;
}
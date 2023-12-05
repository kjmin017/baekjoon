#include <iostream>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,k;
	cin >> n >> k;
	int** c = new int*[n];
	for (int i = 0; i < n; i++) {
		c[i] = new int[4];
		for (int j = 0; j < 4; j++) {
			cin >> c[i][j];
			if (c[i][0] == k) {
				k = i;
			}
		}
	}
	int rank = 1;

	for (int i = 0; i < n; i++) {
		if (c[i][1] > c[k][1]) {
			rank++;
		}
		else if (c[i][1] == c[k][1]) {
			if (c[i][2] > c[k][2]) {
				rank++;
			}
			else if (c[i][2] == c[k][2]) {
				if (c[i][3] > c[k][3]) {
					rank++;
				}
			}
		}
	}
	cout << rank;
	for (int i = 0; i < n; i++) {
		delete[] c[i];
	}
	delete[] c;
	return 0;
}
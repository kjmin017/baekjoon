#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int countChanges(char** matrix, char start, int x, int y) {
	int cnt = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			char expectedColor = ((i + j) % 2 == 0) ? start : (start == 'B' ? 'W' : 'B');
			if (matrix[i][j] != expectedColor) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int m, n;
	cin >> m >> n;

	char** matrix = new char*[m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new char[n];
		string line;
		getline(cin >> ws, line);

		for (int j = 0; j < n; j++) {
			matrix[i][j] = line[j];
		}
	}

	int minChanges = m * n;
	for (int i = 0; i <= m - 8; i++) {
		for (int j = 0; j <= n - 8; j++) {
			int changes = min(countChanges(matrix, 'B', i, j),
				countChanges(matrix, 'W', i, j));
			minChanges = min(minChanges, changes);
		}
	}

	cout << minChanges << endl;

	for (int i = 0; i < m; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}

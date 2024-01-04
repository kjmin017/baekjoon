#include <iostream>

using namespace std;
void getmin() {

}
int main() {

	int n, m;
	int sum = 0;
	cin >> n >> m;

	int** matrix = new int*[n];

	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << sum;
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}
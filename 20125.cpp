#include <iostream>

using namespace std;
int leftarm, rightarm, spine, leftleg, rightleg;
void checkleftarm(int x, int y, int n, char** matrix) {
	int cnt = 0;
	while (matrix[y][x] == '*' && x>=0) {
		cnt++;
		x--;
	}
	leftarm = cnt;
}
void checkrightarm(int x, int y, int n, char** matrix) {
	int cnt = 0;
	while ( x < n&&matrix[y][x] == '*') {
		cnt++;
		x++;
	}
	rightarm = cnt;
}

void checkleftleg(int x, int y, int n, char** matrix) {
	int cnt = 0;
	while (y < n &&matrix[y][x] == '*') {
		cnt++;
		y++;
	}
	leftleg = cnt;
}
void checkrightleg(int x, int y, int n, char** matrix) {
	int cnt = 0;
	while (y < n && matrix[y][x] == '*' ) {
		cnt++;
		y++;
	}
	rightleg = cnt;
}
void checkspine(int x, int y, int n, char** matrix) {
	int cnt = 0;
	while (y < n && matrix[y][x] == '*' ) {
		cnt++;
		y++;
	}
	spine = cnt;
	checkleftleg(x-1, y, n, matrix);
	checkrightleg(x+1, y, n, matrix);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char c;
	int n;
	cin >> n;
	char** matrix = new char*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new char[n];
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	int heartx = 0;
	int hearty = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > 0 && i < n && j>0 && j < n) {
				if (matrix[i][j] == '*') {
					if (matrix[i - 1][j] == '*' && matrix[i][j - 1] == '*' && matrix[i + 1][j] == '*' && matrix[i][j + 1] == '*') {
						heartx = j;
						hearty = i;
						break;
					}
				}
			}
		}
		if (hearty != 0&& heartx != 0) {
			break;
		}
	}

	cout << hearty+1 << " " << heartx+1 << "\n";
	checkleftarm(heartx-1, hearty, n, matrix);
	checkrightarm(heartx + 1, hearty, n, matrix);
	checkspine(heartx, hearty + 1, n, matrix);
	cout << leftarm << " " << rightarm << " " << spine << " " << leftleg << " " << rightleg<< "\n";
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}
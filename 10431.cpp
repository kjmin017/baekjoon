#include <iostream>
#include <string>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int students[21];
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < 21; j++) {
			cin >> students[j];
			if (j > 1) {
				for (int k = j; k > 1; k--) {
					if (students[k] < students[k - 1]) {
						int temp = students[k - 1];
						students[k - 1] = students[k];
						students[k] = temp;
						cnt++;
					}
				}
			}
		}
		cout << students[0] << " " << cnt << "\n";
	}

	return 0;
}
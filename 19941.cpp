#include <iostream>
#include <string>
using namespace std;

int main() {
	string arr;
	int n, k;
	int count = 0;
	cin >> n >> k;
	cin >> arr;

	for (int i = 0; i < n; i++) {
		if (arr[i] == 'P') {
			for (int j = i - k; j <= i + k; j++) {
				if (0 <= j && j < n && arr[j] == 'H') {
					arr[j] = '-';
					count++;
					break;
				}
			}
		}
	}

	cout << count;
	return 0;
}
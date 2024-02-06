#include <iostream>
#include <string>
using namespace std;
int n, m;
string title[100000];
int require[100000];
int binsearch(int p) {
	int mid = 0, left = 0, right = n - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (p <= require[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (p > require[mid])
		return mid + 1;
	else
		return mid;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> title[i] >> require[i];
	}
	int num;
	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << title[binsearch(num)] << "\n";
	}
	

	return 0;
}
#include <iostream>
using namespace std;

int main(void) {
	int n,m;
	int t;
	int a;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		a = 1;
		for (int j = 0; j < n; j++) {
			a *= m-j;
			a /= 1+j;
		}
		cout << a << endl;
	}
	
	return 0;
}
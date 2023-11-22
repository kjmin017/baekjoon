#include <iostream>

using namespace std;


int main() {
	int H, W, N, M;
	cin >> H >> W >> N >> M;
	int a, b;
	if ((H % (N + 1))>0) {
		a = 1;
	}
	else {
		a = 0;
	}
	if ((W % (M + 1))>0) {
		b = 1;
	}
	else {
		b = 0;
	}
	int h = H / (N + 1) + a;
	
	int w = W / (M + 1);
	int d = h * w;
	cout << d;
	return 0;
}

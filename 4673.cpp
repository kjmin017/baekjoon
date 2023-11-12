#include <iostream>
using namespace std;
int snum[10000] = { 0 };

void selfnumber(int a) {
	int sn = 0;
	sn = a / 1000 + a % 1000 / 100 + a % 1000 % 100 / 10 + a % 10 + a;
	if (sn < 10001) {
		snum[sn - 1] = sn;
		selfnumber(sn);
	}
	
}
int main() {

	for (int i = 1; i < 10000; i++) {
		selfnumber(i);
	}
	
	for (int i = 0; i < 10000; i++) {
		if (snum[i] == 0) {
			cout << i + 1 << endl;
		}
	}
	return 0;
}
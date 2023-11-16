#include <iostream>
#include <string>
using namespace std;
bool contains666(int number) {

	string numStr = to_string(number);

    return numStr.find("666") != string::npos;
}


int main(void) {
	int n;
	int cnt = 0;
	int i = 0;
	cin >> n;

	while (true) {
		if (i > 2666799) {
			break;
		}
		if (contains666(i)) {
			cnt++;
			if (cnt == n) {
				cout << i;
				break;
			}
		}
		i++;
	}



	return 0;
}
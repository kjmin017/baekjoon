#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	string str = "";
	cin >> str;

	int num = 1, ptr = 0;

	while (true) {
		
		string num2str = to_string(num);
		for (int i = 0; i < num2str.length(); i++) {
			if (str[ptr] == num2str[i]) {
				ptr++;
			}
			if (ptr == str.length()) {
				cout << num;
				return 0;
			}
		}
		num++;
	}
	return 0;
}
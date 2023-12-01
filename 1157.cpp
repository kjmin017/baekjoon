#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int upper[26] = { 0 };
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] <= 'Z' && s[i] >= 'A') {
			upper[s[i] - 'A']++;
		}
		else if(s[i] <= 'z' && s[i] >= 'a') {
			upper[s[i] - 'a']++;
		}
		
	}
	int max = 0;
	int maxa = 0;
	for (int j = 0; j < 26; j++) {
		if (upper[j] > max) {
			max = upper[j];
			maxa = j;
		}
	}
	for (int k = 0; k < 26; k++) {
		if (k !=maxa && upper[k] == max) {
			cout << "?";
			return 0;
		}
	}
	char c = maxa + 65;
	cout << c;
	return 0;
}
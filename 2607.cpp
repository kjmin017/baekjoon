#include <iostream>
#include <string>

using namespace std;
bool wordcheck(string word, string s) {
	int* a = new int[word.length()]();
	int num = 0;
	for (int i = 0; i < s.length(); i++) {
		std::size_t found = word.find(s[i]);
		while ( found != std::string::npos) {
			if (a[found] == 0) {
				a[found]++;
				num++;
				break;
			}
			else {
				found = word.find(s[i], found + 1);
			}
		}
	}
	delete[] a;
	int d = s.length() - num;
	if (num >= word.length() - 1 && num <= word.length() + 1 && s.length()-num<2) {
		return true;
	}
	else {
		return  false;
	}
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string word, input;

	int n;
	cin >> n >> word;
	int count = 0;
	for (int i = 1; i < n; i++) {
		cin >> input;
		if (input.length() >= word.length() - 1 && input.length() <= word.length() + 1) {
			if (wordcheck(word, input)) {
				count++;
			}
		}
	}
	cout << count;
	return 0;
}
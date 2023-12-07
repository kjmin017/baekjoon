#include <iostream>
#include <string>
#include<vector>
#include <unordered_set>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char c;
	int n;
	cin >> n >> c;
	
	unordered_set<string> sv; 

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		sv.insert(s); 
	}
	int num = sv.size();
	if (c == 'Y') {
		num /= 1;
	}
	else if (c == 'F') {
		num /= 2;
	}
	else {
		num /= 3;
	}
	cout << num << "\n";
	return 0;
}
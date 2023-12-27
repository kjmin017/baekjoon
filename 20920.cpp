#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	unordered_map<string, int> wordCount;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (int i = 0; i < n; i++) {
		string word;
		getline(cin, word);
		if (word.length() >= m) {
			wordCount[word]++;
		}
	}

	
	vector<pair<string, int>> words;
	for (const auto &entry : wordCount) {
		words.push_back(entry);
	}

	
	sort(words.begin(), words.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
		if (a.second != b.second) return a.second > b.second; 
		if (a.first.length() != b.first.length()) return a.first.length() > b.first.length(); 
		return a.first < b.first; 
	});

	for (const auto &w : words) {
		cout << w.first << "\n";
	}

	return 0;
}

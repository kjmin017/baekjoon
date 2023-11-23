#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	set<int> list, alllist;
	for (int i = 1; i < 21; i++) {
		alllist.insert(i);
	}
	string order;
	int o;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> order; 
		if (order == "add") {
			cin >> o;
			list.insert(o);
		}
		else if(order=="remove"){
			cin >> o;
			list.erase(o);
		}
		else if (order == "check") {
			cin >> o;
			cout << (list.find(o) != list.end()) << '\n';
		}
		else if (order == "toggle") {
			cin >> o;
			auto it = list.find(o);
			if (it != list.end()) {
				list.erase(o);
			}
			else {
				list.insert(o);
			}
		}
		else if (order == "all") {
			list = alllist;
		}
		else if (order == "empty") {
			list.clear();
		}
	}

	
	return 0;
}
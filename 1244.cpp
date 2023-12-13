#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, sn;
	cin >> n;
	int* switches = new int[n+1];
	for (int i = 1; i < n+1; i++) {
		cin >> switches[i];
	}
	cin >> sn;
	int gender, number;
	for (int i = 0; i < sn; i++) {
		cin >> gender >> number;
		if (gender == 1) {
			for (int j = 1; j < n+1; j++) {
				if ((j)%number == 0) {
					switches[j] = switches[j] ^ 1;
				}
			}
		}
		else if(gender == 2){
			switches[number] = switches[number] ^ 1;
			for (int j = 1; switches[number - j] == switches[number + j]; j++) {
				if (number + j > n || number - j < 1) {
					break;
				}
				switches[number - j] = switches[number - j] ^ 1;
				switches[number + j] = switches[number + j] ^ 1;
			}
		}
	
	}
	for (int i = 1; i < n+1; i++) {
		
		cout << switches[i] << " ";
		if (i % 20 == 0) {
			cout << "\n";
		}
	}


	delete[] switches;
	return 0;
}
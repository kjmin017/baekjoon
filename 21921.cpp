#include <iostream>

using namespace std;


int main() {
	int x,n;
	int max = 0;
	int count = 0;
	cin >> n >> x;
	int* numbers = new int[n];
	int* maxnumbers = new int[n-x];
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	maxnumbers[0] = 0;
	for (int j = 0; j < x; j++) {
		maxnumbers[0] += numbers[j];
		
	}
	if (max < maxnumbers[0]) {
		max = maxnumbers[0];
	}
	for (int i = 1; i < n-x+1; i++) {
		maxnumbers[i] = 0;
		maxnumbers[i] = maxnumbers[i-1] - numbers[i-1] + numbers[i + x-1];
		if (max < maxnumbers[i]) {
			max = maxnumbers[i];
		}
	}
	for (int i = 0; i < n - x+1; i++) {
		if (max == maxnumbers[i]) {
			count++;
		}
	}
	if (max == 0) {
		cout << "SAD";
	}
	else {
		cout << max << "\n" << count;
	}

	delete[] numbers;
	delete[] maxnumbers;

	return 0;
}
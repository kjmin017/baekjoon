#include <iostream>
#include <vector>
using namespace std;

bool findc(vector<int> arr, int a) {
	for (auto it:arr) {
		if (it == a) {
			return true;
		}
	}
	return false;
}

int findn(int* arr, int a, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == a) {
			
			cnt++;
		}
	}
	return cnt;
}
int findfive(int* arr, int a, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == a) {
			cnt++;
		}
		if (cnt == 5) {
			return i;
		}
	}
	return 0;
}
int getscore(vector<int> arr, int* numbers, int a, int n) {
	int score = 1;
	int cnt =1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (findn(numbers, numbers[i], n) == 6) {
			if (numbers[i] == a && cnt<=4) {
				sum += score;
				cnt++;
			}
			score++;
		}
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int t,n;
	vector<int> arr;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int* numbers = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> numbers[j];
		}
		
		for (int k = 0; k < n; k++) {
			if (!findc(arr, numbers[k]) && findn(numbers, numbers[k], n) == 6) {
				arr.push_back(numbers[k]);
			}
		}
		int min = 2147483646;
		int minteam = 0;
		for (auto it : arr) {
			int score = getscore(arr, numbers, it, n);
			if (score < min) {
				min = score;
				minteam = it;
			}
			else if (score == min) {
				if (findfive(numbers, it, n) < findfive(numbers, minteam, n)) {
					min = score;
					minteam = it;
				}
			}
		}
		cout << minteam << "\n";
		delete[] numbers;
	}
	
	
	

	
	return 0;
}
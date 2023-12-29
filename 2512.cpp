#include <iostream>
#include <algorithm>

using namespace std;
int answer;
int arr[10000];
int n, m;
int calcBudget(int mid) {
	int sum = 0;

	for (int i = 0; i < n; i++) { 
		if (arr[i] > mid) {
			
			sum += mid;
		}
		else {
			
			sum += arr[i];
		}
	}

	return sum;
}

void biSearch(int start, int end) {
	int mid = (start + end) / 2;
	int result = calcBudget(mid);

	if (start > end) {
		return;
	}

	if (result <= m) {
		answer = mid;

		// ���Ѿ��� �ִ��� ���ϱ� ���� �������� �̵� 
		biSearch(mid + 1, end);
	}
	else {
		// ���Ѿ��� ���̱� ���� �������� �̵� 
		biSearch(start, mid - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

	}
	
	cin >> m;
	int end = *max_element(arr, arr + n);
	biSearch(1, end);

	cout << answer;

	return 0;
}

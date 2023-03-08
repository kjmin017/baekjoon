#include <stdio.h>
#include <iostream>
using namespace std;
int arr[41][2] = {};


int setfibonacci(int n) {

    if (n == 0) {
        arr[n][0] = 1;
        arr[n][1] = 0;
    }
    else if (n == 1) {
        arr[n][0] = 0;
        arr[n][1] = 1;
    }
    else {
        arr[n][0] = arr[n - 1][0] + arr[n - 2][0];
        arr[n][1] = arr[n - 1][1] + arr[n - 2][1];
    }
    return 0;
}
int main(void) {
    int t;
    int N = 0;
    cin >> N;
    for (int i = 0; i < 41; i++) {
        setfibonacci(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> t;

        cout << arr[t][0] << " " << arr[t][1] << endl;
    }
    return 0;
}
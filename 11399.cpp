#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int t;
    int sum=0;

    cin >> t;
    int numbers[t];
    for(int i=0; i<t; i++){
            cin >> numbers[i];
        }
    sort(numbers, numbers + t);
    sum = numbers[0];
    for(int i=1; i<t; i++){
        numbers[i] +=numbers[i-1];
        sum +=numbers[i];
    }
    cout << sum;
    return 0;
}
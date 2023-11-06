#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int fiveCount = n / 5;
    n %= 5;

    while (fiveCount >= 0) {
        if (n % 3 == 0) { 
            cout << fiveCount + (n / 3) << endl; 
            return 0;
        }
        fiveCount--; 
        n += 5; 
    }

    cout << -1 << endl;

    return 0;
}

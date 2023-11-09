#include <iostream>
using namespace std;

void initAndPrint(int a, int b) {
    int** apt = new int*[a];
    for (int i = 0; i < a; i++) {
        apt[i] = new int[b];
    }

    for (int i = 0; i < b; i++) {
        apt[0][i] = i + 1;
    }

    for (int k = 1; k < a; k++) {
        for (int i = 0; i < b; i++) {
            apt[k][i] = apt[k-1][i];
            if (i > 0) {
                apt[k][i] += apt[k][i-1];
            }
        }
    }

    cout << apt[a-1][b-1] << endl;

    for (int i = 0; i < a; i++) {
        delete[] apt[i];
    }
    delete[] apt;
}

int main() {
    int t, k, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> k >> n;
        initAndPrint(k + 1, n); 
    }

    return 0;
}




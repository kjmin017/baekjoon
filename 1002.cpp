#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int getmax(int a, int b){
    if(a>b)
        return a;
    else   
        return b;
}
int getmin(int a, int b){
    if(a <b)
        return a;
    else 
        return b;
}
int main(void) {
    int x1, y1, x2, y2, r1, r2;
    int N=0;
    int distance;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if (x1 == x2 && y1 == y2) {
            if (r1 == r2)
                cout << -1<< endl;
            else
                cout << 0 << endl;
        }
        else {
            distance = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
            int rad = (r2 + r1) * (r2 + r1);
            if (distance < rad) {

                if (getmax(r2, r1) == (sqrt(distance) + getmin(r2, r1))) {
                    cout << 1 << endl;
                }
                else if (getmax(r2, r1) > (sqrt(distance) + getmin(r2, r1)))
                    cout << 0 << endl;
                else
                    cout << 2 << endl;
            }
            else if (distance == rad) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
	return 0;
}

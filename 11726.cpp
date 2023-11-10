#include <stdio.h>
#include <iostream>
using namespace std;
int dp[1000]= {0};

int main(void) {
    int t;
    int N = 0;
    dp[0] = 1;
    dp[1] = 2;
    cin >> N;
    if(N>2){
        for(int i=2; i<N; i++){
            dp[i] = (dp[i-2] + dp[i-1])%10007;
        }
    }
    cout << dp[N-1] << endl;
    return 0;
}
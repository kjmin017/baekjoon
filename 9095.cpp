#include <iostream>

int dp[11]= {0};

using namespace std;

int main(void) {
    int n;
    int t = 0;
    
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    cin >> t;
    for(int k = 0; k<t; k++){
        cin >> n;
        for(int i =4; i<=n; i++){
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }

        cout << dp[n] << endl;
    }
    
    

    return 0;
}
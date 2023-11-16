#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000000]= {0};

using namespace std;

int main(void) {
    int n;
    int cnt = 0;
    cin >> n;

    if(n==1){
        cout << 0;
    }
    else{
        for(int i =2; i<=n; i++){
            dp[i] = dp[i - 1] + 1;

            if (i % 2 == 0) {
                dp[i] = min(dp[i], dp[i / 2] + 1);
            }

            if (i % 3 == 0) {
                dp[i] = min(dp[i], dp[i / 3] + 1);
            }
        }

        cout << dp[n];
    }
    

    return 0;
}

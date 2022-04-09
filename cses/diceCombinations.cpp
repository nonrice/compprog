#include <iostream>
#include <vector>

#define MOD 1000000007

int main(){
    int n;
    std::cin >> n;
    std::vector<int> dp(n+1);

    dp[0] = 1;
    for (int i=1; i<=n; ++i){
        for (int d=1; d<=6; ++d){
            if (i-d >= 0)
                dp[i] = (dp[i] + dp[i-d])%MOD;
        }
    }

    std::cout << dp[n] << '\n';
}

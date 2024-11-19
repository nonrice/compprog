#include <iostream>
#include <vector>
#include <algorithm>

#define MAXX 1000001

int main(){
    int n, x;
    std::cin >> n >> x;
    std::vector<int> coins(n);
    for (int i=0; i<n; ++i)
        std::cin >> coins[i];
    
    std::vector<int> dp(x+1, MAXX);
    for (int v:coins){
        if (v <= x)
            dp[v] = 1;
    }

    for (int i=0; i<=x; ++i){
        for (int v:coins){
            if (i-v >= 0 && dp[i-v])
                dp[i] = std::min(dp[i], dp[i-v]+1);
        }
    }
    
    std::cout << ((dp[x] == MAXX) ? -1 : dp[x]) << '\n';
}

#include <iostream>
#include <vector>
#include <numeric>

// 1-0 knapsack

int main(){
    int n, x; std::cin >> n >> x;
    std::vector<int> h(n);
    std::vector<int> s(n);
    for (int& hi:h) std::cin >> hi;
    for (int& si:s) std::cin >> si;

    std::vector<std::vector<int>> dp(n+1, std::vector<int>(x+1));
    for (int r=1; r<=n; ++r){
        for (int c=0; c<=x; ++c){
            if (h[r-1]<=c){
                dp[r][c] = std::max(
                    dp[r-1][c],
                    dp[r-1][c-h[r-1]] + s[r-1]
                );
            } else {
                dp[r][c] = dp[r-1][c];
            }
        }
    }

    std::cout << dp[n][x] << '\n';
}


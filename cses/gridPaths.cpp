#include <iostream>
#include <vector>
#include <string>

#define MOD 1000000007

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    std::string row;
    for (int r=0; r<n; ++r){
        std::cin >> row;
        for (int c=0; c<n; ++c){
            if (row[c] == '*')
                dp[r][c] = -1;
        }
    }
    
    ++dp[0][0]; // Turn -1 into 0, 0 into 1, cool trick
    for (int r=0; r<n; ++r){
        for (int c=0; c<n; ++c){
            if (dp[r][c] == -1){
                dp[r][c] = 0;
            } else {
                if(r) dp[r][c]+=dp[r-1][c];
                if(c) dp[r][c]+=dp[r][c-1];
                dp[r][c] %= MOD;
            }
        }
    }

    std::cout << dp[n-1][n-1] << '\n';
}

#include <iostream>
#include <vector>
#include <numeric>

#define MAXN 1000

//KNAP SACK
void solve(std::vector<int>& ws){
    int n, k; std::cin >> n >> k;
    std::vector<int> w(n);
    int max_k = 0;
    for (int i=0; i<n; ++i){
        int a; std::cin >> a;
        w[i] = ws[a];
        max_k += w[i];
    }
    std::vector<int> v(n);
    for (int& a:v)
        std::cin >> a;

    k = std::min(max_k, k);
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(k+1));
    for (int r=1; r<=n; ++r){
        for (int c=0; c<=k; ++c){
            if (c >= w[r-1]){
                dp[r][c] = std::max(
                    dp[r-1][c],
                    dp[r-1][c-w[r-1]] + v[r-1]
                );
            } else {
                dp[r][c] = dp[r-1][c];
            }
        }
    }
    std::cout << dp[n][k] << '\n';
}

int main(){
    // lesson: precompute values for all testcases when possible
    // lesson: never use greedy for unbounded knapsack
    std::vector<int> ws(MAXN+1, MAXN);
    ws[1] = 0;
    for (int i=1; i<=MAXN; ++i){
        for (int x=1; x<=i; ++x){
            int next = i+i/x;
            if (next <= MAXN)
                ws[next] = std::min(ws[next], ws[i]+1);
        }
    }

    int cases; std::cin >> cases;
    while (cases--)
        solve(ws);
}

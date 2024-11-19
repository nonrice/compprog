#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];

int main(){
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    
    int bst = 0;
    for (int r=1; r<=n; ++r){
        for (int c=1; c<=m; ++c){
            if (a[r-1] == b[c-1]){
                dp[r][c] = max(dp[r][c], dp[r-1][c-1] + 2);
            } else {
                dp[r][c] = max(0, max(dp[r-1][c], dp[r][c-1])-1);
            }
            bst = max(bst, dp[r][c]);
        }
    }

    cout << bst << '\n';
}

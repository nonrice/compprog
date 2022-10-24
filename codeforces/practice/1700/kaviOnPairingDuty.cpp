#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int dp[2000001] = { 1 };

int main(){
    int n; cin >> n;
    int sum = 1;
    for (int i=2; i<=2*n; i+=2){
        dp[i] = (dp[i] + sum) % MOD;
        sum = (sum + dp[i]) % MOD;
        for (int j=i+i; j<=2*n; j+=i){
            ++dp[j];
        }
    }
    cout << dp[2*n]<< '\n';
}

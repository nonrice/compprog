#include <bits/stdc++.h>
using namespace std;


constexpr long long M = 1e9+7;

char s[500005];

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n; cin >> n;
    cin >> s+1;

    vector<int> pr(n+1), pb(n+1);
    for (int i=1; i<=n; ++i){
        pr[i] = pr[i-1] + (s[i] == 'R');
        pb[i] = pb[i-1] + (s[i] == 'B');
    }

    vector<long long> dp(n+1);
    dp[0] = 1;
    for (int i=1; i<=n; ++i){
        for (int j=i-2; j>=0; j-=2){

            int l = (i-j)/2;
            if (pb[j+l]-pb[j] == 0 && pr[i]-pr[j+l] == 0){
                for (int k=0; k<=j; ++k){
                    if (pr[j]-pr[k]==0 && pb[j]-pb[k]==0){
                        dp[i] = (dp[i] + dp[k]) % M;
                    }
                }
            }
        }
    }

    long long ans = 0;
    for (int i=1; i<=n; ++i){
        if (pr[n]-pr[i]==0 && pb[n]-pb[i]==0){
            ans = (ans + dp[i]) % M;
        }
    }
    cout << ans << '\n';

}
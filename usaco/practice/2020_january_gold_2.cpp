//notmycode

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int W = 5e3;
const int N = 2e6;
long long dp[W][W];
int a[W], k[W];
vector<int> lk(N*2+1, -1);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
    int n, q; cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> a[i];
        lk[-a[i]+N]=i;
    }
    for(int j=0; j<n; j++){
        for(int i=j+1; i<n; i++){
            dp[i][j]+=k[lk[-a[i]+N]];
            int key = a[i]+a[j]+N;
			k[lk[key]] += (lk[key]!=-1);
        }
        for(int i=j+1; i<n; i++)k[lk[-a[i]+N]]=0;
    }
    for(int i=1; i<n; i++){
        long long sum = 0;
        for(int j=i; j>=0; j--){
            sum+=dp[i][j];
            dp[i][j]=sum+dp[i-1][j];
        }
    }
    while(q--){
        int l, r; cin >> l >> r;
        l--;
        cout << dp[r-1][l]-dp[l][l] << '\n';
    }
    return 0;
}

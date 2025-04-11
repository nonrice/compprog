#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr int N = 10000000;

bool s[N+1];
vector<int> p;

void solve(){
    int n; cin >> n;
    
    int ans = 0;
    for (int i=0; i<p.size() && p[i]<=n; ++i){
        ans += n/p[i];
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    for (int d=2; d<=N; ++d){
        for (int i=d+d; i<=N; i+=d){
            s[i] = true;
        }
    }
    for (int i=2; i<=N; ++i){
        if (!s[i]){
            p.push_back(i);
        }
    }

    int t; cin >> t;
    while (t--){
        solve();
    }
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n; cin >> n;
    vector<int> p(n);
    for (int& v : p) cin >> v;

    vector<vector<int>> pr(n+1, vector<int>(n+1));
    for (int b=1; b<=n; ++b){
        for (int d=b+1; d<=n; ++d){
            pr[b][d] = pr[b-1][d] + pr[b][d-1] - pr[b-1][d-1] + (p[b-1]>p[d-1]);
            //pr[b][d] = pr[b][d-1] + (p[b-1]>p[d-1]);
        }
    }

    /*
    for (auto& a : pr){
        for (int b : a){
            cout << b << ' ';
        }
        cout << '\n';
    }
    */

    ll ans = 0;
    for (int a=0; a<n; ++a){
        for (int c=a+1; c<n; ++c){
            if (p[a] < p[c])
                ans += pr[c][n] - pr[c][c+1] - pr[a+1][n] + pr[a+1][c+1];
            // a+1 and c+1
            //cout << a+1 << ' ' << c+1 << ':' << pr[c-1][n] - pr[c-1][c] - pr[a][n] + pr[a][c] << '\n';
        }
    }
    
    cout << ans << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}


#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> f(n+1);
    int mex = 0;
    for (int i=0; i<n; ++i){
        int v; cin >> v;
        ++f[v];
        while (f[mex]) ++mex;
    }
    
    for (int i=0; i<=mex; ++i){
        cout << f[i] << ' ';
    }
    
    int lst = mex-1;
    long long cur_ans = 0;
    for (int i=mex+1; i<=n; ++i){
        if (!f[i-1]){
            while (lst>=0 && f[lst] <= 1) --lst;
            if (lst<0) {
                for (; i<=n; ++i) cout << "-1 ";
                break;
            } else {
                cur_ans += i-1-lst;
                --f[lst];
            }
        } else if (f[i-1] >= 2) {
            lst = i-1;
        }
        
        cout << cur_ans+f[i] << ' ';
    }
    
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases; cin >> cases;
    while (cases--) solve();
}

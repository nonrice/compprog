#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k, r, c; cin >> n >> k >> r >> c;
    
    int offs = (r+c)%k;
    vector<string> ans(n);
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j){
            if ((j+i - offs) % k == 0) cout << 'X';
            else cout << '.';
        }
        cout << '\n';
    }
    
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

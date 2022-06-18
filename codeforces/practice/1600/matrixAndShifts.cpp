#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<string> m(n);
    for (string& v : m) cin >> v;
    
    int mx = 0;
    int sum = 0;
    for (int i=0; i<n; ++i){
        int cur = 0;
        for (int j=0; j<n; ++j){
            if (m[(i+j)%n][j] == '1'){
                cur += 1;
                sum += 1;
            }
        }
        mx = max(cur, mx);
    }

    cout << sum-mx + (n-mx) << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}


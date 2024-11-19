#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> f(26);

    for (char ch : s){
        ++f[ch-65];
    }
    
    int ans = 0;
    for (int v : f){
        if (v){
            ans += v+1;
        }
    }

    cout << ans << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

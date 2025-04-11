#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    if (k == 0){
        string t(s);
        reverse(t.begin(), t.end());
        if (s < t){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    for (int i=0; i<n-1; ++i){
        if (s[i] != s[i+1]){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}

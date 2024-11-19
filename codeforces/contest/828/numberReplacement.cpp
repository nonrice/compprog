#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;
    string s; cin >> s;
    
    map<int, char> mp;
    for (int i=0; i<n; ++i){
        if (!mp.count(a[i])) mp[a[i]] = s[i];
        else {
            if (mp[a[i]] != s[i]){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

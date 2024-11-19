#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;

    int mp[10] = {};
    vector<int> a(s.size());
    for (size_t i=0; i<s.size(); ++i){
        a[i] = s[i]-'0';
        ++mp[a[i]];
    }

    int m[10] = {};
    auto cur = a.begin();
    for (int i=0; i<=9; ++i){
        m[i] = count(cur, a.end(), i);
        if (m[i]) {
            cur = (find(a.rbegin(), a.rend(), i)+1).base();
        }
    }

    for (int i=0; i<=9; ++i) mp[i] -= m[i];
    rotate(mp, mp+9, mp+10);
    mp[9] += mp[0];
    mp[0] = 0;
    for (int i=0; i<=9; ++i) mp[i] += m[i];

    for (int i=0; i<=9; ++i){
        for (int j=0; j<mp[i]; ++j) cout << i;
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

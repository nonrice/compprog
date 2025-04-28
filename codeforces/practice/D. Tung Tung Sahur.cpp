#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    string p; cin >> p;
    string s; cin >> s;

    if (s[0] != p[0]){
        cout << "NO\n";
        return;
    }

    vector<int> l1({ 1 });
    for (int i=1; i<p.size(); ++i){
        if (p[i] != p[i-1]){
            l1.push_back(1);
        } else {
            l1.back() += 1;
        }
    }
    vector<int> l2({ 1 });
    for (int i=1; i<s.size(); ++i){
        if (s[i] != s[i-1]){
            l2.push_back(1);
        } else {
            l2.back() += 1;
        }
    }

    if (l1.size() != l2.size()){
        cout << "NO\n";
        return;
    }

    for (int i=0; i<l1.size(); ++i){
        if (l2[i] > l1[i]*2 || l1[i] > l2[i]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}

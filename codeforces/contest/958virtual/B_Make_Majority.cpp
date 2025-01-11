#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<bool> a;
    for (int i=0; i<n; ++i){
        if (s[i] == '0'){
            if (a.size()==0 || a.back()){
                a.push_back(false);
            }
        } else {
            a.push_back(true);
        }
    }

    int c0 = 0, c1 = 0;
    for (int i=0; i<a.size(); ++i){
        if (a[i]){
            ++c1;
        } else {
            ++c0;
        }
    }

    debug(a);
    if (c1 > c0){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
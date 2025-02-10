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

    vector<int> r({ 0 }), l({ 0 });
    for (int i=0; i<n; ++i){
        if (s[i] == '<'){
            l.push_back(i);
        } else {
            r.push_back(i);
        }
    }

    for (int i=1; i<r.size(); ++i){
        r[i] += r[i-1];
    }
    for (int i=1; i<l.size(); ++i){
        l[i] += l[i-1];
    }
    
    long long s = 0;
    for (int i=0; i<n; ++i){


    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
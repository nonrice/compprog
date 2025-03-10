#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    string s; cin >> s;
    const int n = s.size();

    vector<vector<int>> f(26, vector<int>(n+1));
    for (int i=0; i<n; ++i){
        ++f[s[i]-'a'][i+1];
        for (int j=0; j<26; ++j){
            f[j][i+1] += f[j][i];
        }
    }

    int l = -1;
    while (l+1 <= n/2-1 && s[l+1]==s[n-l-2]){
        ++l;
    }
    int w = n/2;
    while (w-1 >= 0 && s[w-1]==s[n-w]){
        --w;
    }

    auto chk_ss = [&](int l, int r){
        int m = n/2-1;
        if (l<=m && r<=m){

        }
    }

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
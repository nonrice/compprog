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

    string t(s);
    sort(t.begin(), t.end());

    int o0 = 0, o1 = 0;
    bool e1 = false;
    for (int i=0; i<n; ++i){
        e1 |= (s[i] == '1');
        if (s[i] == '0'){
            o0 += e1;
        }
    }
    bool e0 = false;
    for (int i=n-1; i>=0; --i){
        e0 |= (s[i] == '0');
        if (s[i] == '1'){
            o1 += e0;
        }
    }

    if (o0 == 1 || :wq
    )


}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}

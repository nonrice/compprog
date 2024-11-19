#include <bits/stdc++.h>
using namespace std;

short e[300000], o[300000], ans[300000];

void solve(){
    string s; cin >> s;
    
    int l1=0, l2=0;
    for (size_t i=0; i<s.size(); ++i){
        short d = s[i]-'0';

        if (d&1) e[l1++] = d;
        else o[l2++] = d;
    }
    
    merge(e, e+l1, o, o+l2, ans); // ub???

    for (int i=0; i<l1+l2; ++i){
        cout << ans[i];
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

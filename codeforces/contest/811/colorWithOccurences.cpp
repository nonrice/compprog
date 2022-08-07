#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int q; cin >> q;
    int n = s.size();
    vector<pair<int, int>> bst(n);
    for (int i=1; i<=q; ++i){
        string t; cin >> t;
        for (size_t p=s.find(t); p!=string::npos; p=s.find(t, p+1)){
            bst[p] = max(bst[p], {(int)t.length(), i});
        }
    }
    /*
    for (auto [a, b] : bst){
        cout << a << ' ';
    }
    cout << '\n';*/

    int ans = 0;
    vector<pair<int, int>> ans_v;
    int p2 = 0;
    int mxp2 = 0;
    for (int i=0; i<n;){
        for (; p2<=i; ++p2){
            if (bst[p2].first+p2-i > bst[mxp2].first+mxp2-i) mxp2 = p2;
        }
        if (bst[mxp2].first+mxp2-i == 0){
            cout << "-1\n";
            return;
        }
        ans_v.emplace_back(bst[mxp2].second, mxp2+1);
        i += bst[mxp2].first+mxp2-i;
        ++ans;
    }
    cout << ans << '\n';
    for (auto [a, b] : ans_v) cout << a << ' ' << b << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases; cin >> cases;
    while (cases--) solve();
}

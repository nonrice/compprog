#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int& v : a) cin >> v;
    for (int& v : b) cin >> v;
    
    //int bgn = max_element(a.begin(), a.end()) - a.begin();
    int bgn = 0;
    for (int i=1; i<=n; ++i){
        int idx = bgn-i;
        if (idx < 0) idx += n;
        int pr_idx = idx-1;
        if (pr_idx < 0) pr_idx += n;

        //cout << idx << ':' << pr_idx << ' ';

        if (a[idx] > b[idx] || (b[pr_idx] > b[idx]+1 && a[pr_idx]!=b[pr_idx])){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while(cases--) solve();
}

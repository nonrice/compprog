#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;
    
    int depth = 0;
    int lvs = 0;
    int prev_lvs = 1;
    for (int i=1; i<n;){
        for (int j=0; j<prev_lvs; ++j, ++i){
            while (i+1<n && a[i] < a[i+1]) ++i, ++lvs;
            ++lvs;
        }
        //cout << lvs << ' ' << i << '\n';
        prev_lvs = lvs;
        lvs = 0;
        ++depth;
    }

    cout << depth << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int h, n; cin >> h >> n;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    
    bool odd = true;
    int ans = 0;
    for (int i=0; i<n; ++i){
        int cur_len = 1;
        while (i+1<n && a[i+1] == a[i]-1) ++i, ++cur_len;
        if (odd != cur_len%2 && a[i]>1) ++ans;
        odd &= 0;
    }
    
    cout << ans << '\n';
}
 
int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

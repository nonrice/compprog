#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int zc = 0;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        if (a[i] == 0){
            ++zc;
        }
    }

    auto it = find(a.begin(), a.end(), 0);
    if (it == a.end()){
        cout << n << '\n';
        return;
    }

    int z = it - a.begin();
    vector<int> mn(n);
    mn[0] = a[0];
    for (int i=1; i<n; ++i){
        mn[i] = mn[i-1];
        if (a[i]==0 && i!=z){
            continue;
        }
        mn[i] = min(mn[i], a[i]);
    }

    int c = 0;
    vector<bool> v(n+1);
    vector<int> mx(n);
    for (int i=n-1; i>=0; --i){
        if (a[i]==0 && i!=z){
            continue;
        }
        if (a[i]<=n){
            v[a[i]] = true;
        }
        while (v[c]){
            ++c;
        }
        mx[i] = c;
    }

    for (int i=0; i+1<n; ++i){
        if (mn[i] < mx[i+1]){
            cout << n-zc << '\n';
            return;
        }
    }

    cout << n-zc+1 << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}

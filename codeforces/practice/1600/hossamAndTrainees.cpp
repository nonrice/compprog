#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int a[100000];

void solve(){
    int n; cin >> n;
    for (int i=0; i<n; ++i) cin >> a[i];

    unordered_set<int> f;
    for (int i=0; i<n; ++i){
        if (f.count(a[i])) goto yes;
        for (int cur=2; cur*cur<=a[i]; ++cur){
            if (a[i]%cur == 0){
                if (f.count(cur) || f.count(a[i]/cur)) goto yes;
                f.insert(cur);
                f.insert(a[i]/cur);
            }
        }
        f.insert(a[i]);
    }

    cout << "NO\n";
    return;

yes:
    cout << "YES\n";
    return;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

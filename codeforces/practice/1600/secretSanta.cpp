#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> from(n+1);
    vector<bool> c(n+1);
    int satisfied = 0;
    for (int i=0; i<n; ++i){
        cin >> b[i];
        a[i] = b[i];
        if (c[a[i]]) {
            b[i] = 0;
        } else {
            ++satisfied;
            from[a[i]] = i;
            c[a[i]] = true;
        }
    }
    
    auto it = c.begin()+1;
    for (int i=0; i<n; ++i){
        it = find(it, c.end(), false);
        if (!b[i]){
            b[i] = it-c.begin();
            *it = true;
        }
    }

    for (int i=0; i<n; ++i){
        if (b[i] == i+1){
            swap(b[i], b[from[a[i]]]);
        }
    }
    
    cout << satisfied << '\n';
    for (int v : b) cout << v << ' ';
    cout << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }   

    vector<int> p(n);
    set<int> v1;
    int m1 = 0;
    for (int i=0; i<n; ++i){
        v1.insert(a[i]);
        while (v1.count(m1)){
            ++m1;
        }
        p[i] = m1;
    }

    vector<int> s(n);
    set<int> v2;
    int m2 = 0;
    for (int i=n-1; i>=0; --i){
        v2.insert(a[i]);
        while (v2.count(m2)){
            ++m2;
        }
        s[i] = m2;
    }

    debug(p);
    debug(s);

    for (int i=0; i+1<n; ++i){
        if (p[i] == s[i+1]){
            cout << "2\n";
            cout << "1 " << i+1 << '\n';
            cout << i+2 << ' ' << n << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
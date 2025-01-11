#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, q; cin >> n >> q;

    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    multiset<pair<long long, int>> f, b;
    for (int i=0; i<n; ++i){
        f.emplace(a[i] - i, i);
        b.emplace(a[i] + i, i);
    }


    for (int z=0; z<=q; ++z){
        debug(f, b);

        bool f_w = f.rbegin()->second > f.begin()->second;
        bool b_w = b.rbegin()->second < b.begin()->second;
        long long f_a = f.rbegin()->first - f.begin()->first;
        long long b_a = b.rbegin()->first - b.begin()->first;
        if (f_w && b_w){
            cout << max(f_a, b_a) << '\n';
        } else if (f_w){
            cout << f_a << '\n';
        } else if (b_w){
            cout << b_a << '\n';
        } else {
            cout << "0\n";
        }

        if (z != q){
            int p; cin >> p;
            long long x; cin >> x;
            --p;
            f.erase(f.find(make_pair(a[p] - p, p)));
            f.emplace(x - p, p);
            b.erase(b.find(make_pair(a[p] + p, p)));
            b.insert(make_pair(x + p, p));
            a[p] = x;
        }
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
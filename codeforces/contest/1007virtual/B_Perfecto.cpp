#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

set<long long> h;

void solve(){
    long long n; cin >> n;
    if (h.count(n*(n+1)/2)){
        cout << "-1\n";
        return;
    }

    pair<int, int> a = { 5, 6 };
    auto [x, y] = a;

    vector<long long> v(n);
    for (int i=0; i<n; ++i){
        v[i] = i+1;
    }
    while (true){
        shuffle(v.begin(), v.end(), rng);
        long long s = 0;
        bool f = false;
        for (int i=0; i<n; ++i){
            s += v[i];
            if (h.count(s)){
                f = true;
                break;
            }
        }
        if (!f){
            break;
        }
    }

    for (int i=0; i<n; ++i){
        cout << v[i] << ' ';
    }

    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    for (long long x=0; x<=1000000; ++x){
        h.insert(x*x);
    }

    int t; cin >> t;
    while (t--){
        solve();
    }
}

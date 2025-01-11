#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int t = 1000000;
    cout << t << '\n';
    while (t--){
        int n = 8;
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                cout << ((randint(0, 16) < 4) ? randint(0, 2) : 0) << ' ';
            }
            cout << '\n';
        }
    }
}
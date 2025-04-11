#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

#define INTERACTIVE

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Select int from interval [l, r]
int randint(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}

int ask(int i, int j, int k){
    cout << "? " << i << ' ' << j << ' ' << k << endl;
    int x; cin >> x;
    if (x == -1){
        exit(0);
    }
    return x;
}

void ans(int i, int j, int k){
    cout << "! " << i << ' ' << j << ' ' << k << endl;
}

void solve(){
    int n; cin >> n;
    if (n == -1){
        exit(0);
    }
    int i=randint(1, n), j=1, k=1;
    while (j == i){
        j = randint(1, n);
    }
    while (k == j || k == i){
        k = randint(1, n);
    }

    int w = ask(i, j, k);
    while (w != 0){
        int r = randint(1, 3);
        if (r == 1){
            i = w;
        } else if (r == 2){
            j = w;
        } else {
            k = w;
        }
        w = ask(i, j, k);
    }

    ans(i, j, k);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}

#include <bits/stdc++.h>
using namespace std;

#define INTERACTIVE

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

int ask(int a, int b, int c, int d){
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    char r; cin >> r;
    if (r == '>'){
        return 1;
    } else if (r == '='){
        return 0;
    } else {
        return -1;
    }
}

void solve(){
    int n; cin >> n;

    int mx = 0;
    for (int i=0; i<n; ++i){
        if (ask(i, i, mx, mx) == 1){
            mx = i;
        }
    }

    map<int, vector<int>> f;
    int c = 0;
    for (int i=0; i<n; ++i){
        int r = ask(i, mx, c, mx);
        if (i != mx && r == 1){
            c = i;
            f[c].push_back(c);
        } else if (r == 0){
            f[c].push_back(i);
        }
    }

    int t = f[c][0];
    for (auto v : f[c]){
        if (ask(v, v, t, t) == -1){
            t = v;
        }
    }

    cout << "! " << mx << ' ' << t << endl;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
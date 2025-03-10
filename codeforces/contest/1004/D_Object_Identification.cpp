#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

#define INTERACTIVE

int ask(int i, int j){
    cout << "? " << i+1 << ' ' << j+1 << endl;
    int x; cin >> x;
    if (x == -1){
        exit(0);
    }
    return x;
}

void solve(){
    int n; cin >> n;
    vector<int> x(n);
    for (int i=0; i<n; ++i){
        cin >> x[i];
        --x[i];
    }

    vector<int> p(n, -1);
    for (int i=0; i<n; ++i){
        p[x[i]] = i;
    }

    if (p[0] != -1 && p[n-1] != -1){
        int l1 = ask(p[0], p[n-1]);
        int l2 = ask(p[n-1], p[0]);

        if (l1 != l2){
            cout << "! A" << endl;
        } else {
            if (l1 >= n-1){
                cout << "! B" << endl;
            } else {
                cout << "! A" << endl;
            }
        }
    } else {
        int l = ask((p[0] == -1) ? 0 : n-1, 1);
        if (l == 0){
            cout << "! A" << endl;
        } else {
            cout << "! B" << endl;
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
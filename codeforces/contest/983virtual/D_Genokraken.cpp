#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

#define INTERACTIVE

bool ask(int u, int v){
    cout << "? " << u << ' ' << v << endl;
    int r; cin >> r;
    if (r == -1){
        exit(0);
    }
    return r==1;
}

void solve(){
    int n; cin >> n;

    vector<int> p(n);

    int x = 2;
    for (; x<n; ++x){
        bool r = ask(1, x);
        if (!r){
            p[x] = 1;
            ++x;
            break;
        }
    }

    list<int> t;
    for (int i=1; i<x-1; ++i){
        t.push_back(i);
    }
    *t.begin() = x-1;

    auto t_it = (t.size()==1) ? t.begin() : ++t.begin();
    for (; x<n; ++x){
        if (ask(*t_it, x)){
            t_it = t.erase(t_it);
            if (t_it == t.end()){
                t_it = t.begin();
            }
            --x;
            continue;
        }
        p[x] = *t_it;
        *t_it = x;
        ++t_it;
        if (t_it == t.end()){
            t_it = t.begin();
        }
    }

    cout << "! ";
    for (int i=1; i<n; ++i){
        cout << p[i] << ' ';
    }
    cout << endl;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
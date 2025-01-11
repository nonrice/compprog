#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

struct seg {
    int l;
    bool c;

    seg(int l, bool c) : l(l), c(c) {}
};

void print(seg s){
    cerr << '(' << s.l << ' ' << s.c << ") ";
}

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    list<seg> f;
    for (int i=0; i<n; ++i){
        if (f.empty() || f.back().c != (s[i] == '1')){
            f.emplace_back(1, s[i]=='1');
        } else {
            ++f.back().l;
        }
    }

    map<int, int> h;
    for (auto [l, c] : f){
        ++h[l];
    }


    list<seg> b;
    for (int p=1; p<=n; ++p){
        --h[f.front().l];
        if (h[f.front().l] == 0){
            h.erase(f.front().l);
        }   
        --f.front().l;
        if (f.front().l != 0){ 
            ++h[f.front().l];
        }

        if (b.empty() || f.front().c != b.front().c){
            b.emplace_front(1, f.front().c);
            ++h[1];
        } else {
            --h[b.front().l];
            if (h[b.front().l] == 0){
                h.erase(b.front().l);
            }
            ++b.front().l;
            ++h[b.front().l];
        }

        if (f.front().l == 0){
            f.pop_front();
        }

        if (!f.empty() && f.back().c != b.front().c){
            if (h[k] == n/k){
                cout << p << '\n';
                return;
            }
        } else {
            debug(f, b);
            debug(h);
            if (h[k] == n/k - 1 && f.back().l+b.front().l==k && ((h[f.back().l]==1 && h[b.front().l]==1) || (f.back().l==b.front().l && h[f.back().l]==2))){
                cout << p << '\n';
                return;
            }
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

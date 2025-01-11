#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

bool getb(uint32_t x, int i){
    return (x>>i)&1;
}

uint32_t setb(uint32_t x, int i, bool b){
    if (b){
        return x | (1<<i);
    }
    return x & (~(1<<i));
}

void solve(){
    uint32_t l, r;
    cin >> l >> r;

    uint32_t b=r, c=l;
    bool p = true;
    for (int i=31; i>=0; --i){
        if (getb(r, i) != getb(l, i)){
            p = false;
            continue;
        }

        if (!p){
            if (getb(r, i) == getb(l, i)){
                if (getb(r, i)){
                    b = setb(b, i, 0);
                } else {
                    c = setb(c, i, 1);
                }
            }
        }
    }

    uint32_t a = l+1;
    if (b != r){
        a = r;
    } else if (c != l){
        a = l;
    }
    debug((a^b) + (b^c) + (a^c));
    cout << a << ' ' << b << ' ' << c << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
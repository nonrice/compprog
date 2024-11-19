#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    vector<int> t;
    int n;
    
    SegTree(int sz){
        n = sz;
        t = vector<int>(sz*2);
    }

    void modify(int i, int v){
        for (t[i+=n] = v; i>1; i/=2){
            t[i/2] = t[i] + t[i^1];
        }
    }

    int query(int l, int r){
        int total = 0;
        for (l+=n, r+=n; l<r; l/=2, r/=2){
            if (l%2) total += t[l++];
            if (r%2) total += t[--r];
        }
        return total;
    }
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int q; cin >> q;

    SegTree rt(n+1), ct(n+1);
    vector<int> rv(n+1), cv(n+1);

    while (q--){
        int t; cin >> t;
        if (t == 1){
            int r, c; cin >> r >> c;
            rt.modify(r, 1);
            ct.modify(c, 1);
            ++rv[r];
            ++cv[c];
        } else if (t == 2){
            int r, c; cin >> r >> c;
            if (!--rv[r]) rt.modify(r, 0);
            if (!--cv[c]) ct.modify(c, 0);
        } else if (t == 3){
            int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
            if (rt.query(r1, r2+1) == r2-r1+1 || ct.query(c1, c2+1) == c2-c1+1){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

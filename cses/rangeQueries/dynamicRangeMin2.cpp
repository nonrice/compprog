#include <bits/stdc++.h>
using namespace std;

template<typename T, T (*F)(T, T), T D = T{}>
struct segtree_sparse {
    struct node {
        node *lc=nullptr, *rc=nullptr;
        int lb, rb, m;
        T x;

        node(int lb, int rb) : lb(lb), rb(rb) {
            m = (lb+rb)/2;
            x = D;
        }

        void set(int i, T v){
            if (lb == rb){
                x = v;
                return;
            }

            if (i <= m){
                (!lc ? (lc = new node(lb, m)) : lc)->set(i, v);
            } else {
                (!rc ? (rc = new node(m+1, rb)) : rc)->set(i, v);
            }

            x = F(lc ? lc->x : D, rc ? rc->x : D);
        }

        T query(int l, int r){
            if (l<=lb && r>=rb){
                return x;
            }
            T s = D;
            if (l<=m){
                s = F(s, lc ? lc->query(l, r) : D);
            }
            if (r>m){
                s = F(s, rc ? rc->query(l, r) : D);
            }
            return s;
        }

        ~node(){
            delete lc;
            delete rc;
        }
    };

    node* t;

    // construct root on [l, r]
    segtree_sparse(int l, int r) {
        t = new node(l, r);
    }

    // set index i to v 
    void set(int i, int v){
        return t->set(i, v);
    }

    // query [l, r)
    T query(int l, int r){
        return t->query(l, r-1);
    }

    ~segtree_sparse(){
        delete t;
    }
};

int c_min(int a, int b){
    return min(a, b);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n, q; cin >> n >> q;
    segtree_sparse<int, c_min, INT_MAX> st(0, n-1);
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        st.set(i, x);
    }

    while (q--){
        int t; cin >> t;
        if (t == 1){
            int i, x; cin >> i >> x;
            --i;
            st.set(i, x);
        } else {
            int l, r; cin >> l >> r;
            --l;
            cout << st.query(l, r) << '\n';
        }
    }
}

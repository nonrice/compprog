// https://cses.fi/problemset/task/1651

#include <bits/stdc++.h>
using namespace std;

template<typename T, typename U>
struct segtree_sparse {
    struct node {
        node *lc=nullptr, *rc=nullptr;
        U lb, rb, m;
        T x;

        node(U lb, U rb) : lb(lb), rb(rb) {
            m = (lb+rb)/2;
            x = T{};
        }

        void set(U i, T v){
            if (lb == rb){
                x = v;
                return;
            }

            if (i <= m){
                get_lc()->set(i, v);
            } else {
                get_rc()->set(i, v);
            }

            x = get_lc()->x + get_rc()->x;
        }

        T query(U l, U r){
            if (l<=lb && r>=rb){
                return x;
            }
            T s{};
            if (l<=m){
                s += get_lc()->query(l, r);
            }
            if (r>m){
                s += get_rc()->query(l, r);
            }
            return s;
        }

        node* get_lc(){
            if (lc == nullptr){
                lc = new node(lb, m);
            }
            return lc;
        }

        node* get_rc(){
            if (rc == nullptr){
                rc = new node(m+1, rb);
            }
            return rc;
        }

        ~node(){
            delete lc;
            delete rc;
        }
    };

    node* t;

    segtree_sparse(U l, U r) {
        t = new node(l, r);
    }

    void set(U i, T v){
        return t->set(i, v);
    }

    T query(U l, U r){
        return t->query(l, r);
    }

    ~segtree_sparse(){
        delete t;
    }
};

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
{
    int n, q; cin >> n >> q;
    segtree_sparse<long long, int> t(0, n-1);
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        t.set(i, x);
    }

    while (q--){
        int c; cin >> c;
        if (c == 1){
            int i, v; cin >> i >> v;
            --i;
            t.set(i, v);
        } else {
            int l, r; cin >> l >> r;
            --l, --r;
            cout << t.query(l, r) << '\n';
        }
    }
}
}


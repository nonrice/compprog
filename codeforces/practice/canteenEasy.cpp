#include <bits/stdc++.h>
using namespace std;

template<typename T, T (*F)(T, T), T D = T{}, typename I=int>
struct segtree_sparse {
    struct node {
        node *lc=nullptr, *rc=nullptr;
        I lb, rb, m;
        T x;

        node(I lb, I rb) : lb(lb), rb(rb) {
            m = (lb+rb - (lb+rb<0))/2;
            x = D;
        }

        void set(I i, T v){
            //cerr << '(' << i << ' ' << v << ' ' << lb << ' ' << rb <<  ')' << '\n';
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

        T query(I l, I r){
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
    segtree_sparse(I l, I r) {
        t = new node(l, r);
    }

    // set index i to v 
    void set(I i, I v){
        return t->set(i, v);
    }

    // query [l, r)
    T query(I l, I r){
        return t->query(l, r-1);
    }
    ~segtree_sparse(){
        delete t;
    }
};



int c_min(int a, int b){
    return min(a, b);
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<n; ++i){
        cin >> b[i];
    }
    
    vector<int> d(2*n);
    for (int i=0; i<n; ++i){
        d[i] = b[i]-a[i];
    }
    copy(d.begin(), d.begin()+n, d.begin()+n);

    vector<long long> p(2*n+1);
    for (int i=1; i<=2*n; ++i){
        p[i] = p[i-1]+d[i-1];
    }
    
    long long mx = *max_element(p.begin(), p.end());
    segtree_sparse<int, c_min, INT_MAX, long long> st(*min_element(p.begin(), p.end()), mx);
    for (int i=2*n; i>n; --i){
        st.set(p[i], i);
    }
    int ans = 1;
    for (int i=n; i>=1; --i){
        if (d[i-1] >= 0){
            continue;
        }
        int j = st.query(p[i]-d[i-1], mx+1);
        ans = max(ans, j-i+1);
        st.set(p[i], i);
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}

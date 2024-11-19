#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegTree {
    vector<T> t;
    int n;
    
    SegTree(vector<T>& a){
        n = a.size();
        t = vector<T>(n*2);
        for (int i=n*2-1; i>=0; --i){
            t[i] = (i >= n) ? a[i-n] : t[i*2]|t[i*2+1];
        }
    }

    void modify(int i, T v){
        for (t[i+=n] = v; i>1; i/=2){
            t[i/2] = t[i] | t[i^1];
        }
    }

    T query(int l, int r){
        T total = 0;
        for (l+=n, r+=n; l<r; l/=2, r/=2){
            if (l%2) total |= t[l++];
            if (r%2) total |= t[--r];
        }
        return __builtin_popcount(total);
    }
};

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    string s; cin >> s;
    vector<int> b(s.size());
    for (size_t i=0; i<s.size(); ++i){
        b[i] = 1 << (s[i]-'a');
    }

    SegTree<int> st(b);
    int n; cin >> n;
    while (n--){
        int t; cin >> t;
        if (t == 1){
            int i; cin >> i;
            char ch; cin >> ch;
            st.modify(i-1, 1 << (ch-'a'));
        } else {
            int l, r; cin >> l >> r;
            cout << st.query(l-1, r) << '\n';
        }
    }
}

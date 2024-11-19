#include <bits/stdc++.h>
using namespace std;
 
template <typename T>
struct SegTree {
    vector<T> t;
    int n;
    
    SegTree(int sz){
        n = sz;
        t = vector<T>(n*2);
    }
 
    void increase(int i, T v){
        for (t[i+=n] += v; i>1; i/=2){
            t[i/2] = t[i] + t[i^1];
        }
    }
 
    T query(int l, int r){
        T total = 0;
        for (l+=n, r+=n; l<r; l/=2, r/=2){
            if (l%2) total += t[l++];
            if (r%2) total += t[--r];
        }
        return total;
    }
};
 
void solve(){
    int n; cin >> n;
    vector<int> a(n), s(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
        s[i] = a[i];
    }
 
    sort(s.begin(), s.end());
    map<int, int> m;
    int pre=0, cur=0;
    for (int v : s){
        if (v != pre) m[v] = ++cur;
        pre = v;
    }
 
    long long ans = 0;
    SegTree<int> st(cur+1);
    for (int v : a){
        v = m[v];
        int l = st.query(0, v);
        int r = st.query(v+1, cur+1);
        ans += min(l, r);
        st.increase(v, 1);
    }
    
    cout << ans << '\n';
}
 
int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

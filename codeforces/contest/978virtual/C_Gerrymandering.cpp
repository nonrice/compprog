#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

template<class Fun> class ycomb_result {
    Fun fun_;
public:
    template<class T> explicit ycomb_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) ycomb(Fun &&fun) { return ycomb_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

inline int vote(char a, char b, char c){
    return (a=='A') + (b=='A') + (c=='A') >= 2;
}

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;


    map<pair<int, int>, int> h;
    auto dp = ycomb([&](const auto& self, int i, int j)->int{
        debug(i, j);
        const pair<int, int> p = make_pair(i, j);

        if (i==-1 && j==-1){
            return h[p] = 0;
        }

        if ((i<1 && j<1) || abs(i-j)>3){
            return h[p]= INT_MIN;
        }

        if (h.count(p)){
            return h[p];
        }

        h[p] = INT_MIN;
        if (i >= 2){
            h[p] = max(h[p], self(i-3, j) + vote(a[i], a[i-1], a[i-2]));
        }
        if (j >= 2){
            h[p] = max(h[p], self(i, j-3) + vote(b[j], b[j-1], b[j-2]));
        }
        if ((j==i || j==i+1) && i >= 0 && j >= 1){
            h[p] = max(h[p], self(i-1, j-2) + vote(a[i], b[j], b[j-1]));
        }
        if ((i==j || i==j+1) && i >= 1 && j >= 0){
            h[p] = max(h[p], self(i-2, j-1) + vote(a[i], a[i-1], b[j]));
        }

        return h[p];
    });


    cout << dp(n-1, n-1) << '\n';
    
    debug(h);

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
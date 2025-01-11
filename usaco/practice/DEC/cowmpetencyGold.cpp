#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr long long M = 1e9 + 7;

long long binpow(long long a, long long b, long long m){
    long long ans = 1;
    while (b){
        if (b&1) ans = ans*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return ans;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    long long c; cin >> c;

    map<int, int> a;
    for (int i=0; i<q; ++i){
        int l, r; cin >> l >> r;
        if (!a.count(r)){
            a[r] = l;
        } else {
            a[r] = min(a[r], l);
        }
    }
    vector<pair<int, int>> s;
    for (auto [r, l] : a){
        s.emplace_back(l, r);
    }
    sort(s.begin(), s.end());
    q = s.size();
    for (int i=1; i<q; ++i){
        if (s[i].first < s[i-1].second){
            cout << "0\n";
            return 0;
        }
    }

    vector<vector<long long>> dpa(q, vector<long long>(c+1)), dph(q, vector<long long>(c+1));
    for (int i=0; i<q; ++i){
        for (int x=1; x<=c; ++x){
            if (i != 0){
                int l = s[i].first-s[i-1].second;
                dpa[i][x] = dph[i-1][x] * binpow(x, l, M) % M;
                for (int y=1; y<x; ++y){
                    dpa[i][x] = (dpa[i][x] + dph[i-1][y] * ((binpow(x, l, M)-binpow(x-1, l, M)+M)%M)%M) % M;
                }
            } else {
                dpa[i][x] = (binpow(x, s[i].first, M)-binpow(x-1, s[i].first, M)+M)%M;
            }
        }

        for (int x=1; x<=c; ++x){
            int l = s[i].second-s[i].first;
            for (int y=1; y<x; ++y){
                dph[i][x] = (dph[i][x] + dpa[i][y] * binpow(y, l-1, M)%M) % M;
            }
        }
    }

    long long ans = 0;
    for (int x=0; x<=c; ++x){
        ans = (ans + dph[q-1][x] * binpow(c, n-s[q-1].second, M)%M) % M;
    }
    cout << ans << '\n';

    debug(dph);
    debug(dpa);
}
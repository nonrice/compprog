#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

constexpr long long M = 1000000007;

constexpr __int128 M2 = 18361375334787046697UL;
constexpr int B = 999998173;


__int128 binpow(__int128 a, int b){
    __int128 ans = 1;
    while (b){
        if (b&1){
            ans = ans*a%M2;
        }
        a = a*a%M2;
        b >>= 1;
    }
    return ans;
}

__int128 hash_replace(__int128 h, int i, int x1, int x2){
    return ((h + M2 - binpow(B, i)*x1%M2)%M2 + binpow(B, i)*x2)%M2;
}

#include <dbg.hpp>
int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n, t; cin >> n >> t;
    int u, v; cin >> u >> v;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int m = u;
    vector<long long> d(m);
    for (int i=0; i<u; ++i){
        d[i] = a[i+n-u] - a[i+n-u-1];
    }

    __int128 h = 0;
    for (int i=1; i<m; ++i){
        h = hash_replace(h, i, 0, d[i]);
    }
    
    set<pair<__int128, long long>> s({ { h, 0 } });
    map<__int128, long long> d0t({ { h, d[0] } });
    int w = u-v;
    long long rt = t;
    bool loop = false;
    while (rt > 0){
        if (d[w] > 0){
            int dt = min(rt, d[w]);
            h = hash_replace(h, w, d[w], d[w]-dt);
            d[w] -= dt;
            d[0] += dt;
            rt -= dt;
            continue;
        }
        
        h = hash_replace(h, w, d[w], d[w]-1);
        --d[w];
        ++d[0];
        --rt;
    
        if (d[w] == -1){
            int l=w-1;
            while (l>=0 && d[l]==0){
                --l;
            }
            int r=w+1;
            while (r<m && d[r]==0){
                ++r;
            }
            if (l + (r-w) != w){
                h = hash_replace(h, w, d[w], 0);
                d[w] = 0;
                if (l + (r-w)>0){
                    h = hash_replace(h, l+(r-w), d[l+(r-w)], 1);
                }
                d[l + (r-w)] = 1;

                if (l>=0){
                    if (l > 0){
                        h = hash_replace(h, l, d[l], d[l]-1);
                    }
                    --d[l];
                }
                if (r<m){
                    h = hash_replace(h, r, d[r], d[r]-1);
                    --d[r];
                }
            } else {

            }
        }

        if (!loop){
            auto it = s.lower_bound({ h, -1 });
            if (it != s.end() && it->first == h){
                int nrt = rt % ((t-rt) - it->second);
                d[0] += rt / (t-rt - it->second) * (d[0]-d0t[h]);
                rt = nrt;
                loop = true;
            }
            s.emplace(h, t-rt);
            d0t.emplace(h, d[0]);
        }
        debug(d);
    }

    long long ans = 0;
    for (int i=0; i<n-u; ++i){
        ans = (ans + 1LL*a[i]*a[i]%M) % M;
    }
    long long x = a[n-u-1];
    for (int i=0; i<m; ++i){
        x += d[i];
        ans = (ans + x*x%M) % M;
    }
    cout << ans << '\n';
}

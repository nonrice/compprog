#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, k, d; cin >> n >> k >> d;
    vector<int> a(n);
    int ans = (d-1)/2;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        if (a[i] == i+1){
            ++ans;
        }
    }
    vector<int> b(k);
    for (int i=0; i<k; ++i){
        cin >> b[i];
    }

    vector<int> s(n);
    for (int i=0; i<k; ++i){
        for (int j=0; j<b[i]; ++j){
            ++s[j];
        }
    }

    int c = 0;
    set<int> t({ 0 });
    for (int i=n-1; i>=0; --i){
        for (int j=0; j<k; ++j){
            if (b[j]-1 >= i){
                ++c;
            }
        }
        if (a[i] < i+1 && c>0){
            int r = (i+1-a[i])%c;
            if (r == 0){
                r = c;
            }
            for (int j=0; j<k; ++j){
                if (b[j]-1 >= i){
                    --r;
                }
                if (r == 0){
                    t.insert(max(0, (i+1-a[i])/c-1) * k + j);
                    break;
                }
            }
        }
    }

    for (auto x : t){
        if (x+1 < d){
            vector<int> h(a.begin(), a.end());
            for (int i=0; i<n; ++i){
                h[i] += s[i]*(x/k);
            }
            vector<int> p(n);
            for (int i=0; i<=x%k; ++i){
                ++p[0];
                if (b[i] < n){
                    --p[b[i]];
                }
            }
            for (int i=0; i<n; ++i){
                if (i>0){
                    p[i] += p[i-1];
                }
                h[i] += p[i];
            }

            int c = 0;
            for (int j=0; j<n; ++j){
                if (h[j] == j+1){
                    ++c;
                }
            }

            ans = max(ans, c + (d-x-2)/2);
        }
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
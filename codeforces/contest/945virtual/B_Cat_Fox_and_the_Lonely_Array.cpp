#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    auto chk = [&](int k){
        int s = 0;
        map<int, int> b;
        int c = 0;
        for (int i=0; i<n; ++i){
            for (int p=0; p<21; ++p){
                if (a[i] & (1<<p)){
                    ++b[p];
                }
            }
            ++s;

            if (s == k){
                for (auto [p, f] : b){
                    c += (1<<p);
                }
            } else if (s > k){
                for (int p=0; p<21; ++p){
                    if (a[i-k] & (1<<p)){
                        --b[p];
                        if (b[p] == 0){
                            b.erase(p);
                        }
                    }
                }
                --s;

                int t = 0;
                for (auto [p, f] : b){
                    t += (1<<p);
                }

                if (t != c){
                    return false;
                }
            }
        }
        return true;
    };

    int k = n;
    for (int s=n-1; s>=1; s/=2){
        while (k-s > 0 && chk(k - s)){
            k -= s;
        }
    }

    cout << k << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
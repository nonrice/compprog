#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr int MAXA = 3*1e5;

int fs1[MAXA+1], fs2[MAXA+1];

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    auto cnt_noncoprime = [&](int fs[MAXA+1], int x){
        vector<int> pf;
        int t = x;
        for (int f=2; f*f<=t; ++f){
            if (t%f == 0){
                pf.push_back(f);
                while (t%f == 0){
                    t /= f;
                }
            }
        }
        if (t != 1){
            pf.push_back(t);
        }

        int s=0;
        for (int m=1; m<(1<<pf.size()); ++m){
            int d=1;
            for (int i=0; i<pf.size(); ++i){
                if (m & (1<<i)){
                    d *= pf[i];
                }
            }
            if (__builtin_popcount(m) % 2){
                s += fs[d];
            } else {
                s -= fs[d];
            }
        }

        return s;
    };

    vector<vector<int>> fs(n);
    for (int i=0; i<n; ++i){
        for (int f=1; f*f<=a[i]; ++f){
            if (a[i] % f == 0){
                ++fs2[f];
                fs[i].push_back(f);
                if (a[i]/f != f){
                    ++fs2[a[i]/f];
                    fs[i].push_back(a[i]/f);
                }
            }
        }
    }

    long long ans = 0;
    long long cur = 0;
    for (int i=0; i<n; ++i){
        cur -= max(i-1, 0) - cnt_noncoprime(fs1, a[i]);
        for (auto f : fs[i]){
            --fs2[f];
        }
        if (i > 0){
            cur += n-i-1 - cnt_noncoprime(fs2, a[i-1]);
            for (auto f : fs[i-1]){
                ++fs1[f];
            }
        }
        ans += cur;
    }

    cout << ans << '\n';
}
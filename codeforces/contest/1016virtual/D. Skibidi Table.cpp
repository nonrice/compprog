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
    int q; cin >> q;

    while (q--){
        string c; cin >> c;

        if (c == "->"){
            long long x, y; cin >> x >> y;

            long long u=1, v=1;
            long long l=1, r=1LL<<(2*n);

            for (long long p=2*n; p>=2; p-=2){
                long long h = 1LL<<(p-2);
                
                int i = 0;
                long long d = 1LL<<(p/2 - 1);
                bool b1 = (y >= u+d);
                bool b2 = (x >= v+d);
                if (b1 && b2){
                    i = 1;
                } else if (b1 && !b2){
                    i = 3;
                } else if (!b1 && b2){
                    i = 2;
                }

                r = l+(i+1)*h - 1;
                l = l+i*h;
                if (i%2){
                    u += 1LL<<(p/2 - 1);
                }
                if (i == 1 || i == 2){
                    v += 1LL<<(p/2 - 1);
                }
            }

            cout << l << '\n';
        } else {
            long long d; cin >> d;

            long long u=1, v=1;
            long long l=1, r=1LL<<(2*n);

            for (long long p=2*n; p>=2; p-=2){
                long long h = 1LL<<(p-2);
                for (int i=0; i<4; ++i){
                    if (l+i*h <= d && d <= l+(i+1)*h - 1){
                        r = l+(i+1)*h - 1;
                        l = l+i*h;
                        if (i%2){
                            u += 1LL<<(p/2 - 1);
                        }
                        if (i == 1 || i == 2){
                            v += 1LL<<(p/2 - 1);
                        }
                    }
                }
            }

            cout << v << ' ' << u << '\n';
        }
    }


}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}

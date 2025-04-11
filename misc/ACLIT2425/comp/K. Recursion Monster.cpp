#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr int PM = 40;
constexpr int ZM = 40;
constexpr int XM = 256;
constexpr int SM = 100;
int dp1[ZM+1][XM+1][SM+1];
int dp2[ZM+1][XM+1][SM+1];

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    dp1[0][0][0] = 1;
    for (int p=1; p<=n; ++p){
        dp2[0][0][0] = 1;
        for (int z=1; z<=ZM; ++z){
            for (int x=0; x<=XM; ++x){
                for (int s=0; s<=SM; ++s){
                    dp2[z][x][s] = dp1[z][x][s];
                    if (s-a[p-1] >= 0 && (x^a[p-1])<=XM){
                        dp2[z][x][s] += dp1[z-1][x^a[p-1]][s-a[p-1]];
                    }
                }
            }
        }
        swap(dp1, dp2);
    }

    int q; cin >> q;
    while (q--){
        int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
        debug(a, b, c, d, e, f);

        long long ans = 0;
        for (int z=e; z<=f; ++z){
            for (int x=c; x<=d; ++x){
                for (int s=a; s<=b; ++s){
                    ans += dp1[z][x][s];
                    debug(dp1[z][x][s], z, x, s);
                }
            }
        }

        cout << ans << '\n';
    }
}

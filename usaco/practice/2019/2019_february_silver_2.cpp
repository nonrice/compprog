#include <bits/stdc++.h>
using namespace std;

int a[1001][1001], b[1001][1001];

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
#endif

    int n, k; cin >> n >> k;
    while (n--){
        int c1, r1, c2, r2; cin >> c1 >> r1 >> c2 >> r2;
        for (int r=r1; r<r2; ++r){
            ++a[r][c1];
            ++b[r][c2-1];
        }
    }

    int cur = 0;
    int ans = 0;
    for (int r=0; r<=1000; ++r){
        for (int c=0; c<=1000; ++c){
            cur += a[r][c];
            ans += cur==k;
            cur += b[r][c];
        }
    }

    cout << ans << '\n';
}

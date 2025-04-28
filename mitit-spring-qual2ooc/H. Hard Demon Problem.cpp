#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

long long query(vector<vector<long long>>& p, int x1, int y1, int x2, int y2){
    --x1, --y1;
    return p[x2][y2] - p[x2][y1] - p[x1][y2] + p[x1][y1];
}

void solve(){
    int n, q; cin >> n >> q;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            cin >> a[i][j];
        }
    }

    vector<vector<long long>> p1(n+1, vector<long long>(n+1)), p2(n+1, vector<long long>(n+1)), p3(n+1, vector<long long>(n+1));
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j){
            p1[i][j] = p1[i-1][j] + p1[i][j-1] - p1[i-1][j-1] + a[i-1][j-1];
            p2[i][j] = p2[i-1][j] + p2[i][j-1] - p2[i-1][j-1] + a[i-1][j-1]*j;
            p3[i][j] = p3[i-1][j] + p3[i][j-1] - p3[i-1][j-1] + a[i-1][j-1]*i;
        }
    }

    while (q--){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        
        long long s1 = query(p1, x1, y1, x2, y2);
        long long s2 = query(p2, x1, y1, x2, y2);
        long long s3 = query(p3, x1, y1, x2, y2);

        cout << s2 - (y1-1)*s1 + (y2-y1+1) * (s3 - s1*(x1)) << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}

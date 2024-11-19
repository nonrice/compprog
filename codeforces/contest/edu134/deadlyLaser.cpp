#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, sx, sy, d; cin >> n >> m >> sx >> sy >> d;
    if ((sx-d<=1 && sy-d<=1) || (sy+d>=m && sx+d>=n) || (sx-d<=1 && sx+d>=n) || (sy-d<=1 && sy+d>=m)){
        cout << "-1\n";
        return;
    }
    cout << n+m-2 << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

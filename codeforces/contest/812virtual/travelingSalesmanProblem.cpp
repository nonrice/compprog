#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int mxr=0, mxc=0, mnr=0, mnc=0;
    while (n--){
        int r, c; cin >> r >> c;

        if (r > 0) mxr = max(mxr, r);
        else mnr = max(mnr, -1*r);

        if (c > 0) mxc = max(mxc, c);
        else mnc = max(mnc, -1*c);
    }

    cout << 2*mxr + 2*mxc + 2*mnr + 2*mnc << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

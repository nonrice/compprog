#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s;

    int r=0, c=0;
    int mxr=0, mxc=0, mnr=0, mnc=0;
    for (char d : s){
        if (mxr-mnr+1 == n && ((d=='U' && r==mnr) || (d == 'D' && r==mxr))) break;
        if (mxc-mnc+1 == m && ((d=='R' && c==mxc) || (d == 'L' && c==mnc))) break;

        if (d == 'U') --r;
        else if (d == 'D') ++r;
        else if (d == 'R') ++c;
        else if (d == 'L') --c;

        mxr = max(mxr, r);
        mnr = min(mnr, r);
        mxc = max(mxc, c);
        mnc = min(mnc, c);
    }

    cout << -1*mnr + 1 << ' ' << -1*mnc + 1 << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

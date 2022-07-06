#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int l=-1, r=-1, cnt=0;
    for (int i=0; i<n; ++i) if (s[i]=='1') {
        if (l==-1) l=i;
        r = i;
        ++cnt;
    }
    
    int cur = cnt*11;
    if (n-r-1 <= k && cnt) {
        cur-=10;
        k -= n-r-1;
        --cnt;
    }
    if (l<=k && cnt) --cur;
    cout << cur << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

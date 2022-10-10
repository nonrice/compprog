#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int& v : a) cin >> v;
    for (int& v : b) cin >> v;

    if (a == b) {
        cout << "0\n";
        return;
    }
    
    int c1 = count(a.begin(), a.end(), 1);
    int c2 = count(b.begin(), b.end(), 1);

    if (c1 == c2) {
        cout << "1\n";
        return;
    }

    int ans = 0;
    for (int i=0; i<n; ++i){
        if ((c1>c2 && a[i]==1 && b[i]==0) || (c1<c2 && a[i]==0 && b[i]==1)){
            a[i] = b[i];
            if (a[i] == 0) --c1;
            else ++c1;
            ++ans;
        }
    }

    cout << ans+(a!=b) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    long long ans = 0;
    for (int i=1; i<=n; ++i){
        for (int j=i; j<=n; j+=i){
            if (s[j-1] == '1') break;
            if (s[j-1] != 'x') ans += i;
            s[j-1] = 'x';
        }
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

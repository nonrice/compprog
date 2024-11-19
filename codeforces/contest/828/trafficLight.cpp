#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    char c; cin >> c;
    string ts; cin >> ts;

    if (c == 'g') {
        cout << "0\n";
        return;
    }

    string s = ts + ts;
    
    int ans = 0;
    int g = s.find("g", n);
    for (int i=n-1; i>=0; --i){
        if (s[i] == c){
            ans = max(ans, g-i);
        } else if (s[i] == 'g'){
            g = i;
        }
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

char s[200001];

void solve(){
    int n; cin >> n >> s;

    char* p = find(s, s+n, (s[0]=='L' ? 'R' : 'L'));
    if (p != s+n) rotate(s, p, s+n);

    int ans = 0;
    for (int i=0; i<n; ++i){
        if (s[i] == s[(i+2)%n] && s[i] == s[(i+1)%n]){
            char opp = (s[i]=='L' ? 'R' : 'L');
            if (s[(i+3)%n] == opp && s[(i+4)%n] == opp) s[(i+1)%n] = opp;
            else s[(i+2)%n] = opp;
            ++ans;
        }
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
}


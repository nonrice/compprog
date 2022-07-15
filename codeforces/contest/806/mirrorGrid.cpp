#include <bits/stdc++.h>
using namespace std;

void rotate(int& r, int& c, int s){
    int tr = r;
    r = c;
    c = s-1-tr; 
}

void solve(){
    int s; cin >> s;
    vector<string> b(s);
    for (string& v : b) cin >> v;
    
    int ans = 0;
    for (int r=0; r<=s/2; ++r) for (int c=0; c<=s/2; ++c) {
        int one=0, zer=0;
        int tr = r, tc = c;
        for (int i=0; i<4; ++i){
            one += (b[tr][tc]=='1');
            zer += (b[tr][tc]=='0');
            rotate(tr, tc, s);
        }
        ans += min(one, zer);
    }
    cout << ans << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

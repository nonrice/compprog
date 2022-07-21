#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    
    int r = 0;
    int l = 0;
    int w = 0;
    for (char ch : s){
        if (ch == '(') ++r;
        else if (ch == ')'){
            if (r >= 1) --r;
            else ++l;
        }
        else ++w;
    }
    
    l += (s[0]=='?');
    r += (s.back()=='?');
    if (w - (s[0]=='?') - (s.back()=='?') == 0){
        cout << "YES\n";
        return;
    }

    //cout << r+l-w << '\n';

    if (r+l == w){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

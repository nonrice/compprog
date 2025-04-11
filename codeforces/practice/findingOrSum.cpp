#include <bits/stdc++.h>
using namespace std;

int ask(int n){
    cout << n << endl;
    int y; cin >> y;
    return y;
}

void solve(){
    int b1 = ask(0x15555555);
    int b2 = ask(0x2AAAAAAA);
    
    int x=0, y=0;
    if (b2 & 1){
        x = 1;
    } else {
        x = y = (b2 & 2)>>1;
    }

    for (int i=1; i<30; ++i){
        bool a, v;
        if (i&1){
            a = b1 & (1<<i);
            v = b1 & (1<<(i+1));
        } else {
            a = b2 & (1<<i);
            v = b2 & (1<<(i+1));
        }
        
        if (v){
            x |= 1<<i;
            if (a){
                y |= 1<<i;
            }
        }
    }

    cout << "! " << endl;
    int m; cin >> m;

    cout << (x|m) + (y|m) << endl;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}

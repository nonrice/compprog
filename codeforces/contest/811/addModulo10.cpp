#include <bits/stdc++.h>
using namespace std;

/*
 * C1: 2 4 8 6 2
 * C2: 0 0 0 0 0
 * 0 C2 
 * 1 C1*
 * 2 C1
 * 3 C1*
 * 4 C1
 * 5 C2
 * 6 C1
 * 7 C1*
 * 8 C1
 * 9 C1*
 */

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;
    int fz = 0;
    int oth = 0;
    int ffi = -1;
    int fze = -1;
    bool bad = false;
    for (int v : a){
        if (v%10 == 5){
            if (ffi != -1 && v!=ffi) bad = true;;
            ffi = v;
            ++fz;
        } else if (v%10 == 0){
            if (fze != -1 && v!=fze) bad = true;
            fze = v;
            ++fz;
        } else ++oth;

        if ((fz && oth) || bad){
            cout << "NO\n";
            return;
        }
    }
    
    //if (fz == )

    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases; cin >> cases;
    while (cases--) solve();
}

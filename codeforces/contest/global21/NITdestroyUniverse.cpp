#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    
    int segs = 0;
    bool in_seg = false;
    while (n--){
        int v; cin >> v;

        if (!in_seg && v){
            in_seg = true;
            ++segs;
        } else if (!v) {
            in_seg = false;
        }
    } 

    cout << min(2, segs) << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

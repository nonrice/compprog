#include <bits/stdc++.h>
using namespace std;

int calc_time(vector<int>& j, int t){
    int low = 0;
    int up = 0;
    for (int v : j){
        up += max(0, v-t);
        low += max(0, t-v);
    }

    return up - low/2;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> j(n);
    for (int i=0; i<m; ++i){
        int v; cin >> v;
        ++j[--v];
    }
    
    int mx1=0, mx2=0;
    for (int v : j){
        if (v > mx1){
            mx1 = v;
            mx2 = mx1;
        } else if (v > mx2){
            mx2 = v;
        }
    }

    int cur = mx1;
    for (int step=cur; step>=1; step/=2){
        while (cur-step >= 0 && calc_time(j, cur - step) >= 0){
            cur -= step;
        }
    }
    
    cout << cur + (mx-cur)/2 + 1 << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

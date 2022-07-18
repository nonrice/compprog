#include <bits/stdc++.h>
using namespace std;

// this is not working
// binary search is not right
// what the hell
//

int check(vector<int>& a, int t, int k){
    int mx=0, mn=INT_MAX;
    for (int v : a){
        int pi = (!t) ? k : max(1, min(k, v/t));
        mx = max(mx, v/pi);
        mn = min(mn, v/pi);
    }
    return mx-mn;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int a_mx = 0;
    for (int& v : a){
        cin >> v;
        a_mx = max(a_mx, v);
    }
    
    int cur = -1;
    for (int step=a_mx+1; step>=1; step/=2){
        int nxt = cur-1;
        int cur_val = check(a, cur+step)
        for (int step2=a_mx+1; step2>=1; step2/=2){
            while ()
        }
        while (check(a, cur+step, k) <= check(a, cur+step-1, k)){
            cur += step;
        }
    }

    cout << check(a, cur, k) << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

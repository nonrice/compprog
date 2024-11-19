#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n, k; cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    ll sum=0;
    while (n--){
        int v; cin >> v;
        sum += v;
        pq.push(n-v);
    }
    
    int decr = 0;
    while (k-- && pq.top()-decr <= 0){
        sum += pq.top()-decr;
        pq.pop();
        ++decr;
    }

    cout << max(0LL, sum) << '\n';
}

int main(){
    int cases; cin >> cases;
    while(cases--) solve();
}

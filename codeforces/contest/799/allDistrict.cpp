#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    unordered_map<int, int> m;
    while (n--){
        int v; cin >> v;
        ++m[v];
    }

    priority_queue<int> pq;
    for (auto& p : m){
        pq.push(p.second);
    }

    while (pq.top() > 1){
        int v = pq.top(); pq.pop();
        if (--v)
            pq.push(v);

        v = pq.top(); pq.pop();
        if (--v)
            pq.push(v);
    }

    cout << pq.size() << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

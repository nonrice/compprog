#include <bits/stdc++.h>
using namespace std;

// lesson: use hashmap to store bfs depth and prevent duplicates

using ll = long long;

int main(){
    ll n, x; cin >> n >> x;

    queue<ll> bfs({x});
    unordered_map<ll, int> dist;
    while (!bfs.empty()){
        ll v = bfs.front();
        ll tv = v;
        bool di[10] = { 0 };
        
        int len = 0;
        while (tv){
            di[tv%10] |= 1;
            tv /= 10;
            ++len;
        }
        if (len == n){
            cout << dist[v] << '\n';
            return 0;
        }

        for (int i=2; i<=9; ++i){
            if (di[i] && !dist.count(v*i)){
                bfs.push(v * i);
                dist[v * i] = dist[v] + 1;
            }
        }
        
        bfs.pop();
    }

    cout << "-1\n";
}

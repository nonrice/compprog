#include <bits/stdc++.h>
using namespace std;

struct table {
    int x, y;

    bool operator<(const table& o) const {
        if (this->dist() != o.dist()){
            return this->dist() > o.dist(); // to make min pq
        }
        if (x != o.x){
            return x > o.x;
        }
        return y > o.y;
    }

    int dist() const {
        if (x%3==1 || y%3==1){
            return x+y;
        }
        return x+y+2;
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    
    priority_queue<table> q1, q2; 
    for (int d=0; d<100*n; ++d){
        for (int x=0; x<d; ++x){
            if (x%3!=0 && (d-x)%3!=0){
                q1.push({x, d-x});
                q2.push({x, d-x});
            }
        }
        if (q1.size() >= 50*n){
            break;
        }
    }

    set<pair<int, int>> v1, v2;
    for (int i=0; i<n; ++i){
        if (a[i]==0){
            while (v2.count({ q2.top().x/3, q2.top().y/3 }) || v1.count({ q2.top().x, q2.top().y })){
                q2.pop();
            }
            auto [x, y] = q2.top();
            cout << x << ' ' << y << '\n';
            v2.emplace(x/3, y/3);
            v1.emplace(x, y);
            q2.pop();
        } else {
            while (v1.count({ q1.top().x, q1.top().y })){
                q1.pop();
            }
            auto [x, y] = q1.top();
            cout << x << ' ' << y << '\n';
            v2.emplace(x/3, y/3);
            v1.emplace(x, y);
            q1.pop();
        }
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}

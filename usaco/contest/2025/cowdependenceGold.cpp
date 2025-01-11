#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    map<int, vector<int>> p;
    for (int i=0; i<n; ++i){
        int y; cin >> y;
        p[y].push_back(i);
    }

    for (int x=1; x<=n; ++x){
        int ans = 0;
        for (auto [k, v] : p){
            auto it = v.begin();
            while (it != v.end()){
                ++ans;
                it = upper_bound(it, v.end(), *it+x);
            }
        }
        cout << ans << '\n';
    }

}
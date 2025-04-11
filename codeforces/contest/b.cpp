#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    
    vector<pair<int, int>> ans;
    stack<int> s;
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        if (x == 0){
            if (!s.empty()){
                ans.emplace_back(s.size(), s.size()+1);
                s.pop();
                s.push(1);
            } else {
                s.push(x);
            }
        } else {
            if (!s.empty() && s.top() == 0){
                ans.emplace_back(s.size(), s.size()+1);
                s.pop();
                s.push(1);
            } else {
                s.push(x);
            }
        }
    }

    if (s.size() == 1){
        cout << "3\n";
        cout << n/2+1 << ' ' << n << '\n';
        cout << 1 << ' ' << n/2 << '\n';
        cout << "1 2\n";
        return;
    }

    ans.emplace_back(1, s.size());

    cout << ans.size() << '\n';
    for (auto [l, r] : ans){
        cout << l << ' ' << r << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}

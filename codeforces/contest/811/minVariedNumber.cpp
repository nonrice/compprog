#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    if (n < 10){
        cout << n << '\n';
    } else {
        vector<int> d = {9};
        int sum = 9;
        int cur = 9;
        while (sum < n){
            int dig = min(n-sum, --cur);
            sum += dig;
            d.push_back(dig);
        }
        
        reverse(d.begin(), d.end());
        for (int v : d) cout << v;
        cout << '\n';
    }
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

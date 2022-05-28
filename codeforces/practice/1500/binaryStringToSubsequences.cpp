#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    list<int> zeros, ones;
    vector<int> ans;
    int cur = 0;
    for (char ch : s){
        if (ch == '0'){
            if (ones.empty()){
                zeros.push_back(++cur);
                ans.push_back(cur);
            } else {
                ans.push_back(ones.front());
                zeros.push_back(ones.front());
                ones.erase(ones.begin());
            }
        } else {
            if (zeros.empty()){
                ones.push_back(++cur);
                ans.push_back(cur);
            } else {
                ans.push_back(zeros.front());
                ones.push_back(zeros.front());
                zeros.erase(zeros.begin());
            }
        }
    }

    cout << cur << '\n';
    for (int v : ans) cout << v << ' ';
    cout << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--){
        solve();
    }
}


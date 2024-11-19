#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& [s, g] : a) cin >> s >> g;

    vector<pair<int, int>> h(n);
    for (int i=0; i<n; ++i){
        h[i].second = a[i].second + a[i].first;
        h[i].first = i;
    }
    sort(h.begin(), h.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        return a.first+a.second < b.first+b.second;
    });

    map<int, int> m;
    long long rm = 0;
    int mn=INT_MAX, mx=INT_MIN;
    for (auto [i, h] : h){
        m[i] = h;

        if (i > mn){
            auto l = *--m.find(i);
            m[i] = min(m[i], l.second + i-l.first);
        } else {
            mn = i;
        }
        if (i < mx){
            auto r = *++m.find(i);
            m[i] = min(m[i], r.second + r.first-i);
        } else {
            mx = i;
        }

        if (m[i] < a[i].first){
            cout << "-1\n";
            return 0;
        }

        rm += m[i] - a[i].first;
    }


    cout << rm << '\n';
    for (auto [i, h] : m) cout << h << ' ';
    cout << '\n';
}

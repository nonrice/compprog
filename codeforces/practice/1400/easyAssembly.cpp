#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<int>> b(n, vector<int>());
    vector<int> a;
    for (int i=0; i<n; ++i){
        int k; cin >> k;
        b[i].resize(k);
        for (int j=0; j<k; ++j){
            cin >> b[i][j];
            a.push_back(b[i][j]);
        }
    }

    map<int, int> p;
    sort(a.begin(), a.end());
    for (size_t i=0; i<a.size(); ++i) p[a[i]] = i;
    
    int c=0, s=0;
    for (vector<int>& t : b){
        ++c;
        for (size_t i=1; i<t.size(); ++i){
            if (p[t[i]] - p[t[i-1]] != 1){
                ++c;
                ++s;
            }
        }
    }
    --c;

    cout << s << ' ' << c << '\n';
}


#include <bits/stdc++.h>
using namespace std;

#define INTERACTIVE

int ask(string& s){
    cout << "? " << s << endl;
    int ans; cin >> ans;
    return ans;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;

    string s(m, '0');
    vector<pair<int, int>> l(m);
    s[0] = '1';
    l[0].first = ask(s);
    for (int i=1; i<m; ++i){
        s[i-1] = '0';
        s[i] = '1';
        l[i].first = ask(s);
        l[i].second = i;
    }

    s[m-1] = '0';
    sort(l.begin(), l.end());
    int mst = 0;
    for (auto [v, i] : l){
        s[i] = '1';
        int n_mst = ask(s);
        if (n_mst-mst != v){
            s[i] = '0';
        } else {
            mst = n_mst;
        }
    }

    cout << "! " << mst << endl;
}

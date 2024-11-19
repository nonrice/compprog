#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n; cin >> n;
    vector<string> sv(n);
    set<string> st;
    for (int i=0; i<n; ++i){
        string s; cin >> s;
        st.insert(s);
        sv[i] = s;
    }

    for (string& s : sv){
        const int len = s.size();
        bool good = false;
        for (int i=0; i<len; ++i){
            if (st.count(s.substr(0, i)) && st.count(s.substr(i))){
                cout << 1;
                good = true;
                break;
            }
        }
        if (!good) cout << 0;
    }
    cout << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

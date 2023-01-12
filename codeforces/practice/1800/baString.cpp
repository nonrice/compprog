#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    long long x; cin >> x;
    string a; cin >> a;

    vector<int> s;
    char prev = 'a';
    for (int i=0; i<n; ++i){
        char ch = a[i];
        if (ch == '*' && prev != '*'){
            s.push_back(k);
        } else if (ch == '*' && prev == '*'){
            s.back() += k;
        }
        if (ch == 'a') s.push_back(-1);
        prev = ch;
    }
    for (int& sg : s) if (sg >= 0) ++sg;
    //cout << '\n';
    
    --x;
    for (int i=s.size()-1; i>=0; --i){
        if (s[i] == -1) continue;
        if (s[i] > x){
            for (int j=0; j<s.size(); ++j){
                if (s[j] != -1){
                    if (j > i){
                        for (int l=0; l<s[j]; ++l) cout << 'b';
                    } else if (j == i){
                        for (int l=0; l<x; ++l) cout << 'b';
                    }
                } else {
                    cout << 'a';
                }
            }
            cout << '\n';
            return;
        }
        int tsi = s[i];
        s[i] = x % (s[i]);
        x /= tsi;
    }

    cout << a << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}


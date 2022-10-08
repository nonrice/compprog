#include <bits/stdc++.h>
using namespace std;

bool chkcycle(int p[26], int start){
    int len = 0;
    for (int i=p[start]; i!=-1; i=p[i]){
        ++len;
        if (i == start) return len != 26;
    }

    return false;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n);
    for (int i=0; i<n; ++i) a[i] = s[i]-'a';

    int p[26];
    fill(p, p+26, -1);
    bool use[26] = {};
    for (int ch : a){
        if (p[ch] == -1){
            int i=0;
            for (; i<26; ++i){
                if (!use[i]){
                    p[ch] = i;
                    if (!chkcycle(p, ch)) break;
                    p[ch] = -1;
                }
            }
            use[i] = true;
        }
    }

    for (int ch : a) cout << (char)(p[ch]+'a');
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

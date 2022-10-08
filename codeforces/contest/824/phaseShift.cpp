#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool chkcycle(int a[26], bool cpt[26], int bg){
    int ln = 0;
    bool fg = false;

    for (int i=bg; !fg || i!=bg; i=a[i]){
        if (!cpt[i]) return false;
        if (++ln == 26) return false;
        fg = true;
    }
    
    return true;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    bool hpt[26] = {}, cpt[26] = {};
    int pt[26] = {};
    for (char ch : s){
        ch -= 'a';
        
        if (!cpt[ch]){
            int cur = 0;
            bool fg = chkcycle(pt, cpt, ch);
            cpt[ch] = true;
            for (; cur<25 && (hpt[cur] || cur==ch || fg); ++cur){
                pt[ch] = cur;
                fg = chkcycle(pt, cpt, ch);
            }
            hpt[cur] = true;
        }
    }
    
    for (int i=0; i<26; ++i) cout << pt[i] << ' ';
    cout << '\n';
    for (int i=0; i<26; ++i) cout << cpt[i] << ' ';
    cout << '\n';
    for (char ch : s){
        cout << (char)(pt[ch-'a'] + 'a');
    }

    cout << chkcycle(pt, cpt, 0);

    cout << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}


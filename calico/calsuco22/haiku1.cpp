#include <bits/stdc++.h>
using namespace std;

const int sizes[] = {5, 7, 5};

void solve(){
    int n; cin >> n;
    vector<pair<int, string>> words(n);
    for (auto& w : words) cin >> w.first >> w.second;

    vector<int> perm(n);
    for (int i=0; i<n; ++i){
        perm[i] = i;
    }
    
    bool good = false;
    while (!(perm[0]==n-1 && perm.back()==0)){
        int cur = 0;
        int sz = 0;
        for (int v : perm){
            cur += words[v].first;
            if (cur > sizes[sz]) break;
            if (cur == sizes[sz]){
                //cout << cur << '\n';
                ++sz;
                if (sz == 3){
                    good = true;
                    break;
                }
                cur = 0;
            }
        }
        
        if (good){
            int cur = 0;
            int sz = 0;
            for (int v : perm){
                cout << words[v].second << ' ';
                cur += words[v].first;
                if (cur == sizes[sz]){
                    cout << '\n';
                    ++sz;
                    if (sz == 3){
                        return;
                    }
                    cur =0;
                }
            }
        }

        next_permutation(perm.begin(), perm.end());
    }

    cout << "IMPOSSIBLE\nIMPOSSIBLE\nIMPOSSIBLE\n";
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

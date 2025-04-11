#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n, q; cin >> n >> q;
    string s; cin >> s;
    
    array<vector<int>, 26> p;
    for (int i=0; i<n; ++i){
        p[s[i]-'a'].push_back(i);
    }

    while (q--){
        int l, r; cin >> l >> r;
        --l, --r;
    
        long long ans = -1;
        for (int c1=0; c1<26; ++c1){
            for (int c2=0; c2<26; ++c2){
                if (c1 == c2){
                    continue;
                }

                auto it1 = lower_bound(p[c1].begin(), p[c1].end(), l);
                auto it2 = upper_bound(p[c2].begin(), p[c2].end(), r);

                if (it1 == p[c1].end()){
                    break;
                }
                if (*it1 > r){
                    break;
                }
                if (it2 == p[c2].begin()){
                    continue;
                }
                --it2;
                if (*it2 < l || *it2<*it1){
                    continue;
                }

                auto it3 = upper_bound(p[c2].begin(), p[c2].end(), (*it2+*it1)/2);
                if (it3 != p[c2].end() && *it3<*it2 && *it3>*it1){
                    ans = max(ans, 1LL * (*it2-*it3)*(*it3-*it1));
                }
                if (it3 != p[c2].begin()){
                    --it3;
                }
                if (*it3<*it2 && *it3>*it1){
                    ans = max(ans, 1LL * (*it2-*it3)*(*it3-*it1));
                }
            }
        }

        cout << ans << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;

#include <dbg.hpp>

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }


    map<int, int> v;
    for (int i=0; i<n; ++i){
        ++v[a[i]];
    }
    map<int, set<int, greater<int>>> f;
    while (q--){
        int i, x; cin >> i >> x;
        --i;

        f[v[a[i]]].erase(a[i]);
        --v[a[i]];
        f[v[a[i]]].insert(a[i]);

        f[v[x]].erase(x);
        ++v[x];
        f[v[x]].insert(x);



        auto it_j = f.end();
        long long s = it_j->second.size() * it_j->first;
        int r = it_j->second.size()-1;
        auto it_i = f.begin();

        while (it_i!=f.end() && it_i->first < s-it_j->first-r*(it_j->first-1)){
            ++it_i;
        }
        while ()
        }
    }



    
}

#include <bits/stdc++.h>
using namespace std;

struct query {
    int p, r, i; 
};

void solve(){
    int n, q; cin >> n >> q;
    list<int> a(n);
    vector<int> b(n);
    {
        int i=0;
        for (int& v : a){ 
            cin >> v;
            b[i] = v;
            ++i;
        }
    }
    
    vector<query> qs(q);
    for (int i=0; i<q; ++i){
        cin >> qs[i].p >> qs[i].r;
        qs[i].i = i;
    }
    sort(qs.begin(), qs.end(), [](const query& a, const query& b){
        return a.r < b.r;
    });

    vector<int> wins(n+1);
    vector<int> ans(q);
    int cur_q = 0;
    int r = 0;
    for (; a.front()!=n; ++r){
        while (cur_q<q && qs[cur_q].r == r){
            ans[qs[cur_q].i] = wins[b[qs[cur_q].p-1]];
            ++cur_q;
        }
        if (cur_q == q) break;
        int f = a.front(); a.pop_front();
        int s = a.front(); a.pop_front();
        ++wins[max(f, s)];
        a.push_front(max(f, s));
        a.push_back(min(f, s));
    }

    //for (auto v : qs) cout << v.r << ' ' << v.i << '\n';
    //cout << '\n';

    for (int i=cur_q; i<q; ++i){
        if (b[qs[i].p - 1] != n){
            ans[qs[i].i] = wins[b[qs[i].p-1]];
        } else {
            ans[qs[i].i] = qs[i].r - r + wins[n];
            //cout << "MAX" << b[qs[i].p-1] << ' ' << qs[i].r << r  << '\n'; 
        }
    }

    for (int v : ans) cout << v << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

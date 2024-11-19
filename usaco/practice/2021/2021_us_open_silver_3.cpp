#include <bits/stdc++.h>
using namespace std;

int a[100000];
int d[100000]; // (used in can_cite) citations needed for each paper
int n, k, l;

bool can_cite(int h) noexcept {
    for (int i=0; i<h; ++i){
        d[i] = max(0, h-a[i]);
    }

    sort(d, d+h, greater<int>());
    if (d[0] > k) return false;

    // this part is invalid
    // but I still get 17/20 TC which I will gladly take
    multiset<int> p;
    for (int i=0; i<h; ++i){
        multiset<int>::iterator it = p.lower_bound(d[i]);
        if (it == p.end()){
            if (p.size() >= (size_t)l) return false;
            p.insert(k-d[i]);
        } else {
            p.insert(*it-d[i]);
            p.erase(it);
        }
    }

    return true;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    cin >> n >> k >> l;
    for (int i=0; i<n; ++i) cin >> a[i];

    sort(a, a+n, greater<int>());
    int h = 0;
    for (; h<n; ++h){
        if (a[h] < h+1) break;
    }

    int ans = h;
    for (int s=n-h; s>=1; s>>=1){
        while (ans+s <= n && can_cite(ans+s)) ans += s;
    }

    cout << ans << '\n';
}

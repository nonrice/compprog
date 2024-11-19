#include <bits/stdc++.h>
using namespace std;

struct cow {
    int w, x, d;

    bool operator<(const cow& o) const {
        return x<o.x;
    }
};

int n, l;
cow a[400000];

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
#endif

    cin >> n >> l;
    int tw = 0;
    for (int i=0; i<n; ++i){
        cin >> a[i].w >> a[i].x >> a[i].d;
        tw += a[i].w;
    }

    sort(a, a+n);
    queue<int> q;
    for (int i=0; i<n; ++i){
        if (a[i].d == 1) q.push(a[i].w);
        else {
            q.push(a[i].w);
            a[i].w = q.front(); q.pop();
        }
    }
    q = {};
    for (int i=n-1; i>=0; --i){
        if (a[i].d == -1) q.push(a[i].w);
        else {
            q.push(a[i].w);
            a[i].w = q.front(); q.pop();
        }
    }
    
    sort(a, a+n, [&](const cow& a, const cow& b){
        int t1 = (a.d == 1) ? l-a.x : a.x;
        int t2 = (b.d == 1) ? l-b.x : b.x;
        return t1<t2; 
    });
    int ctw = 0;
    int t=0;
    for (int i=0; i<n; ++i){
        ctw += a[i].w;
        if (ctw*2 >= tw){
            t = (a[i].d == 1) ? l-a[i].x : a[i].x;
            break;
        }
    }

    int ans = 0;
    q = {};
    sort(a, a+n);
    for (int i=0; i<n; ++i){
        if (a[i].d == 1) q.push(a[i].x);
        while (!q.empty() && q.front() < a[i].x-2*t) q.pop();
        if (a[i].d == -1) ans += q.size();
    }

    cout << t << ' ' << ans << '\n';
}

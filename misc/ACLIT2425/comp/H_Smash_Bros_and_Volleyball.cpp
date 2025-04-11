#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> f(n);
    for (long long i = 0; i < n; i++) {
        cin >> f[i];
    }
    multiset<long long> taha;
    vector<long long> p(n+1);
    p[0]=0;
    for (long long i = 1; i < n+1; i++) {
        p[i] = f[i-1]+p[i-1];
    }
    //cerr << p.size() <<' ' << a << '\n';
    long long ans = p[a];
    for (long long i = a+1; i < n+1; i++) {
        taha.insert(p[i-a-1]);
        if (!taha.empty()){
            ans = max(ans, p[i]-*taha.begin());
        }
        if (i >= a+b) {
            auto it = taha.find(p[i-a-b]);
            if (it != taha.end()){
                taha.erase(it);
            }
        }
    }
    cout << ans << '\n';
}
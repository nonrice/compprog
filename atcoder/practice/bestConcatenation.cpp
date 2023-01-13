#include <bits/stdc++.h>
using namespace std;
 
struct str {
    long long t, s, x;
    
    bool operator<(const str& o){
        return s*o.x < o.s*x;
    }
};
 
str a[200000];
char buf[200001];
 
int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    for (int i=0; i<n; ++i){
        cin >> buf;
        long long t=0, s=0, x=0;
        for (int j=0; buf[j]!=0; ++j){
            if (buf[j] == 'X') ++x;
            else {
                s += buf[j]-'0';
                t += (buf[j]-'0')*x;
            }
        }
        a[i] = { t, s, x };
    }
    
    sort(a, a+n);
    
    long long x = 0;
    long long ans = 0;
    for (int i=0; i<n; ++i){
        ans += a[i].s * x + a[i].t;
        x += a[i].x;
    }
    
    cout << ans << '\n';
}

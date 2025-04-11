#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;

    long long ans = 2;
    long long s1 = 2;
    for (int i=0; i<n; ++i){
        char o1, o2;
        int p1, p2;
        cin >> o1 >> p1 >> o2 >> p2;

        long long s2 = 0;

        if (i == 0){
            s1 = (p1 - (o1=='x')) + (p2 - (o2=='x'));
            continue;
        }
        
        if (((o1=='+') != (o2=='+')) && o1=='+'){
            swap(o1, o2);
            swap(p1, p2);
        }


        if (o1 == '+'){
            s1 = p1+p2;
        } else if (o1 == 'x' && o2 == '+'){
            s1 = s1*(p1-1) + p2;
        } else {
            s1 = s1*(max(p1, p2)-1);
        }
        debug(s1);

        ans += s1;
    }

    cout << ans << '\n';
    
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}

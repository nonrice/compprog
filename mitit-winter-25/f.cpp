#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    string s, t; cin >> s >> t;
    int n = s.size();

    long long ans = 0;

    {
        vector<bool> s1, t1;
        for (int i=0; i<n; i+=2){
            s1.push_back(s[i]=='A');
            t1.push_back(t[i]=='A');
        }
        if (count(s1.begin(), s1.end(), true) != count(t1.begin(), t1.end(), true)){
            cout << "-1\n";
            return;
        }
        vector<bool>::iterator p1=s1.begin(), p2=t1.begin();
        p1 = find(s1.begin(), s1.end(), true);
        p2 = find(t1.begin(), t1.end(), true);
        while (p1 != s1.end()){
            ans += abs((p1-s1.begin()) - (p2-t1.begin()));
            if (++p1 == s1.end()){
                break;
            }
            if (++p2 == t1.end()){
                break;
            }
            p1 = find(p1, s1.end(), true);
            p2 = find(p2, t1.end(), true);
        }
    }

    {
        vector<bool> s1, t1;
        for (int i=1; i<n; i+=2){
            s1.push_back(s[i]=='A');
            t1.push_back(t[i]=='A');
        }
        if ( count(s1.begin(), s1.end(), true) != count(t1.begin(), t1.end(), true)){
            cout << "-1\n";
            return;
        }
        vector<bool>::iterator p1=s1.begin(), p2=t1.begin();
        p1 = find(s1.begin(), s1.end(), true);
        p2 = find(t1.begin(), t1.end(), true);
        while (p1 != s1.end()){
            ans += abs((p1-s1.begin()) - (p2-t1.begin()));
            if (++p1 == s1.end()){
                break;
            }
            if (++p2 == t1.end()){
                break;
            }
            p1 = find(p1, s1.end(), true);
            p2 = find(p2, t1.end(), true);
        }
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
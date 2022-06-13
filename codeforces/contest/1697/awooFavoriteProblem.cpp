#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    
    size_t i = min(s.find('a'), s.find('c'));
    bool is_ab = s.find('a') < s.find('c');
    while (i != string::npos){
        if (is_ab){
            size_t e = min((size_t)n, s.find(i, 'c'));
            if (!(
                count(s.begin()+i, s.begin()+e, 'a') ==
                count(t.begin()+i, t.begin()+e, 'a')
                &&
                i <= t.find(i-1, 'a')
            )){
                cout << "NO\n";
                return;
            }
        } else {
            size_t b = s.rfind(i, 'a');
            bool flag = b==string::npos;
            b *= (b!=string::npos);
            
            
            size_t next = t.rfind(i+1, 'c');
            next *= next != string::npos;

            if (!(
                count(s.begin()+b+(!flag), s.begin()+i+1, 'c') ==
                count(t.begin()+b+(!flag), t.begin()+i+1, 'c')
                &&
                i >= next 
            )){
                cout << "NO\n";
                return;
            }
        }

        if (is_ab){
            i = s.find(s.find(i, 'c'), 'a');
            i = s.rfind(i, 'c');
        } else {
            i = s.find(i, 'a');
        }
        is_ab ^= 1;
    }

    cout << "YES\n";
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

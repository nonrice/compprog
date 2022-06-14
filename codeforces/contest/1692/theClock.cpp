#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int k; cin >> k;

    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(3, 5));
    int o_a = a;
    int o_b = b;

    int inch = k/60;
    int incm = k%60;

    int ans = 0;
    do {
        if (a == (b%10 * 10)+(b/10)){
            ++ans;
        }
        
        int carry=0;
        b += incm;
        if (b >= 60){
            b -= 60;
            ++carry;
        }
        a += inch+carry;
        if (a >= 24){
            a -= 24;
        }
    } while (a!=o_a || b!=o_b);

    cout << ans << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

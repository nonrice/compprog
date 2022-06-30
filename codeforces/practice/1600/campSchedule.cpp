#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const ull MOD = 99824453;

int main(){
    string s, t; cin >> s >> t;
    
    ull l=0, r=0, pw=1;
    int len = 0;
    const int tl = t.length();
    for (int i=0; i<tl; ++i){
        l = (l + (t[i]=='1')*pw) % MOD;
        r = (r*2%MOD + (t[tl-i-1]=='1')) % MOD;
        if (l == r && i!=tl-1)
            len = i+1;
        pw = pw*2 % MOD;
    }
    
    int s1=0, s0=0;
    for (char ch : s) (ch=='1') ? ++s1 : ++s0;
    int t1=0, t0=0;
    for (char ch : t) (ch=='1') ? ++t1 : ++t0;
    int ts1=0, ts0=0;
    for (int i=0; i<len; ++i) (t[i]=='1') ? ++ts1 : ++ts0;

    ts1 = t1-ts1;
    ts0 = t0-ts0;
    string tsuf;
    if (len == 0 || len == tl){
        tsuf = t;
        ts1 = t1;
        ts0 = t0;
    } else {
        tsuf = t.substr(len);
    }
    
    if (s1-t1>=0 && s0-t0>=0){
        cout << t;
        s1 -= t1;
        s0 -= t0;
        while(s1-ts1>=0 && s0-ts0>=0){
            cout << tsuf;
            s1 -= ts1;
            s0 -= ts0;
        }
    }

    while (s1--) cout << '1';
    while (s0--) cout << '0';
}

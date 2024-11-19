#include <iostream>
#include <string>
#include <algorithm>

// lesson learned: people love anti hash test cases 
#define HASH_BASE 29 
#define MOD 99824453

#define ll long long

void solve(){
    std::string s; std::cin >> s;
    int n = s.length();

    int m = 0;
    while (s[m]==s[n-m-1] && m<=(n/2)-1) ++m;
    std::string front = s.substr(0, m);
    s = s.substr(m, n-m-m);
    n = s.length();
    
    std::string mid = "";

    {
        ll f=0, b=0, p=0, pow=1;
        for (int i=0; i<n; ++i){
            f = ((f*HASH_BASE)%MOD + (s[i]-'a')) % MOD;
            b = (b + ((s[i]-'a') * pow)%MOD) % MOD;
            if (f==b)
                p = i;
            pow = (pow * HASH_BASE) % MOD;
        }
        mid = s.substr(0, p+1);
    }
    {
        ll f=0, b=0, p=0, pow=1;
        for (int i=n-1; i>=0; --i){
            f = ((f*HASH_BASE)%MOD + (s[i]-'a')) % MOD;
            b = (b + ((s[i]-'a') * pow)%MOD) % MOD;
            if (f==b)
                p = i;
            pow = (pow * HASH_BASE) % MOD;
        }
        if ((size_t)(n-p) > mid.length())
            mid = s.substr(p, n-p);
    }

    std::cout << front << mid;
    std::reverse(front.begin(), front.end());
    std::cout << front << '\n';
}

int main(){
    int cases; std::cin >> cases;
    while (cases--){
        solve();
    }
}


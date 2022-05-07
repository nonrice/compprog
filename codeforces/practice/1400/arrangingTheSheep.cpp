#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long

void solve(){
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    
    std::vector<int> v;
    for (size_t i=0; i<s.length(); ++i){
        if (s[i] == '*')
            v.push_back(i);
    }
    
    ll ans = 0;
    int mid = (v.size()+1)/2 - 1;
    int offset = mid;
    for (size_t i:v){
        ans += std::abs(v[mid]-(int)i) - std::abs(offset);
        --offset;
    }
    std::cout << ans << '\n';
}

int main(){
    int cases; std::cin >> cases;
    while (cases--)
        solve();
}


#include <iostream>
#include <vector>
#include <numeric>

#define ll long long

int solve(std::vector<ll>& v, ll d){
    ll ans = 0;
    ll cut = d/2;
    bool is_over = v[0]>cut;
    
    auto it = v.begin();
    while (it != v.end()){
        if (is_over){
            ll min = d+1;
            while (it!=v.end() && *it>cut){
                min = std::min(*it, min);
                ++it;
            }
            ans += d-min;
        } else {
            ll max = 0;
            while (it!=v.end() && *it<=cut){
                max = std::max(*it, max);
                ++it;
            }
            ans += max;
        }
        is_over = !is_over;
    }
    return ans;
}

int main(){
    int cases; std::cin >> cases;
    std::vector<ll> v;
    int n, d;
    for (int c=1; c<=cases; ++c){
        std::cin >> n >> d;
        v.resize(n);
        for (ll& a:v) std::cin >> a;
        std::cout << "Case #" << c << ": " << solve(v, d) << '\n';
    }
}

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

#define ll long long

ll inv_gauss_sum(ll x){
    return -(ll)((1-std::sqrt(1 + 8*x)) / 2);
}

int main(){
    ll a, b; std::cin >> a >> b;
    bool swap = a < b;
    ll t = a;
    a = std::max(a, b);
    b = std::min(t, b);
    
    ll end = inv_gauss_sum(a+b);
    std::vector<bool> taken(end);
    ll max = inv_gauss_sum(a);
    ll sum = (max*(1+max)) / 2;

    for (; max>=1; --max){
        ll d = std::min(end-max, a-sum);
        sum += d;
        end = max+d-1;
        taken[max+d-1] = true;
    }
    
    std::vector<int> ans_a;
    std::vector<int> ans_b;
    for (size_t i=0; i<taken.size(); ++i){
        if (taken[i] ^ swap){
            ans_a.push_back(i+1);
        } else {
            ans_b.push_back(i+1);
        }
    }
    std::cout << ans_a.size() << '\n';
    for (int v : ans_a) std::cout << v << ' ';
    std::cout << '\n' << ans_b.size() << '\n';
    for (int v : ans_b) std::cout << v << ' ';
    std::cout << '\n';
}


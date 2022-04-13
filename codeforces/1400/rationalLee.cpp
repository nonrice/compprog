#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

#define ll long long

ll solve(std::vector<int>& a, std::vector<int>& w){
    std::sort(a.begin(), a.end());
    std::sort(w.begin(), w.end(), std::greater<int>());
    
    int ones = 0;
    for (int i=w.size(); i>0 && w[--i]==1;) ++ones;
    ll total = 2 * std::accumulate(a.end()-ones, a.end(), 0LL);
    auto p1 = a.begin();
    auto p2 = a.end()-ones-1;
    for (auto it = w.begin(); it != w.end()-ones; ++it){
        total += *p1 + *p2;
        --p2;
        p1 += *it-1;
    }

    return total;
}

int main(){
    int cases; std::cin >> cases;
    int n, k;
    std::vector<int> a;
    std::vector<int> w;
    while (cases--){
        std::cin >> n >> k;
        a.resize(n);
        w.resize(k);
        for (int i=0; i<n; ++i)
            std::cin >> a[i];
        for (int i=0; i<k; ++i)
            std::cin >> w[i];
        std::cout << solve(a, w) << '\n';
    }
}

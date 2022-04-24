#include <iostream>
#include <algorithm>

#define ll long long

int main(){
    ll n, k, a, b;
    std::cin >> n >> k >> a >> b;

    if (k == 1LL){
        std::cout << a*(n-1) << '\n';
        return 0;
    }
     
    ll cost = 0LL;
    while (n >= k){
        cost += std::min(a*(n-n/k), a*(n%k)+b);
        n /= k;
    }
    std::cout << cost+a*(n-1) << '\n';
    return 0;
}

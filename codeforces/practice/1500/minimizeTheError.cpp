#include <iostream>
#include <queue>
#include <cmath>

#define ll long long

int main(){
    int n, k1, k2; std::cin >> n >> k1 >> k2;
    std::vector<int> a(n), b(n);
    for (int& v : a) std::cin >> v;
    for (int& v : b) std::cin >> v;

    std::priority_queue<int> pq;
    for (int i=0; i<n; ++i)
        pq.push(std::abs(a[i]-b[i]));
    int v;
    for (int i=0; i < k1+k2; ++i){
        v = pq.top(); pq.pop();
        pq.push(std::abs(--v));
    }

    ll ans = 0LL;
    while (!pq.empty()){
        ans += 1LL*pq.top()*pq.top();
        pq.pop();
    }
    std::cout << ans << '\n';
}

#include <iostream>
#include <vector>

bool can_make(std::vector<int>& a, std::vector<int>& b, int n, int k, int c){
    int diff = 0;
    for (int i=0; i<n; ++i){
        diff += std::max(0, c*a[i] - b[i]);
        if (diff > k)
            return false;
    }
    return true;
}

int main(){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::vector<int> b(n);
    for (int i=0; i<n; ++i)
        std::cin >> a[i];
    for (int i=0; i<n; ++i)
        std::cin >> b[i];

    int ans = 0;
    for (int step=1000; step>=1; step/=2){
        while (can_make(a, b, n, k, ans+step))
            ans += step;
    }

    std::cout << ans << '\n';
}

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

int main(){
    std::unordered_map<int, int> fs;
    int x, n, max_f;
    std::cin >> n;
    while (n--){
        std::cin >> x;
        max_f = std::sqrt(x);
        for (int f=2; f<=max_f; ++f){
            if (x%f == 0){
                ++fs[f];
                while (x%f == 0) x/=f;
            }
        }
        fs[x] += x!=1;
    }

    int ans = 1;
    for (auto& p:fs)
        ans = std::max(ans, p.second);
    std::cout << ans << '\n';
}

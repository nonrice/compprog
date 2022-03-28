#include <iostream>
#include <algorithm>

#define ll long long

int main(){
    int n;
    ll nums[200000], nums_exc[200000];
    ll total = 0;
    
    std::cin >> n;
    for (int i=0; i<n; ++i){
        std::cin >> nums[i];
        total += nums[i];
    }
    std::sort(nums, nums+n);
    for (int i=0; i<n; ++i)
        nums_exc[i] = total-nums[i];
    
    int cases;
    ll x, y;
    int l, r;
    std::cin >> cases;
    for (int c=0; c<cases; ++c){
        std::cin >> x >> y;
        l = 0;
        r = n-1;
        for (int step=n-1; step>=1; step/=2){
            while (l+step < n && nums[l+step] <= x)
                l += step;
            while (r-step >= 0 && nums[r-step] >= x)
                r -= step;
        }

        std::cout << std::min(
            std::max(0LL, x-nums[r]) + std::max(0LL, y-nums_exc[r]),
            std::max(0LL, x-nums[l]) + std::max(0LL, y-nums_exc[l])
        ) << "\n";
    }
}

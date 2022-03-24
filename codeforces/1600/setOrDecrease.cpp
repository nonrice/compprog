#include <iostream>
#include <algorithm>
#include <numeric>

#define ll long long

int solve(int* nums, int n, ll k){
    std::sort(nums, nums+n);
    int min = nums[0];
    for (int step=nums[0]; step>=1; step/=2){
        while ((nums[0]-step)*1LL*n > k)
            nums[0] -= step;
    }
    nums[0] -= 1;

    std::cout << nums[0] << '\n';
    std::cout << min << '\n';

    int steps = min-nums[0];
    ll sum = std::accumulate(nums, nums+n, 0);
    for (int i=n; i>0; --i){
        if (sum<=k)
            break;
        sum -= nums[i]-nums[0];
        steps++;
    }

    return steps; 
}

int main(){
    int cases;
    int nums[200000];
    int n;
    ll k;

    std::cin >> cases;
    for (int c=0; c<cases; ++c){
        std::cin >> n >> k;
        for (int i=0; i<n; ++i)
            std::cin >> nums[i];
        std::cout << solve(nums, n, k) << '\n';
    }
}

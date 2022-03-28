#include <iostream>
#include <algorithm>
#include <numeric>

#define ll long long

int calc_steps(int* nums, ll sum, int n, ll k, int start){
    sum -= nums[0]-start;
    ll steps = nums[0]-start;
    for (int i=n-1; i>0; --i){
        if (sum<=k)
            return steps;
        sum -= nums[i]-start;
        steps++;
    }
    return -1;
}

int solve(int* nums, int n, ll k){
    std::sort(nums, nums+n);
    ll sum = std::accumulate(nums, nums+n, 0);
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

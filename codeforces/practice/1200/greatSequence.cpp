#include <iostream>
#include <unordered_map>
#include <algorithm>

int solve(int *nums, int n, int x){
    std::sort(nums, nums+n);
    std::unordered_map<long long, int> freq;
    for (int i=0; i<n; ++i){
        freq[1LL*nums[i]]++;
    }

    int needed = n;
    int num;
    for (int i=0; i<n; ++i){
        num = nums[i];
        if (freq[num]>0 && freq[1LL*num*x]>0){
            freq[num]--;
            freq[num*x]--;
            needed -= 2;
        }
    }

    return needed;
}

int main(){
    int cases, n, x;
    int nums[1000000];
    std::cin >> cases;

    for (int i=0; i<cases; ++i){
        std::cin >> n >> x;
        for (int j=0; j<n; ++j){
            std::cin >> nums[j];
        }
        std::cout << solve(nums, n, x) << "\n";
    }
}


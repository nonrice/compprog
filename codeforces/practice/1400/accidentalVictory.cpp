#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

void solve(std::vector<std::pair<int, int>>& nums, int n){
    std::sort(nums.begin(), nums.begin()+n);
    ll total = 0;
    for (auto it = nums.begin(); it != nums.begin()+n; ++it)
        total += it->first; 

    std::vector<int> ans;
    int i = n-1;
    do {
        ans.push_back(nums[i].second);
        total -= nums[i].first;
    } while (i-- && total >= nums[i+1].first);
    
    std::cout << ans.size() << '\n';
    std::sort(ans.begin(), ans.end());
    for (int num : ans)
        std::cout << num << ' ';
    std::cout << '\n';
}

int main(){
    int cases, n;
    std::vector<std::pair<int, int>> nums(200000);
    
    std::cin >> cases;
    while (cases--){
        std::cin >> n;
        for (int i=0; i<n; ++i){
            std::cin >> nums[i].first;
            nums[i].second = i+1;
        }
        solve(nums, n);
    }
}


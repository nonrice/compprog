#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

bool check(std::vector<int>& nums, int n, int a, int width){
    int last = (nums[0] == a) ? 0 : -1;
    for (int i=0; i<n; ++i){
        if (nums[i] == a)
            last = i;
        if (i-last >= width)
            return false;
    }
    return true; 
}

void solve(){
    int n;
    std::unordered_map<int, int> freq;
    
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i=0; i<n; ++i){
        std::cin >> nums[i];
        ++freq[nums[i]];
    }

    std::vector<int> ans(n, 300001);
    for (int i=0; i<n; ++i){
        auto it = freq.begin();
        while (it != freq.end()){
            if (it->second < n/(n-i)){
                it = freq.erase(it);
            } else {
                if (it->first < ans[i] && check(nums, n, it->first, n-i)) 
                    ans[i] = std::min(ans[i], it->first);
                ++it;
            }
        }
    }

    for (auto it = ans.rbegin(); it != ans.rend(); ++it)
        std::cout << ((*it == 300001) ? -1 : *it) << ' ';
    std::cout << '\n';
}

int main(){
    int cases;
    std::cin >> cases;
    while (cases--)
        solve();
}

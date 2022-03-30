#include <iostream>
#include <queue>
#include <utility>
#include <vector>

void solve(int* nums, int n){
    std::priority_queue<std::pair<int, int>> people;
    for (int i=0; i<n; ++i){
        if (nums[i])
            people.emplace(nums[i], i+1);
    }

    std::pair<int, int> a, b, r;
    std::vector<std::pair<int, int>> ans;
    while (people.size() >= 2){
        a = people.top(); people.pop();
        b = people.top(); people.pop();
        if (a.first > 1)
            people.emplace(a.first-1, a.second);
        if (b.first > 1)
            people.emplace(b.first-1, b.second);
        ans.emplace_back(a.second, b.second);
    }

    std::cout << ans.size() << '\n';
    for (std::pair<int, int>& talk : ans)
        std::cout << talk.first << ' ' << talk.second << '\n';
}

int main(){
    int cases;
    int nums[200000], n;

    std::cin >> cases;
    while (cases--){
        std::cin >> n;
        for (int i=0; i<n; ++i)
            std::cin >> nums[i];
        solve(nums, n);
    }
}

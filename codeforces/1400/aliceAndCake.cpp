#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>

#define ll long long

void solve(int* nums, int n){
    std::unordered_map<int, int> freq;
    for (int i=0; i<n; ++i)
        freq[nums[i]]++;
    int to_use = freq.size();

    std::queue<int> q({std::accumulate(nums, nums+n, 0)});
    ll a;
    while (!q.empty()){
        a = q.front(); q.pop();
        if (!freq.count(a)){
            if (a > 1){
                q.push(a/2);
                q.push((a+1)/2);
            }
        } else {
            if (freq[a] > 0){
                if (freq[a]-- == 0){
                    if (to_use-- == 0)
                        std::cout << "YES\n";
                }
            } else {
                std::cout << "NO\n";
                return;
            }
        }
    }
    
    if (to_use == 0){
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
        std::cout << "asdf";
    }
    return;
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


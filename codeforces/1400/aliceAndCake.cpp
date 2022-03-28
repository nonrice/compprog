#include <iostream>
#include <queue>
#include <numeric>
#include <unordered_set>

#define ll long long

void solve(int* nums, int n){
    ll sum = std::accumulate(nums, nums+n, 0);
    std::queue<ll> q({sum});
    std::unordered_set<ll> valid_weights({sum});
    
    ll a;
    while (q.size()){
        a = q.front(); q.pop();
        valid_weights.insert(a/2);
        valid_weights.insert((a+1)/2);
        if (a!=1 && !valid_weights.count(a)){
            q.push(a/2);
            q.push((a+1)/2);
        }
    }

    for (int i=0; i<n; ++i){
        if (!valid_weights.count(nums[i])){
            std::cout << "NO\n";
            return;
        }
    }
    
    std::cout << "YES\n";
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


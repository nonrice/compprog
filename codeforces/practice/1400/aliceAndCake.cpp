#include <iostream>
#include <numeric>
#include <set> // Multiset is basically better priority queue 
#include <stack>

#define ll long long
 
bool solve(int* nums, int n){
    std::multiset<ll> cake({std::accumulate(nums, nums+n, 0LL)});
    std::multiset<ll> req(nums, nums+n);
    while (!cake.empty()){
        ll v = *--cake.end();
        if (v < *--req.end())
            return req.empty();
        cake.erase(--cake.end());
        if (req.count(v)){
            req.erase(req.find(v));
        } else {
            cake.insert(v/2);
            cake.insert((v+1)/2);
        }
    }

    return req.empty();
}
 
int main(){
    int cases;
    int nums[200000], n;
    
    std::cin >> cases;
    while (cases--){
        std::cin >> n;
        for (int i=0; i<n; ++i)
            std::cin >> nums[i];
 
        if (solve(nums, n)){
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}
 

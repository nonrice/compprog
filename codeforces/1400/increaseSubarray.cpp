#include <iostream>
#include <algorithm>

void solve(int *nums, int n, int x){
    int subarrs[5001];
    std::fill_n(subarrs, 5001, -1000000000);
    subarrs[0] = 0;

    int total;
    for (int start=0; start<n; ++start){
        total = 0;
        for (int end=start; end<n; ++end){
            total += nums[end];
            subarrs[end-start+1] = std::max(subarrs[end-start+1], total);
        }
    }

    int max_total;
    for (int k=0; k<=n; ++k){
        max_total = 0;
        for (int len=0; len<=n; ++len){
            max_total = std::max(max_total, subarrs[len] + x*std::min(k, len));
        }
        std::cout << max_total << " ";
    }

    std::cout << "\n";
}

int main(){
    int nums[5000];
    int n, x;
    int cases;
    std::cin >> cases;
    
    for (int i=0; i<cases; ++i){
        std::cin >> n >> x;
        for (int j=0; j<n; ++j){
            std::cin >> nums[j];
        }
        solve(nums, n, x);
    }
}

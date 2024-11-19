#include <iostream>
#include <vector>
#include <algorithm>

int solve(){
    int n, a;
    std::cin >> n;
     
    std::vector<int> f(n+1);
    while (n--){
        std::cin >> a;
        ++f[a];
    }
    std::sort(f.rbegin(), f.rend());

    int ans = f[0];
    int prev = f[0];
    for (auto it = ++f.begin(); it != f.end(); ++it){
        if (*it >= prev){
            if (!prev)
                break;
            ans += --prev;
        } else {
            ans += prev=*it;
        }
    }
    
    return ans;
}

int main(){
    int cases;
    std::cin >> cases;
    while (cases--)
        std::cout << solve() << '\n';
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>

#define ll long long

int solve(){
    int n;
    std::cin >> n;
    
    std::vector<std::pair<int, int>> a(n+1);
    std::vector<int> b(n+1);
    for (int i=0; i<n; ++i){
        std::cin >> a[i].first;
        a[i].second = i;
    }
    for (int i=0; i<n; ++i)
        std::cin >> b[i];
    std::sort(a.begin(), a.end(), std::greater<std::pair<int, int>>());
    
    ll drive = 0LL;
    ll ans = (ll)a[0].first;
    for (int i=0; i<=n; ++i){
        ans = std::min(ans, std::max((ll)a[i].first, drive));
        drive += b[a[i].second];
    }

    return ans;
}

int main(){
    int cases;
    std::cin >> cases;
    while (cases--)
        std::cout << solve() << '\n';
}


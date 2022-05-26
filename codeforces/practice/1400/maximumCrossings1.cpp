#include <iostream>
#include <vector>

void solve(){
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int& v : a){
        std::cin >> v;
        --v; //0 indexing
    }
    
    int ans = 0;
    for (int i=0; i<n; ++i){
        for (int j=i+1; j<n; ++j){
            ans += a[i] >= a[j]; 
        }
    }

    std::cout << ans << '\n';
}

int main(){
    int cases; std::cin >> cases;
    while (cases--){
        solve();
    }
}


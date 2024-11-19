#include <iostream>
#include <string>
#include <algorithm>

void solve(){
    std::string s; std::cin >> s;
    const int n = s.length();

    int gap = std::count(s.begin(), s.end(), '1');
    int mid = std::count(s.begin(), s.begin()+gap, '0');
    int bst = mid;
    for (int i=0; i<n-gap; ++i){
        mid += (s[i+gap]=='0') - (s[i]=='0');
        bst = std::min(bst, mid);
    }
    std::cout << bst << '\n';
}

int main(){
    int cases; std::cin >> cases;
    while (cases--){
        solve();
    }
}


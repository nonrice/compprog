#include <iostream>

int main(){
    int t, s, q; std::cin >> t >> s >> q;
    int cur = s;
    int ans = 0;
    while (cur < t){
        cur += (q-1)*cur;
        ++ans;
    }
    std::cout << ans << '\n';
}


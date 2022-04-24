#include <iostream>
#include <string>
#include <unordered_map>

#define ll long long
#define f first
#define s second

int main(){
    int n; std::cin >> n;
    std::unordered_map<int, int> fs;
    std::string s;
    while (n--){
        std::cin >> s;
        int b=0, mc=0;
        for (char ch : s){
            if (ch == '('){
                ++b;
            } else {
                if (b>0) --b;
                else ++mc;
            }
        }

        if (!(mc>0 && b>0)){
            if (mc>0) ++fs[-mc];
            else ++fs[b];
        }
    }

    ll ans = fs[0];
    for (auto& p : fs){
        if (p.f >= 0)
            ans += 1LL * p.s * (fs[-p.f] - (p.f==0));
    }
    std::cout << ans << '\n';
}


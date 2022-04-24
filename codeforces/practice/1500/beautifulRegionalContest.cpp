#include <iostream>
#include <vector>
#include <map> 
#include <functional>

#define fail() std::cout << "0 0 0\n"; return
 
void solve(){
    std::map<int, int, std::greater<int>> p;
    int n, a; std::cin >> n;
    for (int i=0; i<n; ++i){
        std::cin >> a;
        ++p[a];
    }

    auto it = p.begin();
    int g = (it++)->second;

    int s = 0;
    while (it != p.end() && s<=g)
        s += (it++)->second;
    if (s <= g){ fail(); }
    
    int b = 0;
    while (it != p.end() && g + s + b + it->second <= n/2)
        b += (it++)->second;
    if (b<=g || g+s+b > n/2){ fail(); }

    std::cout << g << ' ' << s << ' ' << b << '\n';
}
 
int main(){
    int cases; std::cin >> cases;
    while (cases--)
        solve();
}


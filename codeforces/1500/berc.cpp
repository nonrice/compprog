#include <iostream>
#include <vector>
 
#define fail() std::cout << "0 0 0\n"; return
 
void solve(std::vector<int>& p){
    if (p.size()<=11){ fail(); }
 
    size_t t=0, g=1, s=1;
    while (p[t]==p[t+1]){
        ++g; ++t;
        if (t>p.size()/2){ fail(); }
    }

    ++t;
    while (p[t]==p[t+1] || s<=g){
        ++s; ++t;
        if (t>p.size()/2){ fail(); }
    }

    ++t;
    size_t b_end = p.size()/2 - 1;
    while (p[b_end]==p[b_end+1]){
        --b_end;
        if (b_end < t){ fail(); }
    }
    if (b_end-t+1 <= g){ fail(); }
 
    std::cout << g << ' ' << s << ' ' << b_end-t+1 << '\n';
}
 
int main(){
    int cases; std::cin >> cases;
    int n;
    std::vector<int> p;
    while (cases--){
        std::cin >> n;
        p.resize(n);
        for (int i=0; i<n; ++i)
            std::cin >> p[i];
        solve(p);
    }
}


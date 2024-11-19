#include <iostream>
#include <vector>
#include <algorithm>

void solve(){
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> g(n, std::vector<int>(m));
    for (auto& r : g)
        for (auto& c : r)
            std::cin >> c;
    
    int bad1 = -1, bad2 = -1;
    for (auto& r : g){
        std::vector<int> t = r;
        std::vector<int> mis;
        std::sort(t.begin(), t.end());
        for (int i=0; i<m; ++i){
            if (t[i] != r[i]) mis.push_back(i);
            if (mis.size() > 2){
                std::cout << "-1\n";
                return;
            }
        }
        
        if (mis.size() == 2){
            bad1 = mis[0];
            bad2 = mis[1];
        }
    }

    if (bad1 == -1 && bad2 == -1){
        std::cout << "1 1\n";
        return;
    }

    for (auto& r : g){
        std::swap(r[bad1], r[bad2]);
        if (!std::is_sorted(r.begin(), r.end())){
            std::cout << "-1\n";
            return;
        }
    }

    std::cout << bad1+1 << ' ' << bad2+1 << '\n';
}

int main(){
    int cases; std::cin >> cases;
    while (cases--){
        solve();
    }
}


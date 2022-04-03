#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> parts(n);
    std::unordered_map<int, int> v_lookup;
    for (int i=0; i<n; ++i){
        std::cin >> parts[i].first;
        parts[i].second = i+1;
        v_lookup[i+1] = parts[i].first;
    }
    std::sort(parts.begin(), parts.end(), std::greater<std::pair<int, int>>());

    std::vector<std::unordered_set<int>> adj(n+1);
    int a, b;
    for (int i=0; i<m; ++i){
        std::cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    
    int cost = 0;
    for (auto& p : parts){
        for (int neighbour : adj[p.second]){
            cost += v_lookup[neighbour];
            adj[neighbour].erase(p.second);
        }
    }

    std::cout << cost << '\n';
}


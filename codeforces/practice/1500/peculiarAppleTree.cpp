#include <iostream>
#include <vector>
#include <queue>

int main(){
    int n; std::cin >> n;
    std::vector<int> p(n);
    for (int i=1; i<n; ++i){
        std::cin >> p[i];
        --p[i];
    }

    std::vector<std::vector<int>> adj(n, std::vector<int>());
    for (int i=1; i<n; ++i)
        adj[p[i]].push_back(i);

    int ans = 0;
    std::queue<int> bfs({0});
    while (!bfs.empty()){
        int collect = 0;
        int cur_layer = bfs.size();
        while (cur_layer--){
            for (int neighbor : adj[bfs.front()])
                bfs.push(neighbor);
            collect ^= 1;
            bfs.pop();
        }
        ans += collect;
    }
    std::cout << ans << '\n';
}

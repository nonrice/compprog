#include <vector>
#include <tuple>
#include <climits>

#include <iostream>

/* Given a path from source to u and an edge from u to v exists, source->v
 * must equal min(source->u + u->v , source->v).
 */

int* bellman_ford(
    std::vector<std::tuple<int, int, int>>& edges, // Edge list
    int n, // Highest # number
    int start // Starting node index
){
    int* dists = new int[n];
    std::fill_n(dists, n+1, INT_MAX);

    dists[start] = 0;
    int a, b, w;
    for (int i=1; i<=n-1; ++i){
        for (auto e : edges){
            std::tie(a, b, w) = e; // unpack edge tuple into variables
            if (dists[a]!=INT_MAX && dists[a]+w < dists[b])
                dists[b] = dists[a]+w;
        }
    }

    return dists;
}

int main(){
    std::vector<std::tuple<int, int, int>> graph; // DIRECTIONAL graph
    graph.push_back({0, 1, 5});
    graph.push_back({0, 2, 3});
    graph.push_back({0, 3, 7});
    graph.push_back({2, 3, 1});
    graph.push_back({3, 4, 2});
    graph.push_back({1, 4, 2});
    graph.push_back({1, 3, 3});
    int n = 4;
    int* dists = bellman_ford(graph, n, 0);
    for (int i=0; i<=n; ++i)
        std::cout << dists[i] << ' ';
    std::cout << '\n';
}


#include <iostream>
#include <unordered_map>

int start[100000];
int end[100000];
int prev[100000];
int next[100000];

int main(){
    int len;
    std::cin >> len;
    for (int i = 0; i < len; i++)
        std::cin >> start[i];

    // Initialize linked list for end array
    std::unordered_map<int, int> end_lookup;
    int val;
    for (int i = 0; i < len; i++){
        prev[i] = i-1;
        next[i] = i+1;
        
        std::cin >> val;
        end[i] = val;
        end_lookup.insert(std::make_pair(val, i));
    }
    next[len-1] = -1;

    int index;
    int moves = 0;
    for (int i = 0; i < len; i++){
        index = end_lookup[end[i]];
        if (prev[index] != -1)
            moves += 1;
        
        if (index < len-1){
            prev[next[index]] = prev[index];
            next[prev[index]] = next[index];
        }
    }

    std::cout << moves;
}

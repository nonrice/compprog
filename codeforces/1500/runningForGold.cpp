#include <iostream>
#include <algorithm>
#include <vector>

bool cmp_athletes(std::vector<int>& a, std::vector<int>& b){
    int wins = 0;
    for (int m=0; m<5; ++m)
        wins += a[m]<b[m] ? 1 : -1;
    return wins>0;
}

bool is_winner(std::vector<std::vector<int>>& athletes_sorted, int num_athletes){
    for (int n=1; n<num_athletes; ++n){
        if (!cmp_athletes(athletes_sorted[0], athletes_sorted[n]))
            return false;
    }
    return true;
}

int main(){
    int cases;
    int num_athletes;
    std::vector<std::vector<int>> athletes(50000, std::vector<int>(6));

    std::cin >> cases;
    for (int c=0; c<cases; ++c){
        std::cin >> num_athletes;
        for (int n=0; n<num_athletes; ++n){
            athletes[n][5] = n+1;
            for (int a=0; a<5; ++a)
                std::cin >> athletes[n][a];
        }

        std::sort(athletes.begin(), athletes.begin()+num_athletes, cmp_athletes);
        std::cout << (is_winner(athletes, num_athletes) ? athletes[0][5] : -1) << "\n";
    }
}

#include <iostream>

bool solve(int n){
    for (int t=n/111*111; t>=0; t-=111){
        if ((n-t)%11 == 0)
            return true;
    }
    return false;
}

int main(){
    int cases, n;
    std::cin >> cases;
    for (int c=0; c<cases; ++c){
        std::cin >> n;
        if (solve(n)){
            std::cout << "YES" << "\n";
        } else {
            std::cout << "NO" << "\n";
        }
    }
}


#include <iostream>

int main(){
    int n; std::cin >> n;
    if (n<6){
        std::cout << "-1\n";
    } else {
        std::cout << "1 2\n1 3\n1 4\n3 5\n3 6\n";
        if (n%2)
            std::cout << "3 7\n";
        for (int u = 6+n%2; u<n; ++u)
            std::cout << u << ' ' << u+1 << '\n';
    }

    for (int u=1; u<n; ++u)
        std::cout << u << ' ' << u+1 << '\n';
}


#include <iostream>
#include <cmath>

int solve(int n){ // Return only A because B can be derived from it 
    const int max_f = std::round(std::sqrt(n));
    for (int f=2; f<=max_f; ++f){
        if (n%f==0)
            return n/f;
    }
    return 1;
}

int main(){
    int cases;
    std::cin >> cases;

    int n, a;
    for (int i=0; i<cases; ++i){
        std::cin >> n;
        a = solve(n);
        std::cout << a << " " << n-a << "\n";
    }
}

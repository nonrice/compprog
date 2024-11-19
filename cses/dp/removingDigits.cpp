#include <iostream>
#include <algorithm>

// is this even a dp problem

int largest_digit(int n){
    int max = 0;
    do {
        max = std::max(n%10, max);
    } while (n/=10);
    return max;
}

int main(){
    int n; std::cin >> n;
    int steps = 0;
    do {
        ++steps;
    } while (n -= largest_digit(n));
    std::cout << steps << '\n';
}


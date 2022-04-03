#include <iostream>

// divide until b < a, then add what is needed
int solve(int a, int b){ 
    if (a >= b)
        return a-b;
    return b%2 + 1 + solve(a, (b + b%2)/2);
}

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << solve(a, b) << '\n';
}

#include <iostream>

int main(){
    int weight;
    std::cin >> weight;
    std::cout << ((weight%2==0 && weight>2) ? "YES\n" : "NO\n");
}

#include <iostream>
#include <string>

// How is this a 1400 problem
// I guess the observation makes it hard?? But not really though.

int main(){
    std::string s;
    std::cin >> s;
    std::cout << "3\n R " << s.length()-1 << '\n';
    std::cout << "L " << s.length() << '\n';
    std::cout << "L " << 2 << '\n';
}

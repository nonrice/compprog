#include <iostream>
#include <string>

int solve(std::string& s){
    const int len = s.size();
    int b_count = 0;
    
    // Match: aa
    for (int i=1; i<len; ++i){
        if (s[i]=='a' && s[i-1]=='a')
            return 2;
    }
    
    // Match: aba or aca
    for (int i=2; i<len; ++i){
        if (s[i]=='a' && s[i-2]=='a')
            return 3;
    }
    
    // Match: abca or acba
    for (int i=3; i<len; ++i){
        if (s[i]=='a' && s[i-3]=='a'){
            if (s[i-1]=='b') ++b_count;
            if (s[i-2]=='b') ++b_count;
            if (b_count == 1)
                return 4;
            b_count = 0;
        }
    }
    
    // Match: abbacca or accabba
    for (int i=6; i<len; ++i){
        if (s[i]=='a' && s[i-3]=='a' && s[i-6]=='a'){
            if (s[i-1]=='b') ++b_count;
            if (s[i-2]=='b') ++b_count;
            if (s[i-4]=='b') ++b_count;
            if (s[i-5]=='b') ++b_count;
            if (b_count==2)
                return 7;
            b_count = 0;
        }
    }

    return -1;
}

int main(){
    int cases, n;
    std::string s;
    
    std::cin >> cases;
    while (cases--){
        std::cin >> n;
        std::cin >> s;
        std::cout << solve(s) << '\n';
    }
}

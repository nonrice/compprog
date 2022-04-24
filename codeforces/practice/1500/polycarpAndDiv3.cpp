#include <iostream>
#include <cstring>

#define cr3(a) (s[a]-48)%3

int main(){
    char s[200001];
    std::cin >> s;
    int len = std::strlen(s);
    
    int result = 0;
    int last = -1;
    for (int i=0; i<len; ++i){
        if (cr3(i) == 0){
            ++result;
            last = i;
        } else if (i-last>1 && cr3(i)+cr3(i-1) == 3){
            ++result;
            last = i;
        } else if (i-last>2 && cr3(i)==cr3(i-1) && cr3(i-1)==cr3(i-2)){
            ++result;
            last = i;
        }
    }
    
    std::cout << result << '\n';
}

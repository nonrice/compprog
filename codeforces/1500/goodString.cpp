#include <iostream>
#include <string>

int calc_needed(const std::string& str, char a, char b){
    int seq_part = 0;
    int exc = 0;
    for (char ch:str){
        if (!seq_part && ch==a){
            ++exc;
            seq_part = 1;
        } else if (seq_part && ch==b){
            ++exc;
            seq_part = 0;
        }
    }
    
    if (a!=b)
        return (seq_part==1) ? str.size()-exc+1 : str.size()-exc;
    return str.size()-exc;
}

int main(){
    int cases;
    int min_needed;
    std::string str;

    std::cin >> cases;
    for (int c=0; c<cases; ++c){
        std::cin >> str;
        min_needed = str.size();

        for (int a=0; a<=9; ++a){
            for (int b=0; b<=9; ++b){
                min_needed = std::min(
                    min_needed,
                    calc_needed(str, '0'+a, '0'+b)
                );
            }
        }

        std::cout << min_needed << '\n';
    }
}

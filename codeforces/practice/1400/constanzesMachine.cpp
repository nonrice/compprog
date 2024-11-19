#include <iostream>

#define MOD 1000000007

/* 
 * For a sequence of x 'n's or 'u's, the combinations of contractions
 * into 'm' and 'w' is equal to the xth term of the fibonacci sequence
 * for some reason.
 */
int* calc_fibonacci(int len){
    int* seq = new int[len];
    seq[0] = seq[1] = 1; 
    for (int i=2; i<len; ++i)
        seq[i] = (seq[i-1]+seq[i-2])%MOD;
    return seq;
}

int main(){
    std::string s;
    std::cin >> s;
    s += '!';
    int len = s.length();

    char letter = ' ';
    int ans = 1;
    int start;
    int* fibonacci = calc_fibonacci(len);
    for (int i=0; i<len; ++i){
        if (s[i]=='m' || s[i]=='w'){
            std::cout << 0 << '\n';
            return 0;
        }
        if (letter!=' ' && s[i]!=letter){
            if (i-start > 1)
                ans = ((long long)ans * fibonacci[i-start])%MOD;
            letter = ' ';
        } 
        if (letter==' ' && (s[i]=='n' || s[i]=='u')){
            start = i;
            letter = s[i];
        }
    }

    std::cout << ans << '\n';
    return 0;
}


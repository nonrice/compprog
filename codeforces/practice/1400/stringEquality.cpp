#include <iostream>
#include <cstring>

bool solve(char* a, char* b, int n, int k){
    int fa[26], fb[26];
    std::memset(fa, 0, sizeof(int)*26);
    std::memset(fb, 0, sizeof(int)*26);
    for (int i=0; i<n; ++i){
        ++fa[a[i]-97];
        ++fb[b[i]-97];
    }

    int r_extra = 0;
    for (int i=0; i<26; ++i){
        if (fa[i]>fb[i]){
            if ((fa[i]-fb[i])%k != 0){
                return false;
            } else {
                r_extra += fa[i]-fb[i];
            }
        } else if (fa[i]<fb[i]){
            if ((fb[i]-fa[i])%k != 0 || fb[i]-fa[i] > r_extra){
                return false;
            } else {
                r_extra -= fb[i]-fa[i];
            }
        }
    }

    return r_extra==0;
}

int main(){
    int cases, n, k;
    char a[1000000], b[1000000];

    std::cin >> cases;
    while (cases--){
        std::cin >> n >> k >> a >> b;
        std::cout << (solve(a, b, n, k) ? "YES" : "NO") << '\n';
    }
}


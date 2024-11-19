#include <stdio.h>

#ifdef __APPLE__ 
    #define putchar_fast putchar_unlocked
#endif

#ifdef _WIN32
    #define putchar_fast _putchar_nolock 
#endif

void solve(){
    int n, k; scanf("%d%d", &n, &k);
    
    putchar_fast((k!=0 && k%n) ? '2' : '0');
    putchar_fast('\n');
    for (int r=0; r<n; ++r){
        for (int c=0; c<n; ++c){
            int diff = (r<c) ? n-(c-r) : r-c;
            if (diff*n + c < k) putchar_fast('1');
            else putchar_fast('0');
        }
        putchar_fast('\n');
    }
}

int main(){
    int cases; scanf("%d", &cases);
    while (cases--) solve();
}

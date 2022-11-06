#include <stdio.h>

int a[500][500];
bool c[500][500]; // if you offer gift i, can you recieve gift j? 

int main(){
    int n; scanf("%d", &n);
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            scanf("%d", &a[i][j]);
            --a[i][j];
        }
    }

    for (int i=0; i<n; ++i){
        for (int j=0; j<n && a[i][j] != i; ++j){
            c[a[i][j]][i] = true;
        }
    }

    for (int k=0; k<n; ++k){
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                c[i][j] |= c[i][k] && c[k][j];
            }
        }
    }

    for (int i=0; i<n; ++i){
        bool f = false;
        for (int j=0; j<n && a[i][j] != i; ++j){
            if (c[i][a[i][j]]){
                printf("%d\n", a[i][j]+1);
                f = true;
                break;
            }
        }
        if (!f) printf("%d\n", i+1);
    }
}

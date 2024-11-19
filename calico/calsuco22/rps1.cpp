#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    char bruh;
    int step = 0;
    while (t--){
        if (step <= 1){
            cout << "R" << endl;
        } else {
            cout << "S" << endl;
        }
        step = (step+1) % 3;
        //cin >> bruh;
    }
}

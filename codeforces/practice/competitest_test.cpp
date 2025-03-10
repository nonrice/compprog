#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int a, b; cin >> a >> b;
    
    vector<int> x(5);
    for (int i=0; i<=5; ++i){
        x[i] = i;
    }

    cout << a*b << '\n';
}

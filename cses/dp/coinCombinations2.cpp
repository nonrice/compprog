#include <iostream>
using namespace std;

using ll = long long;

int c[100];
ll dp[1000001]; // = {0, 1} wont work on cses for some reason;

int main(){
    dp[0] = 1;

    int n, x; cin >> n >> x;
    for (int i=0; i<n; ++i)
        cin >> c[i];

    for (int j=0; j<n; ++j){
        for (int i=0; i<=x; ++i){
            if (c[j] <= i)
                dp[i] = (dp[i] + dp[i-c[j]]) % 1000000007;
        }
    }
    
    cout << dp[x] << '\n';
}

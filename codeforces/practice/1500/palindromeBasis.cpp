#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> pals;
ll dp[40001] = { 1 };

int main(){
    for (int p=1; p<40001; ++p){
        int tp = p;
        int rev = 0;
        while (tp != 0){
            rev = rev*10 + tp%10;
            tp /= 10;
        }

        if (rev == p) pals.push_back(p);
    }

    for (int p : pals){
        for (int i=0; i<40001; ++i){
            if (p <= i)
                dp[i] = (dp[i] + dp[i-p]) % 1000000007;
        }
    }

    int cases; cin >> cases;
    while (cases--){
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}


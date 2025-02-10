#include <bits/stdc++.h>
using namespace std;

vector<int> c;
map<int, int> mem;
int x;

int dp(int i){
    if (mem.count(i)){
        return mem[i];
    }

    int ans = INT_MAX;
    for (int h : c){
        if (i-h >= 0){
            ans = min(ans, dp(i-h) + 1);
        }
    }
    mem[i] = ans;
    return ans;
}

int main(){

    vector<int> c;

    vector<int> dp(x+1);
    for (int i=0; i<=x; ++i){
        dp[i] = INT_MAX;
        for (int h : c){
            if (i-h >= 0){
                dp[i] = min(dp[i], dp[i-h] + 1);
            }
        }
    }

}

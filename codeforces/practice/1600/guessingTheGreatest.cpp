#include <bits/stdc++.h>
using namespace std;

int ask(int l, int r){
    cout << "? " << l << ' ' << r << endl;
    int x; cin >> x;
    return x;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int s = ask(1, n);
        
    int cur;
    if (s!=n && ask(s, n) == s){
        cur = n+1;
        for (int step=n-s; step>=1; step/=2){
            while (cur-step>s && ask(s, cur-step) == s) cur -= step;
        }
    } else {
        cur = 0;
        for (int step=s-1; step>=1; step/=2){
            while (cur+step<s && ask(cur+step, s) == s) cur += step;
        }
    }

    cout << "! " << cur << endl;
}

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto chk = [&](int x) {
    char p = 'x';
    int y = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] > x) {
        if (p == 'x') {
          p = s[i];
          y += (s[i] == 'B');
          continue;
        }
        if (p != s[i]) {
          y += (s[i] == 'B');
          p = s[i];
        }
      }
    }
    return y <= k;
  };

  int ans = *max_element(a.begin(), a.end());
  for (int h = ans; h >= 1; h /= 2) {
    while (ans - h >= 0 && chk(ans - h)) {
      ans -= h;
    }
  }

  cout << ans << '\n';
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

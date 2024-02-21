#include <bits/stdc++.h>
using namespace std;

long long a[100], b[100], c[100];

void solve(){
	int n; cin >> n;
	long long ic, im; cin >> ic >> im;
	for (int i=0; i<n; ++i) cin >> a[i] >> b[i] >> c[i];

	long long oc=0, om=0;
	for (int i=0; i<n; ++i){
		for (int j=i+1; j<n; ++j){
			if (a[i]*b[j] != a[j]*b[i]){
				long long cc = (b[i]*(-c[j])-b[j]*(-c[i]))/(a[i]*b[j]-a[j]*b[i]);
				long long cm = ((-c[i])*a[j]-(-c[j])*a[i])/(a[i]*b[j]-a[j]*b[i]);
				if (cc > 0 && cm > 0){
				cout << cc << ' ' << cm << '\n';
					bool s = true;
					for (int k=0; k<n; ++k){
						if (a[k]*cc + b[k]*cm > c[k]){
							s = false;
							break;
						}
					}
					if (s){
						cc = min(oc, cc);
						cm = min(om, cm);
						if (cc+cm > oc+om){
							oc = cc;
							om = cm;
						}
					}
				}
			}
		}
	}

	cout << ic-oc+im-om << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}

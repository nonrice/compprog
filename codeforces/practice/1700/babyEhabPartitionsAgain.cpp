// If a/k (dividing each element of a by k) can be partitioned, so can a, by distributive property. Of course, all a[i] must be divisible by k.
// If the sum of a is odd, it cannot be partitioned, obviously
//
// Therefore if there exists some k such that the sum of a is odd, a cannot be partitioned. To verify this condition it is sufficient to just test k=gcd(a), because it has the largest possible amount of 2 factors eliminated. This handles all cases where the array has at least one odd sum for some k. 
//
// Unfortunately this condition is not sufficient to prove the inverse, so if the array has even sum, it's partitionability is uncertain. In that case a typical knapsack dp can be used to find all possible subset sums in O(n^2*MXA) time. This handles the case where the array has even sum no matter the k, but is actually not partitionable.
//
// Now to construct a solution for a which has even sum no matter the k, is actually is partitionable. Given that there is no k such that the sum of a is odd, at least one change must be made. While some of the possible changes may leave a with an even sum, it can be proven by contradiction that there always exists a change to leave a with an odd sum. Let k be the largest power of 2 that is a common divisor of all a[i]. If the resulting a[i]/k are all even, then k can at least be doubled, contradicting the previous statement. This means at least one a[i]/k must be odd. This is a valid constuction to handle the last case.
//

#include <bits/stdc++.h>
using namespace std;

constexpr int MXN = 100;
constexpr int MXA = 2000;

bool dp[MXN+1][MXN*MXA+1] = { { 1 } };
int a[MXN];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];

	int div = a[0];
	for (int i=1; i<n; ++i) div = gcd(a[i], div);
	
	int sum = 0;
	for (int i=0; i<n; ++i){
		a[i] /= div;
		sum += a[i];
	}

	if (sum % 2){
		cout << "0\n";
		return 0;
	}

	for (int i=1; i<=n; ++i){
		for (int j=0; j<=MXN*MXA; ++j){
			dp[i][j] = dp[i-1][j];
			if (j-a[i] >= 0) dp[i][j] |= dp[i-1][j-a[i]];
		}
	}

	if (dp[n][sum/2]){
		for (int i=0; i<n; ++i){
			if (a[i] % 2){
				cout << "1\n" << i+1 << '\n';
				return 0;
			}
		}
	} else {
		cout << "0\n";
	}


}




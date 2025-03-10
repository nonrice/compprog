#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> make_evils(ll prime, ll n)
{
	vector<ll> ret(n);
	for (ll i = 0; i < n; i++)
		ret[i] = (i + 1) * prime;
	return ret;
}

unordered_set<ll> st;
void test_evils(const vector<ll>& evils)
{
	st = unordered_set<ll>();

	clock_t start = clock();

	for (ll x : evils)
		st.insert(x);

	clock_t end = clock();

	cout << fixed;
	cout.precision(3);
	cout << "Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
}

int main()
{
	vector<ll> evils = make_evils(172933, 200000);
    cout << "1\n200000\n";
    for (int i=0; i<200000; ++i){
        cout << evils[i];
        if (i != 199999){
            cout << ' ';
        }
    }
	//test_evils(evils);
}
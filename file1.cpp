#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
#define ll long long
#define db long double
#define S second
#define MOD 1000000007
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()

const int  N = 1e9 + 7;
const int  P = 1e9;

bool *visited = new bool[100000];
bool *visit = new bool[100000];




ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}

ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}



bool isSubsetSum(ll arr[], ll n, ll sum)
{
	// The value of subset[i%2][j] will be true
	// if there exists a subset of sum j in
	// arr[0, 1, ...., i-1]
	bool subset[2][sum + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {

			// A subset with sum 0 is always possible
			if (j == 0)
				subset[i % 2][j] = true;

			// If there exists no element no sum
			// is possible
			else if (i == 0)
				subset[i % 2][j] = false;
			else if (arr[i - 1] <= j)
				subset[i % 2][j] = subset[(i + 1) % 2]
				                   [j - arr[i - 1]] || subset[(i + 1) % 2][j];
			else
				subset[i % 2][j] = subset[(i + 1) % 2][j];
		}
	}

	return subset[n % 2][sum];
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(3);
	vector<ll> b(3);
	for (int i = 0; i < 3; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 3; ++i)
	{
		cin >> b[i];
	}
	int ans1 = INT_MAX;
	vector<pair<int, int> > ord;
	ord.push_back({0, 0});
	ord.push_back({0, 2});
	ord.push_back({1, 1});
	ord.push_back({1, 0});
	ord.push_back({2, 2});
	ord.push_back({2, 1});
	sort(all(ord));
	do {
		vector<ll> a1 = a, b1 = b;
		for (int i = 0; i < sz(ord); i++) {
			int cnt = min(a1[ord[i].first], b1[ord[i].second]);
			a1[ord[i].first] -= cnt;
			b1[ord[i].second] -= cnt;
		}
		int cur = min(a1[0], b1[1]) + min(a1[1], b1[2]) + min(a1[2], b1[0]);
		ans1 = min(ans1, cur);
	} while (next_permutation(all(ord)));
	int ans2 = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
	cout << ans1 << ' ' << ans2 << endl;

}




int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	cin >> t;


	while (t--)
	{


		solve();

	}
	//solve();
	return 0;
}


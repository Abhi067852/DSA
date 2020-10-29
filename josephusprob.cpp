#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define S second
#define MOD 1000000007
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()

//const int  N = 1e9 + 7;
const int  P = 1e9;
int n, d;
int adj[5001][5001]; // adjacency matrix of graph
const int INF = 1000000000; // weight INF means there is no edge
const int mx = 100001;
ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}
ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

void josephus(std::vector<ll> &v, ll k, ll i, ll &ans)
{	if (v.size() == 1)
	{
		ans = v[0];
		return ;
	}
	i = (i + k) % v.size();
	v.erase(v.begin() + i);
	josephus(v, k, i, ans);


}

void solve() {
	ll n, k;
	cin >> n >> k;
	k--;
	std::vector<ll> v;
	ll ans = -1;
	for (int i = 1; i <= n; ++i)
	{
		v.push_back(i);
	}
	josephus(v, k, 0, ans);
	cout << ans;
}






int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// ll t ;
	// cin >> t;


	// while (t--)
	// {


	// 	solve();

	// }
	solve();
	return 0;
}

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
void tower(ll n, ll s, ll d, ll h, ll &c)
{
	c++;
	if (n == 1)
	{
		cout << "moving plate 1" << "from" << s << "to" << d << "using" << h << endl;
		return;
	}
	tower(n - 1, s, h, d, c);
	cout << "moving plate" << n << "from" << s << "to" << d << "using" << h << endl;
	tower(n - 1, h, d, s, c);

}

void solve() {
	ll n;
	cin >> n;
	ll s, h, d;
	s = 1;
	d = 3;
	h = 2;
	ll c = 0;

	tower(n, s, d, h, c );
	cout << c << endl;



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

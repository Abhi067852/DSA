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



void solve() {
	ll n;
	cin >> n;
	josephus(n);



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

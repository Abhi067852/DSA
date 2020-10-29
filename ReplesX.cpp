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

ll check(ll a[], ll n, ll x)
{
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == x) {
			return 1;

		}

	}
	return 0;
}
ll view(ll a[], ll n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i];
	}
	cout << endl;
}

void solve() {
	ll n, x, p, k;
	cin >> n >> x >> p >> k;
	ll a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	ll pos = 0 ;
	// for (int i = 0; i < n; ++i)
	// {
	// 	if (a[i] == x)
	// 	{
	// 		pos = i;

	// 	}
	// }
	ll c = 0;

	sort(a, a + n);
	ll diff = INT_MAX;
	if (check(a, n, x) == 1) {
		for (int i = 0; i < n; ++i)
		{
			if (a[i] == x)
			{
				if (abs(i - p) < diff) {
					pos = i;
					diff = abs(i - p);
				}

			}
		}
		// cout << pos << endl;;
		//view(a, n);
		//cout << pos << endl;
		if (a[p - 1] == x)
		{
			cout << "0" << endl;
			return;
		}
		if ((p < k && a[p - 1] < x) || (p > k && a[p - 1] > x)) {

			cout << "-1" << endl;
			return;
		}
		cout << abs(p - pos - 1 ) << endl;



	}
	else
	{
		a[k - 1] = x;
		sort(a, a + n);
		for (int i = 0; i < n; ++i)
		{
			if (a[i] == x)
			{
				if (abs(i - p) < diff) {
					pos = i;
					diff = abs(i - p);
				}

			}
		}
		// cout << pos << endl;;
		//view(a, n);
		//cout << pos << endl;
		if (a[p - 1] == x)
		{
			cout << "1" << endl;
			return;
		}
		if ((p < k && a[p - 1] < x) || (p > k && a[p - 1] > x)) {

			cout << "-1" << endl;
			return;
		}
		cout << abs(p - pos - 1) + 1 << endl;




	}
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


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
int n, d;
int adj[5001][5001]; // adjacency matrix of graph
const int INF = 1000000000; // weight INF means there is no edge

struct Edge {
	int w = INF, to = -1;
};



bool *visited = new bool[100000];
bool *visit = new bool[100000];




ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}
ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
void prim() {
	int total_weight = 0;
	vector<bool> selected(n, false);
	vector<Edge> min_e(n);
	min_e[0].w = 0;

	for (int i = 0; i < n; ++i) {
		int v = -1;
		for (int j = 0; j < n; ++j) {
			if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
				v = j;
		}

		if (min_e[v].w == INF) {
			cout << "No MST!" << endl;
			exit(0);
		}

		selected[v] = true;
		total_weight += min_e[v].w;
		// if (min_e[v].to != -1)
		// 	cout << v << " " << min_e[v].to << endl;

		for (int to = 0; to < n; ++to) {
			if (adj[v][to] < min_e[to].w)
				min_e[to] = {adj[v][to], v};
		}
	}

	cout << -1 * total_weight << endl;
}

void solve() {



	cin >> n >> d;

	int dim[n][d];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < d; ++j)
		{
			cin >> dim[i][j];

		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			int diff = 0;
			for (int k = 0; k < d ; ++k)
			{

				diff += abs(dim[i][k] - dim[j][k]);
			}
			adj[i][j] = (-1 * diff);


		}

	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		cout << adj[i][j] << endl;;

	// 	}

	// }
	prim();




}




int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// ll t;
	// cin >> t;


	// while (t--)
	// {


	// 	solve();

	// }
	solve();
	return 0;
}


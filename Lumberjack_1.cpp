#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve();
bool custom(const pair<int, int> &a,
            const pair<int, int> &b)
{
	return (a.second + a.first < b.first + b.second);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("error.txt", "w", stderr);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t = 1;
	// /*is Single Test case?*/cin >> t;
	while (t--)
	{
		solve();

	}

	// cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve()
{

	int t, n, k, x, y, a, b, c, d, rt, up;
	cin >> t >> n >> k;
	std::vector< pair<int, int> > v;
	while (k--) {
		cin >> x >> y >> a >> b >> c >> d;
		v.push_back(make_pair(x, y));

	}
	sort(v.begin(), v.end(), custom);
	rt = v[0].first;
	up = v[0].second;
	// cout << rt << " " << up << "\n";
	while (rt--)cout << "move right\n";
	while (up--)cout << "move up\n";
	cout << "cut up\n";


}
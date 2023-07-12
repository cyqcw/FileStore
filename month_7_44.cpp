#include<bits/stdc++.h>
#include<unordered_map>
// #define int long long
#define INF 0x3f3f3f3f
#define mod 1000000007
#define rep(i, st, ed) for (int (i) = (st); (i) <= (ed);++(i))
#define pre(i, ed, st) for (int (i) = (ed); (i) >= (st);--(i))

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> inline T lowbit(T x) { return x & -x; }

const int N = 100;

pair<LL, LL>cal(LL n, LL m) {
	if (n == 0)return { 0,0 };

	LL cnt = 1ll << (2 * n - 2);
	LL len = 1ll << (n - 1);

	pair<LL, LL>t = cal(n - 1, m % cnt); // 求出 n - 1 级地图中的位置
	LL x = t.first, y = t.second;

	LL z = m / cnt; // 在上一级的哪个区域里

	if (z == 0)return { y,x };
	else if (z == 1)return { x,y + len };
	else if (z == 3)return { 2 * len - y - 1, len - x - 1 };
	else return { x + len,y + len };
}

void solve() {
	LL n, a, b; cin >> n >> a >> b;

	pair<LL, LL>p1 = cal(n, a - 1);
	pair<LL, LL>p2 = cal(n, b - 1);


	printf("%.0lf\n", sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second)) * 10);
}

signed main() {
	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}

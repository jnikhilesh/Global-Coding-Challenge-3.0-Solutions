#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n, m, maxSum; cin >> n >> m >> maxSum;
	vector<long long> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (0 < i) {
			a[i] += a[i - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		if (0 < i) {
			b[i] += b[i - 1];
		}
	}

	int ans = 0;
	for (int i = 0; i < m and b[i] <= maxSum; i++) {
		ans = max(ans, i + 1 + (int)(upper_bound(a.begin(), a.end(), maxSum - b[i]) - a.begin()));
	}

	for (int i = 0; i < n and a[i] <= maxSum; i++) {
		ans = max(ans, i + 1 + (int)(upper_bound(b.begin(), b.end(), maxSum - a[i]) - b.begin()));
	}
	cout << ans;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
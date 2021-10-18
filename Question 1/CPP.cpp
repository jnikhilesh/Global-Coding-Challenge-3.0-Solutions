#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int ans = 2 * (n / 3);
	if (n % 3 > 0) {
		ans += 1;
	}
	cout << ans;
}
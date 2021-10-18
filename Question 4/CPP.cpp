#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int prices[n];
	for (int i = 0; i < n; i++) {
		cin >> prices[i];
	}

	int max_to_left = -1, max_to_right = -1;
	int ans_pairs = 0;
	for (int i = 0; i < n; i++) {
		if (prices[i] <= max_to_left) {
			ans_pairs += 1;
		}
		else {
			max_to_left = prices[i];
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (prices[i] <= max_to_right) {
			ans_pairs += 1;
		}
		else {
			max_to_right = prices[i];
		}
	}
	cout << ans_pairs;
	return 0;
}
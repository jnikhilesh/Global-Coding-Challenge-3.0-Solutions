#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int i_have; cin >> i_have;
	vector<pair<int, int> > price_maxbuy;

	int price, maxbuy = 1;
	while (scanf("%d", &price) == 1) {
		price_maxbuy.push_back(make_pair(price, maxbuy));
		maxbuy += 1;
	}

	sort(price_maxbuy.begin(), price_maxbuy.end());

	int total_bought = 0;
	for (auto p : price_maxbuy) {
		price = p.first;
		maxbuy = p.second;

		int can_buy = min(i_have / price, maxbuy);
		total_bought += can_buy;

		i_have -= (price * can_buy);
	}
	cout << total_bought;
	return 0;
}

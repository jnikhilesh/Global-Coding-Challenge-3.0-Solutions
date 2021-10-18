#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();
	vector<int> segs_zeros;
	int i = 0;
	while (i < n) {
		char curr = s[i];
		int len = 0;
		while (i < n and s[i] == curr) {
			len++;
			i++;
		}

		if (curr == '0') {
			segs_zeros.push_back(len);
		}
	}

	if (segs_zeros.empty()) {
		cout << "B";
		return 0;
	}

	sort(segs_zeros.begin(), segs_zeros.end());
	int maximum = segs_zeros.back(), second_max = -1;
	segs_zeros.pop_back();
	if (!segs_zeros.empty()) {
		second_max = segs_zeros.back();
	}

	if (maximum % 2 == 0 or maximum / 2 < second_max) {
		cout << "B";
	}
	else {
		cout << "A";
	}
	return 0;
}
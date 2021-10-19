#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int *parent, *s, *cnt_of_dep, max_size_allowed, max_size_of_grp = 1, dep_max[3];

/* Matrices are represented as arrays, indexing is different for cnt_of_dep */

int find_set(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find_set(parent[x]);
}

void union_sets(int x, int y) {
	x = find_set(x);
	y = find_set(y);
	if (x == y) {
		return;
	}

	if (s[x] + s[y] > max_size_allowed) {
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (cnt_of_dep[3 * x + i] + cnt_of_dep[3 * y + i] > dep_max[i]) {
			return;
		}
	}

	if (s[x] < s[y]) {
		swap(x, y);
	}

	cnt_of_dep[3 * x + 0] += cnt_of_dep[3 * y + 0];
	cnt_of_dep[3 * x + 1] += cnt_of_dep[3 * y + 1];
	cnt_of_dep[3 * x + 2] += cnt_of_dep[3 * y + 2];

	parent[y] = x;
	s[x] += s[y];
	if (s[x] > max_size_of_grp) {
		max_size_of_grp = s[x];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int a, b; cin >> a >> max_size_allowed;

	parent = new int[n];
	s = new int[n];
	cnt_of_dep = new int[n * 3];
	for (int i = 0; i < 3; i++) {
		cin >> dep_max[i];
	}

	string name_of_employee[n];
	unordered_map<string, int> id_of_employee;
	for (int i = 0; i < n; i++) {
		int dep;
		string name; cin >> name >> dep;
		name_of_employee[i] = name;
		id_of_employee[name] = i;

		parent[i] = i;
		s[i] = 1;
		cnt_of_dep[3 * i + 0] = 0;
		cnt_of_dep[3 * i + 1] = 0;
		cnt_of_dep[3 * i + 2] = 0;

		cnt_of_dep[3 * i + (dep - 1)] = 1;
	}

	for (int i = 0; i < m; i++) {
		string one, two; cin >> one >> two;
		union_sets(id_of_employee[two], id_of_employee[one]);
	}

	if (max_size_of_grp < a) {
		cout << "no groups";
		return 0;
	}

	vector<int> ans;
	int ind = 0;
	for (int i = 0; i < n; i++) {
		if (s[find_set(i)] == max_size_of_grp) {
			name_of_employee[ind++] = name_of_employee[i];
		}
	}

	sort(name_of_employee, name_of_employee + ind);
	for (int i = 0; i < ind; i++) {
		cout << name_of_employee[i] << "\n";
	}
	return 0;
}
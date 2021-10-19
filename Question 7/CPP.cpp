#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <cstring>
using namespace std;

struct pint {
	static int ind;
	int val = ind++;
};
int pint::ind = 0;

pint *parent;
int *s;

int find_set(int x) {
	if (parent[x].val == x) {
		return x;
	}
	return parent[x].val = find_set(parent[x].val);
}


void union_sets(int x, int y) {
	x = find_set(x);
	y = find_set(y);
	if (x == y) {
		return;
	}

	if (s[x] < s[y]) {
		x = x ^ y; y = x ^ y; x = x ^ y;
	}

	parent[y].val = x;
	s[x] += s[y];
}

int p[168] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n], m = -1, y = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m = max(m, a[i]);
	}
	parent = new pint[m + 1];
	s = new int[m + 1];
	memset(s, 1, sizeof(s));
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) continue;
		int x = a[i];
		for (int j = 0; p[j]*p[j] <= x; j++) {
			if (x % p[j] == 0) {
				union_sets(a[i], p[j]);
			}

			while (x % p[j] == 0) {
				x /= p[j];
			}
		}
		if (x != 1) {
			union_sets(a[i], x);
		}
	}

	memset(s, 0, sizeof(int) * (m + 1));
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			y += 1;
			continue;
		}

		int f = find_set(a[i]);
		if (!s[f]) {
			y++;
			s[f] = 1;
		}
	}

	if (y < 2) {
		cout << "NO\n0";
	}
	else {
		long long x = 2;
		int res = 1, mod = 1e9 + 7;
		while (y > 0) {
			if (y & 1) {
				res = (res * x) % mod;
			}

			y = y >> 1;
			x = (x * x) % mod;
		}
		cout << "YES\n" << res - 2;
	}
	return 0;
}
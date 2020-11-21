#include <iostream>
typedef long long LL;
LL n, a[100005], d[270000], b[270000];

using namespace std;

void build(LL s, LL t, LL p) {
	if (s == t) {
		d[p] = a[s];
		return;
	}
	LL m = (s + t) / 2;
	build(m + 1, t, p * 2 + 1);	build(s, m, p * 2);


	d[p] = d[p * 2] + d[p * 2 + 1];
}

void update(LL l, LL r, LL c, LL s, LL t, LL p) {
	if (l <= s && t <= r) {
		d[p] += (t - s + 1) * c;
		b[p] += c;
		return;
	}

	LL m = (s + t) / 2;
	if (b[p]) {
		d[p * 2] += b[p] * (m - s + 1);
		d[p * 2 + 1] += b[p] * (t - m);
		b[p * 2] += b[p];
		b[p * 2 + 1] += b[p];
	}
	b[p] = 0;
	if (l <= m) {
		update(l, r, c, s, m, p * 2);
	}
	if (r > m) {
		update(l, r, c, m + 1, t, p * 2 + 1);
	}
	d[p] = d[p * 2] + d[p * 2 + 1];
}

LL getsum(LL l, LL r, LL s, LL t, LL p) {
	if (l <= s && t <= r) {
		return d[p];
	}

	LL m = (s + t) / 2, sum = 0;

	if (b[p]) {
		d[p * 2] += b[p] * (m - s + 1);
		d[p * 2 + 1] += b[p] * (t - m);
		b[p * 2] += b[p];
		b[p * 2 + 1] += b[p];
	}
	b[p] = 0;

	if (l <= m) {
		sum += getsum(l, r, s, m, p * 2);
	}

	if (r > m) {
		sum += getsum(l, r, m + 1, t, p * 2 + 1);
	}
	return sum;
}

int main() {
	LL q, i1, i2, i3, i4;
	cin >> n >> q;
	for (LL i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, n, 1);
	while (q--) {
		cin >> i1 >> i2 >> i3;
		if (i1 == 2) {
			cout << getsum(i2, i3, 1, n, 1) << endl;
		}
		else {
			cin >> i4;
			update(i2, i3, i4, 1, n, 1);
		}
	}
	return 0;
}
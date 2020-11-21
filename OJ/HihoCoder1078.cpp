#include <iostream>
int n, a[100005], d[270000], b[270000];

using namespace std;

void build(int s, int t, int p) {
    if (s == t) {
        d[p] = a[s];
        return;
    }
    int m = (s + t) / 2;
    build(s, m, p * 2);
    build(m + 1, t, p * 2 + 1);

    d[p] = d[p * 2] + d[p * 2 + 1];
}

void update(int l, int r, int c, int s, int t, int p) {
    if (l <= s && t <= r) {
        d[p] = (t - s + 1) * c;
        b[p] = c;
        return;
    }

    int m = (s + t) / 2;
    if (b[p]) {
        d[p * 2] = b[p] * (m - s + 1);
        d[p * 2 + 1] = b[p] * (t - m);
        b[p * 2] = b[p];
        b[p * 2 + 1] = b[p];
        b[p] = 0;
    }
    if (l <= m) {
        update(l, r, c, s, m, p * 2);
    }
    if (r > m) {
        update(l, r, c, m + 1, t, p * 2 + 1);
    }
    d[p] = d[p * 2] + d[p * 2 + 1];
}

int getsum(int l, int r, int s, int t, int p) {
    if (l <= s && t <= r) {
        return d[p];
    }

    int m = (s + t) / 2, sum = 0;

    if (b[p]) {
        d[p * 2] = b[p] * (m - s + 1);
        d[p * 2 + 1] = b[p] * (t - m);
        b[p * 2] = b[p];
        b[p * 2 + 1] = b[p];
        b[p] = 0;
    }

    if (l <= m) {
        sum += getsum(l, r, s, m, p * 2);
    }

    if (r > m) {
        sum += getsum(l, r, m + 1, t, p * 2 + 1);
    }
    return sum;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, n, 1);

    int q, i1, i2, i3, i4;
    cin >> q;
    while (q--) {
        cin >> i1 >> i2 >> i3;
        if (i1 == 0) {
            cout << getsum(i2, i3, 1, n, 1) << endl;
        }
        else {
            cin >> i4;
            update(i2, i3, i4, 1, n, 1);
        }
    }
    return 0;
}

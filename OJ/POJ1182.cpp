#include <iostream>

using namespace std;

const int maxn = 160000;
int fa[maxn];

void init() {
    for (int i = 0; i < maxn; i++) {
        fa[i] = i;
    }
}
 
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unionSet(int x, int y) {
    x = find(x); 
    y = find(y);

    if (x == y)
        return;

    else {
        fa[x] = y; 
    }
}

int main() {
    init();
    int n, k;

    scanf("%d%d", &n, &k);
    int ans = 0;

    while (k--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        if (b > n || c > n || b < 1 || c < 1) {
            ans++;
            continue;
        }

        if (a == 1) {
            if (find(b + n) == find(c) || find(b + 2 * n) == find(c)) {
                ans++;
                continue;
            }

            unionSet(b, c);
            unionSet(b + n, c + n);
            unionSet(b + 2 * n, c + 2 * n);
        }

        else {
            if (b == c || find(b) == find(c) || find(b + 2 * n) == find(c)) {
                ans++;
                continue;
            }

            unionSet(b + n, c);
            unionSet(b + 2 * n, c + n);
            unionSet(b, c + 2 * n);
        }
    }

    printf("%d\n", ans);
} 
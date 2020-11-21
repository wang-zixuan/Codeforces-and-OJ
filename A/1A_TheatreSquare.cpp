#include <iostream>
using namespace std;

int main () {
	long long n, m, a;
	long long n_cnt, m_cnt;

	cin >> n >> m >> a;

	n_cnt = (n % a == 0 ? n / a : n / a + 1)
	m_cnt = (m % a == 0 ? m / a : m / a + 1)

	cout << n_cnt * m_cnt << endl;
}
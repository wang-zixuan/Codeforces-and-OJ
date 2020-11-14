#include <iostream>

using namespace std;
int main () {
	long long n, m, a;
	long long n_cnt, m_cnt;

	cin >> n >> m >> a;
	if (n % a == 0) {
		n_cnt = n / a;
	}
	else {
		n_cnt = n / a + 1;
	}

	if (m % a == 0) {
		m_cnt = m / a;
	}
	else {
		m_cnt = m / a + 1;
	}

	cout << n_cnt * m_cnt << endl;
}
#include <iostream>
#include <cstdlib>
using namespace std;
double find(double, double);
int main() {
	double n;
	cin >> n;
	double sq = find(n, n);
	cout << sq;
}
double find(double n, double x) {
	if (n * n >= x && n*n - x <= 0.001)
		return n;
	else if (n * n < x && x - n * n <= 0.001)
		return n;
	else {
		n = (n + x / n) / 2;
		return find(n, x);
	}
}